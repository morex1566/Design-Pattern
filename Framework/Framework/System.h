#pragma once
#include <Windows.h>
#include <memory>

#include "Player.h"
#include "Input.h"

class System
{
private:
	Player* player;

public:
	System();
	~System();

	void initialize();
	void run();
	void shutdown();

};

