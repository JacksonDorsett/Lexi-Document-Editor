#include "Column.h"

void Column::Draw(Window * window)
{
	Point drawPos = this->mPos;
	Rect curBounds;
	for (int i = 0; i < this->mChildren.size(); i++) {
		Glyph * gp = this->Child(i);
		gp->setPosition(drawPos);
		gp->Draw(window);
		gp->Bounds(curBounds);
		drawPos.y += curBounds.height;

	}
}

void Column::Bounds(Rect & rect)
{
	int x = 0, y = 0;
	Rect curBounds;
	for (int i = 0; i < this->mChildren.size(); ++i) {
		this->mChildren[i]->Bounds(curBounds);
		if (curBounds.width > x) x = curBounds.width;
		y += curBounds.height;
	}
	rect = Rect(mPos, sf::Vector2f(x, y));
}

void Column::setPosition(Point point)
{
	mPos = point;
}

bool Column::Intersects(const Point & p)
{
	Rect r(0, 0, 0, 0);
	Bounds(r);
	return r.contains(p);
}

void Column::Insert(Glyph * glyph, int position)
{
	this->mChildren.insert(mChildren.begin() + position, glyph);
}

void Column::Remove(Glyph * glyph)
{
	//find child
	auto i = this->mChildren.begin();
	for (i = this->mChildren.begin(); *i != glyph && i != this->mChildren.end(); i++);
	this->mChildren.erase(i, i);
}

Glyph * Column::Child(int cid)
{
	if (cid < 0 || cid >= this->mChildren.size()) {
		return nullptr;
	}
	return mChildren[cid];
}

Glyph * Column::Parent()
{
	return nullptr;
}
