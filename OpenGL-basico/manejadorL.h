#pragma once
#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>
#include "luces.hpp"
class manejadorL
{
	static manejadorL* instance;	
	luces luz1;
	const static GLuint pos = 0;
	GLfloat luz_pos[4] = { 0, 0, 1, 1 };
	explicit manejadorL() :luz1( luz_pos, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, pos+1)
	{
	}

public:
	static void init();
	static luces luz1M();

};
