#include "manejadorT.h"

manejadorT* manejadorT::instance = nullptr;
void manejadorT::init()
{
		instance = new manejadorT();
}

Texturas manejadorT::imagenM()
{
	return	instance->imagenMuestra;

}
