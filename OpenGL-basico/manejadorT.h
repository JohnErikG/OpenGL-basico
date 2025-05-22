#pragma once
#include "Texturas.h"
#include "cargadorT.h"

class manejadorT
{
	static manejadorT* instance;

	Texturas imagenMuestra, texturaSuelo, texturaManzana, texturaPlayer;
	explicit  manejadorT() : imagenMuestra(cargadorT::cargarTextura("../Texturas/metal.jpg")), 
							 texturaSuelo(cargadorT::cargarTextura("../Texturas/tierra.jpg")),
							 texturaManzana(cargadorT::cargarTextura("../Texturas/Apple_BaseColor.png")),
							 texturaPlayer(cargadorT::cargarTextura("../Texturas/player.jpg"))
	{
	}
public:

	static void init();
	static Texturas imagenM();
	static Texturas texturaS();
	static Texturas texturaM();
	static Texturas texturaP();
};

