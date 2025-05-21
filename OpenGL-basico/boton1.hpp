#pragma once
#include "vector2.h"
#include "texturas.h"
#include "manejadorT.h"

class boton1
{
	bool click = false;
	Texturas  tex= manejadorT::botont();	
	Texturas tex2 = manejadorT::botonf();
	vector2 Ader, BIzq;
	
	public :
		virtual ~boton1() = default;
		explicit boton1(const vector2& derecha_, const vector2& Izquierda_) : Ader(derecha_), BIzq(Izquierda_) {}
		boton1() : Ader(vector2()), BIzq(vector2()) {}
		bool is_inside(int x, int y)const;
		float getDerAx()const;
		float getDerAy()const;
		float getIzqAx()const;
		float getIzqAy()const;
		float getDerBx()const;
		float getDerBy()const;
		float getIzqBx()const;
		float getIzqBy()const;
		void on_clickvel1()const;
		void on_clickvel2()const;
		void on_clickvel3()const;
		void on_clickTexOn()const;
		void on_clickluz1()const;
		void on_clickluz2()const;
		void on_clickluz3()const;
		void on_clickwire()const;
		void on_clickfaceteado()const;
		GLuint  get_textura() const;
		GLuint get_textura2() const;
		bool get_click() const;
		void set_click(bool click_);
};

