#include "menuDeSettings.h"
#include "boton1.hpp"
#include "vector2.h"
#include "manejadorT.h"
menuDeSettings* menuDeSettings::instance = nullptr;
menuDeSettings::menuDeSettings(const int width, const int height)
{
	float coordX = 200;
	float coordY = 150;

	v1 = boton1(vector2(250, 200), vector2(coordX, coordY));
	/*v2 = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));
	v3 = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));
	l1 = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));
	l2 = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));
	l3 = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));
	ware = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));
	TexOn = boton1(vector2(coordX, coordY), vector2(0.5f, 0.5f));*/
}

std::array<boton1*, 8> menuDeSettings::getBotones() 
{
	return {&v1, &v2 , &v3 , &l1 , &l2 , &l3 , &ware,&TexOn };
}

void menuDeSettings::click(int x, int y)
{
}

GLuint menuDeSettings::getTextureId() const
{
	return GLuint();
}

menuDeSettings* menuDeSettings::initMs()
{
	if (instance == nullptr) {
		instance = new menuDeSettings(600, 360);
	}
	return instance;
}
