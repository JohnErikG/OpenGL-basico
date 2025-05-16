#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>
#include "OpenGL-basico/Utils/vector3.h"
#include "OpenGL-basico/Escena/escena.h"
#include "OpenGL-basico/boton.hpp"
#include "OpenGL-basico/manejadorT.h"
#include "OpenGL-basico/manejadorL.h"
using namespace std;
void controlador_evento(SDL_Event &evento, Boton& boton, bool &rotate, bool &fin,bool & textOn, bool &luzON);

int main(int argc, char *argv[]) {
float cubeX = 0.0f, cubeY = 0.0f, cubeZ = -5.0f;


int main(int argc, char* argv[]) {
	//INICIALIZACION
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
		exit(1);
	}

	SDL_Window* win = SDL_CreateWindow("juego",
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
	manejadorT::init();
	manejadorL::init();
	char* archivo = new char[30];
	archivo = "../Texturas/tierra.jpg";

	bool fin = false;
	bool rotate = false;

	SDL_Event evento;

	float x, y, z;

	x = 0;
	y = 0;
	z = 5;
	float degrees = 0;

	GLfloat luz_posicion[4] = { 0, 0, 1, 1 };
	//GLfloat luz_posicion1[4] = { 0, 0, -1, 1 };
	GLfloat colorLuz[4] = { 1, 0, 0, 0 };
	//FIN INICIALIZACION
	bool textOn = true;
	bool luzON = false;
	//LOOP PRINCIPAL
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		escena.actualizar_escena();

		//PRENDO LA LUZ (SIEMPRE DESPUES DEL gluLookAt)
		//glEnable(GL_LIGHT0); // habilita la luz 0
		//glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);
		//glLightfv(GL_LIGHT0, GL_DIFFUSE, colorLuz);
		//
		//glEnable(GL_LIGHT1); // habilita la luz 1
		//glLightfv(GL_LIGHT1, GL_POSITION, luz_posicion1);
		//glLightfv(GL_LIGHT1, GL_DIFFUSE, colorLuz);
		if (luzON) {
			manejadorL::luz1M().activarLuz(GL_LIGHT0);
			manejadorL::luz2M().desactivarLuz(GL_LIGHT1);
		}
		else {
			manejadorL::luz1M().desactivarLuz(GL_LIGHT0);

			manejadorL::luz2M().activarLuz(GL_LIGHT1);

		}

		glPushMatrix();
		//TRANSFORMACIONES LINEALES
		if (rotate){
			degrees = degrees + 1;
		}
		glRotatef(degrees, 0.0, 1.0, 0.0);

		//DIBUJAR OBJETOS
		//DIBUJO TRIANGULO CON COLOR
		glBegin(GL_TRIANGLES);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(1., -1., 0.);
			glVertex3f(-1., -1., 0.);
			glVertex3f(0., 1., 0.);
		glEnd();
		glPopMatrix();

		//DIBUJO TRIANGULO CON TEXTURA
		if (textOn){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, manejadorT::imagenM().getId());
		}
		glBegin(GL_TRIANGLES);
			glColor3f(1.0, 1.0, 1.0);
			glTexCoord2f(0, 0);
			glVertex3f(3., -1., 0.);
			glTexCoord2f(0, 1);
			glVertex3f(1., -1., 0.);
			glTexCoord2f(1, 0);
			glVertex3f(2., 1., 0.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		Boton boton(0, 0, 1, 1,0.1, 0.1 ,0.1);	
		boton.dibujar();
		//DIBUJO TRIANGULO CON LUZ
		glEnable(GL_LIGHTING);
		glBegin(GL_TRIANGLES);
			glNormal3f(0, 0, 1);
			glVertex3f(-1., -1., 0.);
			glVertex3f(-3., -1., 0.);
			glVertex3f(-2., 1., 0.);
		glEnd();
		glDisable(GL_LIGHTING);
		

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
		controlador_evento(evento,boton, rotate,fin, textOn);
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
void controlador_evento(SDL_Event &evento, Boton &boton, bool  &rotate, bool &fin, bool  &textOn, bool &luzON) {
	while (SDL_PollEvent(&evento)) {
		switch (evento.type) {
		case SDL_MOUSEMOTION:
			printf("Movimiento del ratón: dx = %d, dy = %d\n", evento.motion.xrel, evento.motion.yrel);
			break;

		case SDL_MOUSEBUTTONDOWN:

			if (!boton.contiene(evento.button.x, evento.button.y)) {
				boton.manejarEvento(evento);
				boton.onClick();
			}
			else {
				cout << "No clickeado\n";
			}
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
			switch (evento.key.keysym.sym) {
			case SDLK_q:
				fin = true;
				break;
			case SDLK_ESCAPE:
				fin = true;
				break;
			case SDLK_l:
				textOn = !textOn;
				break;
			case SDLK_RIGHT:
				break;
			case SDLK_p:
				cout << "abrir menu";
				break;
			case SDLK_g:
				luzON = !luzON;
				cout << "G luz";
				break;
			case SDLK_w:
				cout << "W Arriba";
				break;
			case SDLK_a:
				cout << "A Izquierda";
				break;
			case SDLK_s:
				cout << "S Abajo";
				break;
			case SDLK_d:
				cout << "D Derecha";
				break;
			}
		}
	}
	}
