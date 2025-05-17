#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>
#include "OpenGL-basico/Utils/vector3.h"
#include "OpenGL-basico/Escena/escena.h"

using namespace std;
float cubeX = 0.0f, cubeY = 0.0f, cubeZ = -5.0f;


int main(int argc, char* argv[]) {
	//INICIALIZACION
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
		exit(1);
	}

	SDL_Window* win = SDL_CreateWindow("ICG-UdelaR",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	SDL_GLContext context = SDL_GL_CreateContext(win);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	

	glMatrixMode(GL_PROJECTION);

	float color = 0;
	glClearColor(color, color, color, 1);

	gluPerspective(45, 1280 / 720.f, 0.1, 100);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	//TEXTURA
	char* archivo = new char[30];
	archivo = "../Texturas/tierra.jpg";


	//CARGAR IMAGEN
	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(archivo);
	FIBITMAP* bitmap = FreeImage_Load(fif, archivo);
	bitmap = FreeImage_ConvertTo24Bits(bitmap);
	int w = FreeImage_GetWidth(bitmap);
	int h = FreeImage_GetHeight(bitmap);
	void* datos = FreeImage_GetBits(bitmap);
	//FIN CARGAR IMAGEN

	GLuint textura;
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, datos);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	cout << textura;

	escena escena;


	bool fin = false;
	bool rotate = false;

	SDL_Event evento;

	float x, y, z;

	x = 0;
	y = 0;
	z = 5;
	float degrees = 0;

	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		escena.actualizar_escena();

		if (rotate) {
			degrees = degrees + 0.5f;
		}
		glRotatef(degrees, 0.0, 1.0, 0.0);

		//FIN DIBUJAR OBJETOS

		//MANEJO DE EVENTOS
		while (SDL_PollEvent(&evento)) {
			switch (evento.type) {
			case SDL_MOUSEMOTION:
			{
				const float x_offset = static_cast<float>(evento.motion.xrel);
				const float y_offset = -static_cast<float>(evento.motion.yrel);
				escena.rotar_camara(x_offset, y_offset);
				break;
			}

			case SDL_MOUSEBUTTONDOWN:
				rotate = true;
				cout << "ROT\n";
				break;
			case SDL_MOUSEBUTTONUP:
				rotate = false;
				break;
			case SDL_QUIT:
				fin = true;
				break;
			case SDL_KEYUP:
				escena.mover_jugador(evento);
				switch (evento.key.keysym.sym) {
				case SDLK_ESCAPE:
					fin = true;
					break;
				case SDLK_v:
					escena.cambiar_camara();
					cout << "CAMBIE";
					break;
				}
			}
		}
		//FIN MANEJO DE EVENTOS
		SDL_GL_SwapWindow(win);
	} while (!fin);
	//FIN LOOP PRINCIPAL
	// LIMPIEZA
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
