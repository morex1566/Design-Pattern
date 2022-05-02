#pragma once
#include "Component.h"
#include "Transform.h"

class Renderer : public Component
{
private:
	Transform* transform;
	std::string shape;

public:
	Renderer(Transform* ,std::string);
	~Renderer();

	void update() override;
	void setShape(const std::string);
};

