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
using namespace std;
void controlador_evento(SDL_Event &evento, Boton& boton, bool &rotate, bool &fin,bool & textOn, bool &luzON, Timer &t, escena &esc);


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



	glMatrixMode(GL_PROJECTION);

	float color = 0;
	glClearColor(color, color, color, 1);

	gluPerspective(45, 1280 / 720.f, 0.1, 100);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	//TEXTURA
	manejadorT::init();
	manejadorL::init();
	//char* archivo = new char[30];
	//archivo = "../Texturas/tierra.jpg";


	//////CARGAR IMAGEN
	//FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(archivo);
	//FIBITMAP* bitmap = FreeImage_Load(fif, archivo);
	//bitmap = FreeImage_ConvertTo24Bits(bitmap);
	//int w = FreeImage_GetWidth(bitmap);
	//int h = FreeImage_GetHeight(bitmap);
	//void* datos = FreeImage_GetBits(bitmap);
	////FIN CARGAR IMAGEN

	//GLuint textura;
	//glGenTextures(1, &textura);
	//glBindTexture(GL_TEXTURE_2D, textura);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, datos);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	//
	
	escena esc;
	ManejadorModelos manejadorM;

	modelo manzana = manejadorM.load_model("../Modelos/Apple.obj");
	printf("Se cargaron %d vertices", manzana.vertices.size());
	modelo pinchos = manejadorM.load_model("../Modelos/spike.obj");
	printf("Se cargaron %d vertices", pinchos.vertices.size());
	esc.addEntidad(entidad(manzana.vertices, manzana.indices, vector3(7, 1, 0), vector3(0.01f, 0.01f, 0.01f), manejadorT::texturaM().getId()));
	esc.addEntidad(entidad(manzana.vertices, manzana.indices, vector3(12, 0, 0), vector3(0.01f, 0.01f, 0.01f), manejadorT::texturaM().getId()));
	esc.addEntidad(entidad(manzana.vertices, manzana.indices, vector3(8, 3, 0), vector3(0.01f, 0.01f, 0.01f), manejadorT::texturaM().getId()));
	esc.addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(5, -1.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId()));
	esc.addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(5, -1.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId()));
	esc.addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(11, -0.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId()));
	esc.addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(12, 3.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId()));
	modelo cubo = ManejadorModelos::load_cube();
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(-1, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(0, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(1, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(2, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(3, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(4, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(6, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(7, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(7, 0, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(8, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(11, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(12, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(13, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, 0, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 0, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(8, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(7, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(6, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(6, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(11, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(12, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(13, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));
	esc.addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId()));

	bool fin = false;
	bool rotate = false;

	SDL_Event evento;

	float x, y, z;

	x = 0;
	y = 0;
	z = 5;
	float degrees = 0;
	Timer t = Timer();
	
	/*GLfloat luz_posicion[4] = { 0, 0, 1, 1 };*/
	//GLfloat luz_posicion1[4] = { 0, 0, -1, 1 };
	/*GLfloat colorLuz[4] = { 1, 0, 0, 0 };*/
	//FIN INICIALIZACION
	bool textOn = true;
	bool luzON = false;
	//LOOP PRINCIPAL
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

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
		esc.actualizar_escena();

		if (rotate) {
			degrees = degrees + 0.5f;
		}
		glRotatef(degrees, 0.0, 1.0, 0.0);

		/*
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
			glBindTexture(GL_TEXTURE_2D, manejadorT::texturaS().getId());
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
		*/
		Boton boton(0, 0, 1, 1, 0.1, 0.1, 0.1);
		//boton.dibujar();
		controlador_evento(evento,boton, rotate,fin, textOn, luzON, t, esc);
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
void controlador_evento(SDL_Event &evento, Boton &boton, bool  &rotate, bool &fin, bool  &textOn, bool &luzON, Timer &t, escena &esc) {
	while (SDL_PollEvent(&evento)) {
		switch (evento.type) {
		case SDL_MOUSEMOTION:
			//const float x_offset = static_cast<float>(evento.motion.xrel);
			//const float y_offset = -static_cast<float>(evento.motion.yrel);
			esc.rotar_camara( static_cast<float>(evento.motion.xrel), -static_cast<float>(evento.motion.yrel));
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
			esc.mover_jugador(evento);
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
				cout << "Arriba"<<endl;
				t.start();
				break;
			case SDLK_a:
				cout << "Izquierda"<< endl;
				cout << "tiempo: " << t.getSeconds() << endl;
				break;
			case SDLK_s:
				cout << "S Abajo";
				break;
			case SDLK_d:
				cout << "D Derecha";
				break;
			case SDLK_v:
				esc.cambiar_camara();
				cout << "CAMBIE";
				break;
			}
			}
		}
	}
