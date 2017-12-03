#ifndef TDESKTOP_H_
#define TDESKTOP_H_

namespace ros {
class TDeskTop: public TObject
{
protected:
    virtual void draw();
    
public:
    explicit TDeskTop(TVideo *_video);
    ~TDeskTop();
    
    TVideo *video;
};
} // namespace ros
#endif
