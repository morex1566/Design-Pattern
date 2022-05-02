#include "Player.h"

//   public area is begin   //

Player::Player(const std::string shape, const int pos, const int moveSpeed)
	: GameObject(shape, pos), moveSpeed(moveSpeed)
{}

Player::~Player(){}

void Player::update()
{
	return;
}

//   public area is end   //