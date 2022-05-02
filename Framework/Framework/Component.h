#pragma once
#include <string>

class Component abstract
{
private:
	friend class GameObject;

protected:
	std::string name;

public:
	virtual void update() = 0;
};