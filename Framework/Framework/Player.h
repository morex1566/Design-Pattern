#pragma once
#include <string>
#include <memory>
#include <queue>

// forward declare
class PlayerState;
class Standing;
class Jumping;
class Running;


class Player
{
private:
	PlayerState* state; // FSM
	std::string shape;
	float moveSpeed;
	float jumpPower;

public:
	Player();
	~Player();

	void update();
	void handleInput();
	void setGraphics(std::string); // assume that program has Renderer class.
};


class PlayerState abstract
{
public:
	// Q: is that no problem static field in abstract class?
	// A: yes, static field do not work instance of the class itself.
	static Standing standing;
	static Jumping jumping;
	static Running running;

	virtual PlayerState* handleInput(Player&) = 0;
	virtual void enter(Player&) = 0;
	virtual void update(Player&) = 0;
	virtual void exit(Player&) = 0;
};


class Standing : public PlayerState
{
public:
	Standing();
	~Standing();

	PlayerState* handleInput(Player&) override;
	void enter(Player&) override;
	void update(Player&) override;
	void exit(Player&) override;
};


class Jumping : public PlayerState
{
private:
	int time;

public:
	Jumping();
	~Jumping();

	PlayerState* handleInput(Player&) override;
	void enter(Player&) override;
	void update(Player&) override;
	void exit(Player&) override;
};


class Running : public PlayerState
{
public:
	Running();
	~Running();

	PlayerState* handleInput(Player&) override;
	void enter(Player&) override;
	void update(Player&) override;
	void exit(Player&) override;
};