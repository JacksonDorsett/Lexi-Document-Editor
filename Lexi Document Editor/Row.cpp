#include "Row.h"
Row::Row(const Point p) {
	this->mPos = p;
}

void Row::Draw(Window * window)
{
	Point drawPos = this->mPos;
	Rect curBounds;
	for (int i = 0; i < this->mChildren.size(); i++) {
		Glyph * gp = this->Child(i);
		gp->setPosition(drawPos);
		gp->Draw(window);
		gp->Bounds(curBounds);
		drawPos.x += curBounds.width;
		
	}
}

void Row::Bounds(Rect & rect)
{
	int x = 0, y = 0;
	Rect curBounds;
	for (int i = 0; i < this->mChildren.size(); ++i) {
		this->mChildren[i]->Bounds(curBounds);
		if (curBounds.height > y) y = curBounds.height;
		x += curBounds.width;
	}
	rect = Rect(mPos, sf::Vector2f(x, y));
}

void Row::setPosition(Point point)
{
	mPos = point;

}

bool Row::Intersects(const Point & p)
{
	Rect r(0,0,0,0);
	Bounds(r);
	return r.contains(p);
}

void Row::Insert(Glyph * glyph, int position)
{
	this->mChildren.insert(mChildren.begin() + position, glyph);
}

void Row::Remove(Glyph * glyph)
{
	//find child
	auto i = this->mChildren.begin();
	for (i = this->mChildren.begin(); *i != glyph && i != this->mChildren.end(); i++);
	this->mChildren.erase(i, i);

}

Glyph * Row::Child(int cid)
{
	if(cid < 0 || cid >= this->mChildren.size()){
		return nullptr;
	}
	return mChildren[cid];
	
}

Glyph * Row::Parent()
{
	return nullptr;
}
