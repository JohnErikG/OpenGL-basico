#pragma once
#include <vector>
#include "SDL.h"
#include "SDL_opengl.h"
#include "../Utils/vertex.h"
#include "../Utils/vector3.h"
#include <GL/glu.h>


class entidad {
	

public:
	enum tipo_entidad
	{
		piso,
		pincho,
		manzana,
		jugador
	};
	std::vector<vertex> vertices_;
	std::vector<unsigned int> indices_;
	vector3 posicion_;
	vector3 escala_;
	GLuint textura_;
	tipo_entidad tipo_;
	bool activa_;
	void dibujar() const;
	void set_activa();

	explicit entidad(const std::vector<vertex>& vertices, std::vector<unsigned int>& indices, vector3 posicion, vector3 escala, GLuint textura, tipo_entidad tipo) :vertices_(vertices),indices_(indices), posicion_(posicion), escala_(escala), textura_(textura), tipo_(tipo),activa_(true) {
	
	};
};