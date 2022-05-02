#include "GameObject.h"

//  public area is begin   //

GameObject::GameObject(std::string shape, int pos)
{
	Transform* transform = new Transform(pos);
	Renderer* renderer = new Renderer(transform, shape);
	components.push_back(transform);
	components.push_back(renderer);
}

GameObject::~GameObject()
{
	// caution!, delete error crtlsvaliderror
	for (auto& component : components) { delete component; }
	components.clear();
	std::vector<Component*>().swap(components);
}

void GameObject::setPosition(const int pos)
{
	// caution!!, component[0] is always transform.
	static_cast<Transform*>(components[0])->setPos(pos);
	return;
}

void GameObject::setShape(const std::string shape)
{
	// caution!!, component[1] is always renderer.
	static_cast<Renderer*>(components[1])->setShape(shape);
	return;
}

template<typename T>
void GameObject::addComponent(const T& component)
{
	components.push_back(component);

	return;
}

void GameObject::removeComponent(std::string name)
{
	int index = 0;
	for (auto it = components.begin(); it == components.end(); it++)
	{
		if (components[index]->name == name)
		{
			components.erase(it);
			return;
		}
		index++;
	}

	return;
}

void GameObject::innerUpdate()
{
	for (auto& component : components) { component->update(); }
	update();  // overrided update.
	
	return;
}

//   public area is end   //