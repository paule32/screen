#ifndef TSTRING_H_
#define TSTRING_H_

class TString
{
    friend std::ostream& operator << (std::ostream &out, class TString obj);
    friend std::istream& operator >> (std::istream &out, class TString obj);
    
    friend std::ostream& operator << (std::ostream &out, class TString &obj);
    friend std::istream& operator >> (std::istream &out, class TString &obj);
public:
    explicit TString(char*);
    explicit TString(void);

    class TString & operator = (class TString &rhs) {
        value = rhs.value;
    }
    class TString & operator == (class TString rhs) {
        if (value == rhs.value)
        isOk = true; else
        isOk = false;
    }
    
    bool isEmpty();
    bool isOk;
    
    std::string ClassName;
    std::string value;
};

#endif
