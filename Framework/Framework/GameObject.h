/*
	This class has utility methods and basic fields of all classes that inherit from this class. 
*/

#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"
#include "Renderer.h"

class GameObject
{
private:
	friend class Component;
	std::vector<Component*> components;

protected:
	virtual void update() = 0;

public:
	GameObject(std::string, int);
	~GameObject();

	void setPosition(const int);
	void setShape(const std::string);
	template <typename T>
	void addComponent(const T&);
	void removeComponent(std::string);
	void innerUpdate();

};

