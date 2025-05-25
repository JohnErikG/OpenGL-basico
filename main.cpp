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
#include "OpenGL-basico/Manejador/ManejadorModelos.h"
#include "OpenGL-basico/timer.h"
#include "OpenGL-basico/gamehub.h"
#include "OpenGL-basico/Settings.h"
#include "OpenGL-basico/renderMenu.h"
using namespace std;

void controlador_evento(SDL_Event &evento, bool &fin,bool & textOn, bool &luzON, escena &esc, bool  &start );



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
	SDL_ShowCursor(SDL_ENABLE);
	SDL_GL_SetSwapInterval(0);


	glMatrixMode(GL_PROJECTION);

	float color = 0;
	glClearColor(color, color, color, 1);

	gluPerspective(45, 1280 / 720.f, 0.1, 100);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	//TEXTURA
	manejadorT::init();
	manejadorL::init();
	Timer::init();
	gamehub::init();
	settings::getInstance();
	menuDeSettings::initMs();

	escena esc;
	
	bool fin = false;
	SDL_Event evento;
	float x, y, z;
	bool start = false;
	x = 0;
	y = 0;
	z = 5;
	float degrees = 0;
	
	Uint64 performanceFrequency = SDL_GetPerformanceFrequency();
	Uint64 frameStart, frameEnd;
	double elapsedSeconds;
	Uint64 lastTime = SDL_GetPerformanceCounter();
	int frameCount = 0;
	//FIN INICIALIZACION
	bool textOn = true;
	bool luzON = false;
	float vel = 1;
	//LOOP PRINCIPAL
	do{
		frameStart = SDL_GetPerformanceCounter();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		if (start) {

			switch (settings::getInstance()->velocidades) {
			case vel1:
				vel = 0.5;
				break;
			case vel2:
				vel = 1;
				break;
			case vel3:
				vel = 2;
				break;

			default: 		break;

			}


			if (menuDeSettings::initMs()->getMenuActivo()) {
				Timer::pause();
				SDL_SetRelativeMouseMode(SDL_FALSE);
				renderMenu::dibujarsettings(menuDeSettings::initMs());
			}
			else {
				SDL_SetRelativeMouseMode(SDL_TRUE);
				Timer::resume();
				esc.actualizar_escena();
			}
			renderMenu::dibujarGH();
			if (settings::getInstance()->luz1) {
				manejadorL::luz1M().activarLuz(GL_LIGHT0);
			}
			else {
				manejadorL::luz1M().desactivarLuz(GL_LIGHT0);
			}
			if (settings::getInstance()->luz2) {
				manejadorL::luz2M().activarLuz(GL_LIGHT1);
			}
			else {
				manejadorL::luz2M().desactivarLuz(GL_LIGHT1);
			}
			if (settings::getInstance()->luz3) {
				manejadorL::luz3M().activarLuz(GL_LIGHT2);
			}
			else {
				manejadorL::luz3M().desactivarLuz(GL_LIGHT2);
			}
		}else {

			renderMenu::dibujarInicio();
		}
		
		controlador_evento(evento,fin, textOn, luzON, esc, start);
		//FIN MANEJO DE EVENTOS
		SDL_GL_SwapWindow(win);
		frameEnd = SDL_GetPerformanceCounter();
		elapsedSeconds = (frameEnd - frameStart) / static_cast<double>(performanceFrequency);
		frameCount++;

		// Mostrar FPS cada segundo
		if ((frameEnd - lastTime) / static_cast<double>(performanceFrequency) >= 1.0) {
			std::cout << "FPS: " << frameCount << std::endl;
			frameCount = 0;
			lastTime = frameEnd;
		}
		const double TARGET_FRAME_TIME = 1.0 / (60.0*vel); // 60 FPS
		if (elapsedSeconds < TARGET_FRAME_TIME) {
			SDL_Delay(static_cast<Uint32>((TARGET_FRAME_TIME - elapsedSeconds) * 1000));
		}

	} while (!fin);
	//FIN LOOP PRINCIPAL
	// LIMPIEZA
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
void controlador_evento(SDL_Event &evento, bool &fin, bool  &textOn, bool &luzON, escena &esc, bool &start) {
	std::array<boton1*, 9> botones = menuDeSettings::initMs()->getBotones();
	if (start) {
		while (SDL_PollEvent(&evento)) {
			switch (evento.type) {
			case SDL_MOUSEMOTION:
				esc.rotar_camara(static_cast<float>(evento.motion.xrel), -static_cast<float>(evento.motion.yrel));
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (menuDeSettings::initMs()->getMenuActivo()) {

					if (botones[0]->is_inside(evento.button.x, evento.button.y)) {
						botones[0]->on_clickvel1();
						esc.setVelocidad(0.5f);
						botones[0]->set_click(true);
						botones[1]->set_click(false);
						botones[2]->set_click(false);
					}
					else if (botones[1]->is_inside(evento.button.x, evento.button.y)) {
						botones[1]->on_clickvel2();
						esc.setVelocidad(0.5f);
						botones[1]->set_click(true);
						botones[0]->set_click(false);
						botones[2]->set_click(false);
					}
					else if (botones[2]->is_inside(evento.button.x, evento.button.y)) {
						botones[2]->on_clickvel3();
						esc.setVelocidad(1.0f);
						botones[2]->set_click(true);
						botones[1]->set_click(false);
						botones[0]->set_click(false);
					}
					else if (botones[3]->is_inside(evento.button.x, evento.button.y)) {
						botones[3]->on_clickluz1();
						botones[3]->cambiarClick();
					}
					else if (botones[4]->is_inside(evento.button.x, evento.button.y)) {
						botones[4]->on_clickluz2();
						botones[4]->cambiarClick();
					}
					else if (botones[5]->is_inside(evento.button.x, evento.button.y)) {
						botones[5]->on_clickluz3();
						botones[5]->cambiarClick();
					}
					else if (botones[6]->is_inside(evento.button.x, evento.button.y)) {
						botones[6]->on_clickTexOn();
						botones[6]->cambiarClick();
					}
					else if (botones[7]->is_inside(evento.button.x, evento.button.y)) {
						botones[7]->on_clickwire();
						botones[7]->cambiarClick();
					}
					else if (botones[8]->is_inside(evento.button.x, evento.button.y)) {
						botones[8]->on_clickfaceteado();
						botones[8]->cambiarClick();
					}
				}
				break;
			case SDL_MOUSEBUTTONUP:

				break;

			case SDL_QUIT:
				fin = true;
				break;
			case SDL_KEYUP:
				if (!(menuDeSettings::initMs()->getMenuActivo())) {
					esc.mover_jugador(evento);
				}
				switch (evento.key.keysym.sym) {
				case SDLK_q:
					fin = true;
					break;
				case SDLK_ESCAPE:
					fin = true;
					break;
				case SDLK_p:
					menuDeSettings::initMs()->setMenuActivo(!menuDeSettings::initMs()->getMenuActivo());
					cout << "abrir menu";
					break;
				case SDLK_r:
					Timer::reset();
					break;
				case SDLK_v:
					esc.cambiar_camara();
					cout << "CAMBIE";
					break;
				case SDLK_s:

					break;
				}
			}
		}
	}
	else if (SDL_PollEvent(&evento)) {
		
		switch (evento.type) {
		case SDL_MOUSEBUTTONDOWN:
			start = true;
			Timer::start();
			break;
		default:
			break;
		}
	}

	}
