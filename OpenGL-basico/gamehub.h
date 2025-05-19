#pragma once
#include "manejadorT.h"
#include "rectangulo.h"
#include "Texturas.h"

class gamehub
{
	static gamehub* instance;	
	rectangulo contenedor_ = rectangulo(vector3(-0.8f, -0.9f, 0.0f), vector3(0.8f, -0.9f, 0.0f), vector3(0.8f, -0.6f, 0.0f), vector3(-0.8f, -0.6f, 0.0f));

	rectangulo minutos_decena_ = rectangulo(vector3(-0.145f, 1.3f, 0.0f), vector3(-0.095f, 1.3f, 0.0f), vector3(-0.095f, 1.15f, 0.0f), vector3(-0.145f, 1.15f, 0.0f));
	rectangulo minutos_unidades_ = rectangulo(vector3(-0.085f, 1.3f, 0.0f), vector3(-0.035f, 1.3f, 0.0f), vector3(-0.035f, 1.15f, 0.0f), vector3(-0.085f, 1.15f, 0.0f));
	rectangulo espacio_ = rectangulo(vector3(-0.025f, 1.3f, 0.0f), vector3(0.025f, 1.3f, 0.0f), vector3(0.025f, 1.15f, 0.0f), vector3(-0.025f, 1.15f, 0.0f));
	rectangulo segundos_decena_ = rectangulo(vector3(0.035f, 1.3f, 0.0f), vector3(0.085f, 1.3f, 0.0f), vector3(0.085f, 1.15f, 0.0f), vector3(0.035f, 1.15f, 0.0f));
	rectangulo segundos_unidades_ = rectangulo(vector3(0.095f, 1.3f, 0.0f), vector3(0.145f, 1.3f, 0.0f), vector3(0.145f, 1.15f, 0.0f), vector3(0.095f, 1.15f, 0.0f));

	explicit gamehub() = default;

public:	
	void dibujarNumeros(const rectangulo& rec,const Texturas &tex  );
	static gamehub* getInstance();
	static void init();
	void update();
	void render();
	void cleanup();
	void setTiempo(Uint32 num, rectangulo pos);
	void DibujarTiempo(const Uint32 milisegundos);
};

