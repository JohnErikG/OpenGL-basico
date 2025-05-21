#pragma once  
#include "boton1.hpp"  
#include "Settings.h"  
#include "menuDeSettings.h"  
#include "Utils/vector3.h"  
#include "rectangulo.h"  

class renderMenu  
{  
public:  
    static void dibujarRecR(const rectangulo& rec);  
    static void dibujarvec3(const vector3& vec);  
    static void dibujarBotonT(const boton1* bot);  
    static void dibujarBotonF(const boton1* bot);  
    static void dibujarGH();  
    static void dibujarInicio();  
    static void dibujarsettings(menuDeSettings* Mset);  
    static void dibujarBoton(const boton1* bot);  
};
