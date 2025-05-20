#pragma once
#include "boton1.hpp"
#include "Settings.h"
#include "menuDeSettings.h"
class renderMenu
{
public:
	static void dibujarBotonT(const boton1* bot);
	static void dibujarBotonF(const boton1* bot);
	static void dibujarGH();
	static void dibujarInicio();
	static void dibujarsettings(menuDeSettings* Mset);

};

