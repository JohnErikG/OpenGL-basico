#pragma once
#include "boton1.hpp"
#include "Texturas.h"
#include <array>
#include "manejadorT.h"
class menuDeSettings
{
	static menuDeSettings* instance;
	boton1 v1;
	boton1 v2;
	boton1 v3;
	boton1 l1;
	boton1 l2;
	boton1 l3;
	boton1 ware;
	boton1 TexOn;
	boton1 facetado;
	Texturas fondo = manejadorT::texturaS();

public:
	explicit menuDeSettings(const int width,const  int height);
	std::array<boton1*, 9 > getBotones() ;
	void click(int x, int y);
	GLuint getTextureId() const;
	static menuDeSettings* initMs();
};

