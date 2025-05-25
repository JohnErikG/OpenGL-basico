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
	static manejadorL* instanceL ;	
	GLfloat luz_pos[4] = { 1,1, 1, 1 };
	luces luz2 = luces(luz_pos, 3.0f, 3.0f, 3.0f, 1.0f, 1.0f, 1.0f);
	GLfloat luz_pos2[4] = { -3,-1, 1, 1 };
	luces luz1 = luces(luz_pos2, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	GLfloat luz_pos3[4] = { 6,7, 6, 1 };
	luces luz3 = luces(luz_pos3, 0.0f, 3.0f, 0.0f, 0.0f, 3.0f, 0.0f);
	explicit manejadorL() :luz1(luz_pos2, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f), luz2(luz_pos, 3.0f, 3.0f, 3.0f, 1.0f, 1.0f, 1.0f), luz3(luz_pos3, 0.0f, 3.0f, 0.0f, 0.0f, 3.0f, 0.0f) 
	{
	}

public:
	static void init();
	static luces luz1M();
	static luces luz2M();
	static luces luz3M();

};
