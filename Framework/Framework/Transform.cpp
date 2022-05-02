#include "Transform.h"

//   public area is begin   //

Transform::Transform(int pos)
	: pos(pos)
{
	name = "Transform";
}

Transform::~Transform(){}

void Transform::update()
{
	return;
}

int Transform::getPos() { return pos; }

void Transform::setPos(const int pos)
{
	this->pos = pos;

	return;
}

//   public area is end   //