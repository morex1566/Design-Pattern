#pragma once
#include "Component.h"

class Transform : public Component
{
private:
	int pos;

public:
	Transform(int);
	~Transform();

	void update() override;
	int getPos();
	void setPos(const int);
};

