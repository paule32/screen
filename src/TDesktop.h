#ifndef TDESKTOP_H_
#define TDESKTOP_H_

class TDeskTop: public TObject
{
protected:
    virtual void draw();
    
public:
    explicit TDeskTop();
    ~TDeskTop();
};
#endif
