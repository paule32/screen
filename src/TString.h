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

    class TString & operator =  (class TString &rhs);
    bool            operator == (class TString &rhs);
    
    bool isEmpty();
    
protected:
    std::string value;
};

#endif
