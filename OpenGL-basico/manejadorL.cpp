#include "manejadorL.h"
manejadorL* manejadorL::instanceL = nullptr; // Inicializaci�n del puntero est�tico
void manejadorL::init()
{
		instanceL = new manejadorL();

}

luces manejadorL::luz1M()
{
	return instanceL->luz1;
}



