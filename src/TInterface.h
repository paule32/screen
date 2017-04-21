#ifndef TINTERFACE_H_
#define TINTERFACE_H_

#include <iostream>
#include <ctypes>
#include <vector>

#define Interface class
#define implements public
#define DeclareInterface(name) __interface actual_##name {

#define DeclareBasedInterface(name, base) __interface actual_##name \
     : public actual_##base {

#define EndInterface(name) };                \
     Interface name : public actual_##name { \
     public:                                 \
        virtual ~name() {}                   \
     };
     
std::vector<TString> Interface(20);

struct TGUID
{
    __int32 D1;
    __int16 D2;
    __int16 D3;
    union D4 {
        unsigned a : 1;
        unsigned b : 1;
        unsigned c : 1;
        unsigned d : 1;
        unsigned e : 1;
        unsigned f : 1;
        unsigned g : 1;
        unsigned h : 1;
    }
};

class TUnknown
{
public:
    virtual __int32 QueryInterface(TGUID const IID, void ** ppvObject) = 0;
    virtual __int32 AddRef() = 0;
    virtual __int32 Release() = 0;
};


#endif
