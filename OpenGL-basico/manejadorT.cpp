#include "manejadorT.h"

manejadorT* manejadorT::instance = nullptr;
void manejadorT::init()
{
	if (instance != nullptr) {
		return;
	}
	instance = new manejadorT();
}

Texturas manejadorT::imagenM()
{
	return	instance->imagenMuestra;

}

Texturas manejadorT::texturaS()
{
	return instance->texturaSuelo;
}

Texturas manejadorT::botont()
{
	return instance->botonT;
}

Texturas manejadorT::botonf()
{
	return instance->botonF;
}

Texturas manejadorT::fondo()
{
	return instance->texturaFondo;
}

const Texturas manejadorT::uno()
{
	return instance->unoT;
}

const Texturas manejadorT::dos()
{
	return instance->dosT;
}
const Texturas manejadorT::tres()
{
	return instance->tresT;
}
const Texturas manejadorT::cuatro()
{
	return instance->cuatroT;
}
const Texturas manejadorT::cinco()
{
	return instance->cincoT;
}
const Texturas manejadorT::seis()
{
	return instance->seisT;
}
const Texturas manejadorT::siete()
{
	return instance->sieteT;
}
const Texturas manejadorT::ocho()
{
	return instance->ochoT;
}
const Texturas manejadorT::nueve()
{
	return instance->nueveT;
}
const Texturas manejadorT::cero()
{
	return instance->ceroT;
}

Texturas manejadorT::Settings()
{
	return instance->TextSettings;
}
