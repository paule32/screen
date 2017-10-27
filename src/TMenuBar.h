#ifndef TMENUBAR_H_
#define TMENUBAR_H_

#include <THeaders.h>

class TMenuBar: public TObject
{
public:
	explicit TMenuBar();
	~TMenuBar();

protected:
	virtual void draw();
}
#endif