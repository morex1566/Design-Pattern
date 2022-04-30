#include <conio.h>

#include "System.h"

//   public area is begin   //

System::System()
{
	player = new Player();
	if (!player)
	{

	}
}

System::~System(){}

void System::initialize()
{

}

void System::run()
{
	bool looping = true;
	while (looping)
	{
		if (_kbhit)
		{
			player->handleInput();
		}

		player->update();
	}
}

void System::shutdown()
{

}


 //   public area is end   //