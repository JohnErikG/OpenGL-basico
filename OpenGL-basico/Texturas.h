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
	GLuint id_;

public:
    explicit Texturas(const GLuint id) : id_(id)
    {
    }
    GLuint getId() const;


};
