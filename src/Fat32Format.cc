#include <types.hpp>
#include <new.hpp>
#include <pc.h>

class BootSector {
public:
    uint32_t jmp1;
    uint32_t jmp2;
    uint32_t jmp3;
    uint32_t jmp4;
};

class FileTableDescriptor {
public:
    uint32_t   file_pos;
    uint8_t    file_type;
    uint16_t   file_name_size;
    char     * file_name;
    class FileTableDescriptor * next;
};

class BootTable {
public:
    uint8_t  type;
    char     volume_name[20];
    class   FileTableDescriptor **ft_desc;
};

class BootFS {
public:
    class BootSector   boot_sector;
    class BootTable  * boot_table;
};

extern "C" void ata_lba_write(unsigned int, unsigned int, void*);
class BootTable *boot_table = new BootTable;
void format_volume(void)
{
    boot_table->ft_desc[0] = new FileTableDescriptor;
    boot_table->ft_desc[1] = new FileTableDescriptor;
    boot_table->ft_desc[2] = new FileTableDescriptor;

    boot_table->ft_desc[0]->file_name_size = 12;
    boot_table->ft_desc[1]->file_name_size = 11;
    boot_table->ft_desc[2]->file_name_size = 11;

    boot_table->ft_desc[0]->file_name = (char*)"LiesMich.txt";
    boot_table->ft_desc[1]->file_name = (char*)"ReadMe.text";
    boot_table->ft_desc[2]->file_name = (char*)"Command.com";

    boot_table->ft_desc[0]->file_type = 0x01;       // 1=normal file
    boot_table->ft_desc[1]->file_type = 0x02;       // 1=normal file
    boot_table->ft_desc[2]->file_type = 0x03;       // 1=normal file

    boot_table->ft_desc[0]->file_pos  = 0xb00b;
    boot_table->ft_desc[1]->file_pos  = 0xb11b;
    boot_table->ft_desc[2]->file_pos  = 0xb22b;

    boot_table->type = 0x01;  // 1=hard disc

    __asm__("movl %eax, 0         \n"
            "movb %cl, 2          \n"
            "movl _boot_table, %edi \n"
            "call _ata_lba_write   \n"
    );
    //ata_lba_write(1,2,&boot_table);
}

