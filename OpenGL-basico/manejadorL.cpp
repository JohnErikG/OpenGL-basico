#include "manejadorL.h"
manejadorL* manejadorL::instanceL = nullptr; // Inicialización del puntero estático
void manejadorL::init()
{
		instanceL = new manejadorL();

}

luces manejadorL::luz1M()
{
	return instanceL->luz1;
}



