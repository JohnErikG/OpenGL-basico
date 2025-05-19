#pragma once
#include "boton.hpp"
#include "Texturas.h"
#include <array>
class menuDeSettings
{

	Boton v1;
	Boton v2;
	Boton v3;
	Boton l1;
	Boton l2;
	Boton l3;
	Boton ware;
	Boton TexOn;
	Texturas fondo;

public:
	explicit menuDeSettings(const int width,const  int height);
	std::array<Boton*, 7> getBotones() const;
	void click(int x, int y);
	GLuint getTextureId() const;
};

