#pragma once
#include "Texturas.h"
#include "cargadorT.h"

class manejadorT
{
	static manejadorT* instance;
	Texturas botonT, botonF;
	Texturas imagenMuestra, texturaSuelo;
	Texturas texturaFondo, TextSettings;
	const Texturas unoT, dosT, tresT, cuatroT, cincoT, seisT, sieteT, ochoT, nueveT, ceroT;
	explicit  manejadorT() : imagenMuestra(cargadorT::cargarTextura("../canon.png")), 
							 texturaSuelo(cargadorT::cargarTextura("../Texturas/tierra.jpg"))
		, unoT(cargadorT::cargarTextura("../Texturas/uno.png")), dosT(cargadorT::cargarTextura("../Texturas/dos.png")), tresT(cargadorT::cargarTextura("../Texturas/tres.png")), 
		cuatroT(cargadorT::cargarTextura("../Texturas/cuatro.png")), cincoT(cargadorT::cargarTextura("../Texturas/cinco.png")),
		seisT(cargadorT::cargarTextura("../Texturas/seis.png")), sieteT(cargadorT::cargarTextura("../Texturas/siete.png")), ochoT(cargadorT::cargarTextura("../Texturas/ocho.png")),
		nueveT(cargadorT::cargarTextura("../Texturas/nueve.png")), ceroT(cargadorT::cargarTextura("../Texturas/cero.png")),
		botonT(cargadorT::cargarTextura("../Texturas/botonTick.jpg")), botonF(cargadorT::cargarTextura("../Texturas/botonX.jpg")),
		texturaFondo(cargadorT::cargarTextura("../Texturas/fondo.png")), TextSettings(cargadorT::cargarTextura("../Texturas/Settings.png"))
	{
	}
public:

	static void init();
	static Texturas imagenM();
	static Texturas texturaS();
	static Texturas botont();
	static Texturas botonf();
	static Texturas fondo();
	static Texturas Settings();
	const static Texturas uno();
	const static Texturas dos();
	const static Texturas tres();
	const static Texturas cuatro();
	const static Texturas cinco();
	const static Texturas seis();
	const static Texturas siete();
	const static Texturas ocho();
	const static Texturas nueve();
	const static Texturas cero();
	

};

