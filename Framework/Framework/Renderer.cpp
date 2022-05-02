#include "Renderer.h"
#include <iostream>
#include <Windows.h>

void gotoxy(int x, int y) {
	COORD pos = { x,y }; //x, y ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� ����
}


//   public area is begin   //

Renderer::Renderer(Transform* transform, std::string shape)
	: transform(transform), shape(shape)
{
	name = "Renderer";
}

Renderer::~Renderer(){}

void Renderer::update()
{
	gotoxy(transform->getPos(), 0);
	std::cout << shape << std::endl;
	return;
}

void Renderer::setShape(const std::string shape)
{
	this->shape = shape;

	return;
}
//   public area is end   //