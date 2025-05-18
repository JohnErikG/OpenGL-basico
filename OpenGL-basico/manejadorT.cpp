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

Texturas manejadorT::uno()
{
	return instance->unoT;
}

Texturas manejadorT::dos()
{
	return instance->dosT;
}
Texturas manejadorT::tres()
{
	return instance->tresT;
}
Texturas manejadorT::cuatro()
{
	return instance->cuatroT;
}
Texturas manejadorT::cinco()
{
	return instance->cincoT;
}
Texturas manejadorT::seis()
{
	return instance->seisT;
}
Texturas manejadorT::siete()
{
	return instance->sieteT;
}
Texturas manejadorT::ocho()
{
	return instance->ochoT;
}
Texturas manejadorT::nueve()
{
	return instance->nueveT;
}
Texturas manejadorT::cero()
{
	return instance->ceroT;
}