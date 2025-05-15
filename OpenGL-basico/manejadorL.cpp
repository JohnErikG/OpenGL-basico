#include "manejadorL.h"

void manejadorL::init()
{
	if (instance == nullptr) {
		instance = new manejadorL();
	}
	else {
		std::cerr << "Error: Instancia de manejadorL ya existe." << std::endl;
	}
}

luces manejadorL::luz1M()
{
	return instance->luz1;
}



