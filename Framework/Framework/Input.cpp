#include "Input.h"

bool Input::key[256];

//   public area is begin   //
Input::Input()
{
	for (int index = 0; index < 256; index++)
	{
		key[index] = false;
	}
}

Input::~Input(){}

void Input::keyDown(unsigned int input)
{
	key[input] = true;
	return;
}

void Input::keyUp(unsigned int input)
{
	key[input] = false;
	return;
}

bool Input::isKeyDown(unsigned int input)
{
	return key[input];
}
//   public area is end   //