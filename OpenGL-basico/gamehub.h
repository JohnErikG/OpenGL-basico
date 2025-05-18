#pragma once
#include "manejadorT.h"
#include "rectangulo.h"


class gamehub
{
	static gamehub* instance;	
	rectangulo contenedor_ = rectangulo(vector3(-0.8f, -0.9f, 0.0f), vector3(0.8f, -0.9f, 0.0f), vector3(0.8f, -0.6f, 0.0f), vector3(-0.8f, -0.6f, 0.0f));

	rectangulo minutos_decena_ = rectangulo(vector3(-0.145f, -0.7f, 0.0f), vector3(-0.095f, -0.7f, 0.0f), vector3(-0.095f, -0.85f, 0.0f), vector3(-0.145f, -0.85f, 0.0f));
	rectangulo minutos_unidades_ = rectangulo(vector3(-0.085f, -0.7f, 0.0f), vector3(-0.035f, -0.7f, 0.0f), vector3(-0.035f, -0.85f, 0.0f), vector3(-0.085f, -0.85f, 0.0f));
	rectangulo espacio_ = rectangulo(vector3(-0.025f, -0.7f, 0.0f), vector3(0.025f, -0.7f, 0.0f), vector3(0.025f, -0.85f, 0.0f), vector3(-0.025f, -0.85f, 0.0f));
	rectangulo segundos_decena_ = rectangulo(vector3(0.035f, -0.7f, 0.0f), vector3(0.085f, -0.7f, 0.0f), vector3(0.085f, -0.85f, 0.0f), vector3(0.035f, -0.85f, 0.0f));
	rectangulo segundos_unidades_ = rectangulo(vector3(0.095f, -0.7f, 0.0f), vector3(0.145f, -0.7f, 0.0f), vector3(0.145f, -0.85f, 0.0f), vector3(0.095f, -0.85f, 0.0f));

	explicit gamehub() = default;

public:	
	static gamehub* getInstance();
	static void init();
	void update();
	void render();
	void cleanup();
	static void DibujarTiempo(const Uint32 milisegundos);
	static void setTiempo(Uint32 num , rectangulo pos );

};

