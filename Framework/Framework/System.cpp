#include "System.h"

//   public area is begin   //

System::System() {
	player = new Player("(^ ^)-", 2, 1); // shape, pos, speed
}

System::~System() {

}

void System::initialize() {

}

void System::run() {
	player->innerUpdate();
}

void System::shutdown() {
	delete player;
}

 //   public area is end   //