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
