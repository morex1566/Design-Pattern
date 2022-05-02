#pragma once
#include "GameObject.h"
#include "Player.h"

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

