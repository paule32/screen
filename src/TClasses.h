#ifndef TCLASSES_H_
#define TCLASSES_H_

class TClass {
public:
    explicit TClass();
    
    bool RegisterClass(std::type_info *t, char* _name);
    bool RegisterClass(std::type_info *t);
    
private:
    char* ClassName;
};

#endif
