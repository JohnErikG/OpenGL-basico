#pragma once

#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>

class luces
{
private:
	GLuint luz;
	GLfloat luz_p[4];
	float r_a, g_a, b_a;
	float r_d, g_d, b_d;

public:

	explicit luces(GLfloat luz_posicion[4], float r_ambient, float g_ambient, float b_ambient,
		float r_diffuse, float g_diffuse, float b_diffuse, const GLuint luz ) :luz_p{ luz_posicion[1],luz_posicion[2],luz_posicion[3],luz_posicion[4] }, r_a(r_ambient), g_a(g_ambient), b_a(b_ambient),
			r_d(r_diffuse),g_d(g_diffuse),b_d(b_diffuse), luz(luz){}
	
	void setLuzPosicion(GLfloat luz_posicion[4])
	{
		this->luz_p[0] = luz_posicion[0];
		this->luz_p[1] = luz_posicion[1];
		this->luz_p[2] = luz_posicion[2];
		this->luz_p[3] = luz_posicion[3];
	}
	void setColorAmbient(float r_ambient, float g_ambient, float b_ambient)
	{
		this->r_a = r_ambient;
		this->g_a = g_ambient;
		this->b_a = b_ambient;
	}
	void setColorDiffuse(float r_diffuse, float g_diffuse, float b_diffuse)
	{
		this->r_d = r_diffuse;
		this->g_d = g_diffuse;
		this->b_d = b_diffuse;
	}
	void activarLuz(int luz)
	{
		GLfloat colorLuz[4] = { r_d, g_d, b_d, 1 };
		glEnable(luz);
		glLightfv(luz, GL_POSITION, luz_p);
		glLightfv(luz, GL_DIFFUSE, colorLuz);
		glLightfv(luz, GL_AMBIENT, colorLuz);
	}
	GLuint getLuz() const;

};

