#ifndef TSTRING_H_
#define TSTRING_H_

class TObject;
#include <TObject.h>

class TString: public TObject
{
    friend std::ostream& operator << (std::ostream &out, class TString obj);
    friend std::istream& operator >> (std::istream &out, class TString obj);
    
    friend std::ostream& operator << (std::ostream &out, class TString &obj);
    friend std::istream& operator >> (std::istream &out, class TString &obj);
public:
    explicit TString(char*);
    explicit TString(void);

    
    bool isEmpty();
    
protected:
    std::string value;
};

#endif
