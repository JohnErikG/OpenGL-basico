#pragma once
#include "Texturas.h"
#include "cargadorT.h"

class manejadorT
{
	static manejadorT* instance;

	Texturas imagenMuestra;
	explicit  manejadorT() : imagenMuestra(cargadorT::cargarTextura ("../canon.png"))
	{
	}
public:

	static void init();
	static Texturas imagenM();
};

