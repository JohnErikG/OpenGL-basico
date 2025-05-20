#include "boton1.hpp"
#include "manejadorT.h"
#include "settings.h"
bool boton1::is_inside(int x, int y) const
{
	// Check if the point (x, y) is inside the button's area    
	const float xf = static_cast<float>(x-640);
	const float yf = static_cast<float>(y - 360);
	const float horizontal = xf <= Ader.getx() && xf >= BIzq.getx();
	const float vertical = yf >= BIzq.gety() && yf <= Ader.gety();
    return horizontal && vertical ;
}

float boton1::getDerAx() const
{
    return Ader.getx();
}

float boton1::getDerAy() const
{
	return Ader.gety();
}

float boton1::getIzqAx() const
{
    return BIzq.getx();
}

float boton1::getIzqAy() const
{
	return Ader.gety();
}

float boton1::getDerBx() const
{
	return Ader.getx();
}

float boton1::getDerBy() const
{
    return BIzq.gety();
}

float boton1::getIzqBx() const
{
	return BIzq.getx();
}

float boton1::getIzqBy() const
{
    return BIzq.gety();
}
const auto settings = settings::getInstance();

void boton1::on_clickvel1() const
{
	settings->velocidades = vel1;
}

void boton1::on_clickvel2() const
{
	settings->velocidades = vel2;
}

void boton1::on_clickvel3() const
{
	settings->velocidades = vel2;
}

void boton1::on_clickTexOn() const
{
	settings->textura = !settings->textura;
}

void boton1::on_clickluz1() const
{
	settings->luz1 = !settings->luz1;
}

void boton1::on_clickluz2() const
{
	settings->luz2 = !settings->luz2;
}

void boton1::on_clickluz3() const
{
	settings->luz3 = !settings->luz3;
}

void boton1::on_clickwire() const
{
	settings->wireframe = !settings->wireframe;
}

void boton1::on_clickfaceteado() const
{
	settings->facetado = !settings->facetado;	
}

GLuint boton1::get_textura() const
{ 
    return tex.getId();
}
GLuint boton1::get_textura2() const
{
	return tex2.getId();
}
