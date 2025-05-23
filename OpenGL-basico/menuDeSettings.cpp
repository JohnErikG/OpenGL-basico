#include "menuDeSettings.h"
#include "boton1.hpp"
#include "vector2_2.h"
#include "manejadorT.h"
menuDeSettings* menuDeSettings::instance = nullptr;
menuDeSettings::menuDeSettings(const int width, const int height)
{
	float coordX = -90;
	float coordY = 100;

	v1 = boton1(vector2_2(-50, 140), vector2_2(coordX, coordY));
	l1 = boton1( vector2_2(-50, 65), vector2_2(coordX, coordY-75));
	v2 = boton1( vector2_2(150, 140), vector2_2(coordX + 200, coordY));
	v2.set_click(true);
	l2 = boton1( vector2_2(150, 65),vector2_2(coordX+200, coordY-75));
	l2.set_click(true);
	v3 = boton1( vector2_2(335, 140), vector2_2(coordX+385, coordY));
	l3 = boton1(vector2_2(335, 65), vector2_2(coordX+385, coordY-75));
	TexOn = boton1(vector2_2(-160, -15), vector2_2(coordX-110, coordY-155));
	TexOn.set_click(true);
	ware = boton1(vector2_2(-160, -90), vector2_2(coordX - 110, coordY - 230));
	facetado = boton1(vector2_2(-160, -170), vector2_2(coordX - 110, coordY - 310));
}

std::array<boton1*, 9> menuDeSettings::getBotones() 
{
	return {&v1, &v2 , &v3 , &l1 , &l2 , &l3 ,&TexOn , & ware,&facetado };
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

void menuDeSettings::setMenuActivo(bool activo)
{
	menuActivo = activo;
}

bool menuDeSettings::getMenuActivo() const
{
	return this->menuActivo;
}
