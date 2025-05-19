#pragma once
#include "vector2.h"
#include "texturas.h"
class boton1
{
	vector2 derecha, Izauiqerda;
	explicit boton1(const vector2& derecha_, const vector2& Izquierda_) : derecha(derecha_), Izauiqerda(Izquierda_) {}
	public :
		virtual ~boton1() = default;
		boton1() : derecha(vector2()), Izauiqerda(vector2()) {}
		bool is_inside(int x, int y)const;
		float getDerA()const;
		float getIzqA()const;
		float getDerB()const;
		float getIzqB()const;
		void on_click()const;
		GLuint  get_textura(Texturas tex) const;
};

