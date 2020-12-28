#pragma once
#include "Glyph.h"

class Character : public Glyph {
public:
	Character(char c, Font * font, int size = 30);
	virtual void Draw(Window * window) override;
	virtual bool Intersects(const Point & p) override;
	void setFont(Font *font);
	virtual void setPosition(Point point);

	virtual void Bounds(Rect & rect) override;
private:
	char c;
	Text txt;
	Font * font;
	// Inherited via Glyph
	

	virtual void Insert(Glyph * glyph, int position) override;

	virtual void Remove(Glyph * glyph) override;

	virtual Glyph * Child(int cid) override;

	virtual Glyph * Parent() override;

};