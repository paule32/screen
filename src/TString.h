#ifndef TSTRING_H_
#define TSTRING_H_

#ifndef TOBJECT_H_
#include "TObject.h"
#endif

class TString: public TObject
{
    friend std::ostream& operator << (std::ostream &out, TString obj);
    friend std::istream& operator >> (std::istream &out, TString obj);
    
    friend std::ostream& operator << (std::ostream &out, TString &obj);
    friend std::istream& operator >> (std::istream &out, TString &obj);
public:
    explicit TString(char*);
    explicit TString(void);

    TString & operator =  (TString &rhs);
    bool      operator == (TString &rhs);
    
    bool isEmpty();
    
protected:
    std::string value;
};

#endif
