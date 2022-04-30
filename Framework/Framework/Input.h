#pragma once
class Input
{
private:
	static bool key[256];

public:
	Input();
	~Input();

	static void keyDown(unsigned int);
	static void keyUp(unsigned int);
	static bool isKeyDown(unsigned int);
};

