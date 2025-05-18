#pragma once
#include "Texturas.h"
#include "cargadorT.h"

class manejadorT
{
	static manejadorT* instance;

	Texturas imagenMuestra, texturaSuelo;
	explicit  manejadorT() : imagenMuestra(cargadorT::cargarTextura("../canon.png")), 
							 texturaSuelo(cargadorT::cargarTextura("../Texturas/tierra.jpg"))
	{
	}
public:

	static void init();
	static Texturas imagenM();
	static Texturas texturaS();
};

