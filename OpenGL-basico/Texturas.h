#pragma once
#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>
class Texturas
{
	GLuint id;

public:
    explicit Texturas(const GLuint id) : id(id)
    {
    }
    GLuint getId() const;


};
