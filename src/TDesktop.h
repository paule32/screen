#ifndef TDESKTOP_H_
#define TDESKTOP_H_

class TDesktop: public TObject
{
    friend std::ostream& operator << (std::ostream &out, class TDesktop &obj);
    friend std::istream& operator >> (std::istream &out, class TDesktop &obj);
    
public:
    explicit TDesktop();
    ~TDesktop();
};
#endif
