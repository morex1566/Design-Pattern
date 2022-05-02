#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	int moveSpeed;

public:
	Player(const std::string, const int, const int);
	~Player();

	void update() override;
};

