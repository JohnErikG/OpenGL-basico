#include "manejadorL.h"
manejadorL* manejadorL::instanceL = nullptr; 
void manejadorL::init()
{
		instanceL = new manejadorL();

}

luces manejadorL::luz1M()
{
	return instanceL->luz1;
}

luces manejadorL::luz2M()
{
	return instanceL->luz2;
}



