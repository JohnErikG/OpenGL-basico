#include "menuDeSettings.h"
#include "boton1.hpp"
#include "vector2.h"
#include "manejadorT.h"
menuDeSettings* menuDeSettings::instance = nullptr;
menuDeSettings::menuDeSettings(const int width, const int height)
{
	float coordX = -90;
	float coordY = 100;

	v1 = boton1(vector2(-50, 140), vector2(coordX, coordY));
	//v2 = boton1( vector2(130, 200), vector2(coordX-20, coordY));
	//v3 = boton1( vector2(0.5f, 0.5f), vector2(coordX, coordY));
	//l1 = boton1( vector2(0.5f, 0.5f),vector2(coordX, coordY));
	//l2 = boton1( vector2(0.5f, 0.5f), vector2(coordX, coordY));
	//l3 = boton1(vector2(0.5f, 0.5f), vector2(coordX, coordY));
	//ware = boton1( vector2(0.5f, 0.5f), vector2(coordX, coordY));
	//TexOn = boton1(vector2(0.5f, 0.5f), vector2(coordX, coordY));
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
