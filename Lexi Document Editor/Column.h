#pragma once
#include "Glyph.h"
class Column :
	public Glyph
{
public:
	// Inherited via Glyph
	virtual void Draw(Window * window) override;
	virtual void Bounds(Rect & rect) override;
	virtual void setPosition(Point point) override;
	virtual bool Intersects(const Point & p) override;
	virtual void Insert(Glyph * glyph, int position) override;
	virtual void Remove(Glyph * glyph) override;
	virtual Glyph * Child(int cid) override;
	virtual Glyph * Parent() override;
private:
	Point mPos;
	std::vector<Glyph *> mChildren;
};

