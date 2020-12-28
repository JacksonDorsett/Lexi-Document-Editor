#pragma once
#include "type.h"

class Glyph {
public:
	//appearance
	virtual void Draw(Window * window ) = 0;
	virtual void Bounds(Rect & rect) = 0;
	virtual void setPosition(Point point) = 0;
	//hit detection
	virtual bool Intersects(const Point & p) = 0;
	//structure
	virtual void Insert(Glyph * glyph, int position) = 0;
	virtual void Remove(Glyph * glyph) = 0;
	virtual Glyph* Child(int cid) = 0;
	virtual Glyph* Parent() = 0;


};