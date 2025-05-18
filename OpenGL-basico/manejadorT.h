#pragma once
#include "Texturas.h"
#include "cargadorT.h"

class manejadorT
{
	static manejadorT* instance;

	Texturas imagenMuestra, texturaSuelo, unoT, dosT, tresT, cuatroT, cincoT, seisT, sieteT , ochoT , nueveT, ceroT;
	explicit  manejadorT() : imagenMuestra(cargadorT::cargarTextura("../canon.png")), 
							 texturaSuelo(cargadorT::cargarTextura("../Texturas/tierra.jpg"))
		, unoT(cargadorT::cargarTextura("../Texturas/uno.png")), dosT(cargadorT::cargarTextura("../Texturas/dos.png")), tresT(cargadorT::cargarTextura("../Texturas/tres.png")), 
		cuatroT(cargadorT::cargarTextura("../Texturas/cuatro.png")), cincoT(cargadorT::cargarTextura("../Texturas/cinco.png")),
		seisT(cargadorT::cargarTextura("../Texturas/seis.png")), sieteT(cargadorT::cargarTextura("../Texturas/siete.png")), ochoT(cargadorT::cargarTextura("../Texturas/ocho.png")),
		nueveT(cargadorT::cargarTextura("../Texturas/nueve.png")), ceroT(cargadorT::cargarTextura("../Texturas/cero.png"))
	{
	}
public:

	static void init();
	static Texturas imagenM();
	static Texturas texturaS();
	static Texturas uno();
	static Texturas dos();
	static Texturas tres();
	static Texturas cuatro();
	static Texturas cinco();
	static Texturas seis();
	static Texturas siete();
	static Texturas ocho();
	static Texturas nueve();
	static Texturas cero();

};

