#include "Frame.h" 
void  Point::copyto(Point &p)
{
	p.name=name;
	p.x=x;
	p.y=y;
}
void Frame::Copyto(Frame &fr)
{
	fr.setname(this->name);
	fr.setorigin(this->origin);
	fr.setVector_X(this->vector_X);
	fr.setVector_Y(this->vector_Y);
}
