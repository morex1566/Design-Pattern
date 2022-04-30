#include <conio.h>
#include <iostream>
#include "Player.h"


//   public area is begin   //

Standing PlayerState::standing;
Jumping PlayerState::jumping;
Running PlayerState::running;

Player::Player()
{
	state = &PlayerState::standing;
	moveSpeed = 1.0f;
	jumpPower = 10.0f;
}

Player::~Player(){}

void Player::update()
{
	state->update(*this);
}

void Player::handleInput()
{
	PlayerState* temp = state->handleInput(*this);
	if (temp != nullptr)
	{
		state->exit(*this);
		state = temp;
		state->enter(*this);
	}
	return;
}

void Player::setGraphics(std::string shape)
{
	this->shape = shape;
	return;
}

Standing::Standing() {}

Standing::~Standing() {}

PlayerState* Standing::handleInput(Player& player)
{
	int key = _getch();
	if (key == 72)
	{
		return &PlayerState::jumping;
	}
	
	if (key == 77 || key == 75)
	{
		return &PlayerState::running;
	}

	return nullptr;
}

void Standing::enter(Player& player)
{
	std::cout << "standing enter" << std::endl;
	return;
}

void Standing::update(Player& player)
{
	
}

void Standing::exit(Player& player)
{
	std::cout << "standing exit" << std::endl;
	return;
}


Jumping::Jumping()
{
	time = 0;
}

Jumping::~Jumping() {}

PlayerState* Jumping::handleInput(Player& player)
{
	int key = _getch();
	if (key == 80 || time > 100000)
	{
		return &PlayerState::standing;
	}

	return nullptr;
}

void Jumping::enter(Player& player)
{
	std::cout << "jumping enter" << std::endl;
	return;
}

void Jumping::update(Player& player)
{
	time++;
	return;
}

void Jumping::exit(Player& player)
{
	std::cout << "jumping exit" << std::endl;
	return;
}


Running::Running() {}

Running::~Running() {}

PlayerState* Running::handleInput(Player& player)
{
	int key = _getch();
	if (key == 72)
	{
		return &PlayerState::jumping;
	}

	if (key == 80)
	{
		return &PlayerState::standing;
	}

	return nullptr;
}

void Running::enter(Player& player)
{
	std::cout << "running enter" << std::endl;
	return;
}

void Running::update(Player&)
{

}

void Running::exit(Player& player)
{
	std::cout << "running exit" << std::endl;
	return;
}

//   public area is end   //