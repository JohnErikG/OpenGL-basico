#include "escena.h"
#include <stdio.h>
#include "SDL.h"
#include "SDL_opengl.h"
#include <GL/glu.h>
#include <iostream>
#include "../manejadorT.h"
#include "../Manejador/ManejadorModelos.h"
#include "entidad.h"
#include "modelo.h"
#include <vector>



void escena::drawCube(GLuint textura,vector3 posicion) {
   
    modelo cubo = ManejadorModelos::load_cube();
    entidad ecubo = entidad(cubo.vertices, cubo.indices, posicion, vector3(1, 1, 1), textura);
    ecubo.dibujar();
}

void escena::cambiar_camara()
{
    switch (modo_camara_)
    {
    case primera_persona:
        modo_camara_ = normal;
        camara_->set_posicion(vector3(7.5f, 3.5f, 20));
        camara_->set_direccion(vector3(0,0,-1));
        camara_->set_up(vector3(0, 1, 0));
        camara_->actualizar_angulos_desde_direccion();
        break;
    case normal:
        {
            modo_camara_ = perspectiva;
            vector3 objetivo = jugador_->get_cuerpo()[jugador_->get_segmentos() / 2];
            vector3 posicion_camara = objetivo + vector3(0, 5, 10);
            camara_->set_posicion(posicion_camara);
            camara_->set_direccion((objetivo - posicion_camara).normalize());
            camara_->actualizar_angulos_desde_direccion();
            break;
        }
    case perspectiva:
        modo_camara_ = primera_persona;
        camara_->set_posicion(jugador_->get_cuerpo()[0]);
        camara_->set_direccion(jugador_->get_direccion());
        camara_->set_up(jugador_->get_up());
        camara_->actualizar_angulos_desde_direccion();
        break;
    }
}


void escena::rotar_camara(const float x, const float y) const
{
    switch (modo_camara_)
    {
    case primera_persona:
        camara_->rotar(x, y, true);
        break;
    case normal:
        break;
    case perspectiva:
        camara_->rotar(x, y, false);
        break;
    }
}



escena::escena()
{
    vector3 pos(7.5f, 3.5f, 20);
    vector3 dir(0.0f, 0.0f, -1.0f);
    vector3 up(0.0f, 1.0f, 0.0f);
    jugador_ = new player;
    camara_ = new camara(&pos, &dir, &up);
}

escena::~escena()
{
    delete camara_;
    camara_ = nullptr;
}

void escena::actualizar_escena()
{


    auto pos = camara_->get_posicion();
    auto dir = camara_->get_direccion();
    auto up = camara_->get_up();

    gluLookAt(
        pos.get_x(), pos.get_y(), pos.get_z(),
        pos.get_x() + dir.get_x(), pos.get_y() + dir.get_y(), pos.get_z() + dir.get_z(),
        up.get_x(), up.get_y(), up.get_z()
    );

    for (entidad e: entidades_) {
        e.dibujar();
    }

    dibujar_jugador(modo_camara_ == primera_persona);


}

void escena::dibujar_jugador(bool primera_persona) {
    if (!primera_persona) {
        //Solo renderizo cabeza si no estoy en primera persona
        vector3 cabeza = jugador_->get_cuerpo()[0];
        drawCube(manejadorT::texturaP().getId(),vector3(cabeza.get_x(), cabeza.get_y(), cabeza.get_z()));
    }

    for (int i = 1; i < jugador_->get_segmentos();i++) {
        vector3 segmento = jugador_->get_cuerpo()[i];

        drawCube(manejadorT::texturaP().getId(),vector3(segmento.get_x(), segmento.get_y(), segmento.get_z()));
    
    }

}


void escena::mover_jugador(const SDL_Event& evento) const
{
    const float velocidad = 1.0f;
    vector3 movimiento;
   
    switch (modo_camara_)
    {
    case primera_persona:
    {
        vector3 direccion = camara_->get_direccion();
        if (std::abs(direccion.get_x()) >= std::abs(direccion.get_z()) && std::abs(direccion.get_x()) >= std::abs(direccion.get_y())) {
            direccion = vector3(direccion.get_x(),0,0);
        }
        else if ((std::abs(direccion.get_y()) >= std::abs(direccion.get_z()) && std::abs(direccion.get_y()) > std::abs(direccion.get_x()))){
            direccion = vector3(0, direccion.get_y(), 0);
        }
        else {
            direccion = vector3(0, 0, 0);
        }
        direccion.normalize();
        switch (evento.key.keysym.sym) {
        case SDLK_UP:
            jugador_->set_direccion(direccion);
            jugador_->mover();
            break;
        default:
            break;
        }
        
        break;
    }

    case normal:
    {
        switch (evento.key.keysym.sym) {
        case SDLK_UP:
            jugador_->set_direccion(vector3(1, 0, 0));
            jugador_->mover();
            break;
        case SDLK_DOWN:
            jugador_->set_direccion(vector3(-1, 0, 0));
            jugador_->mover();
            break;
        case SDLK_LEFT:
            jugador_->set_direccion(vector3(0, 1, 0));
            jugador_->mover();
            break;
        case SDLK_RIGHT:
            jugador_->set_direccion(vector3(0, -1, 0));
            jugador_->mover();
            break;
        default:
            break;
        }
        break;
    }

    case perspectiva:
    {
        switch (evento.key.keysym.sym) {
        case SDLK_UP:
            jugador_->set_direccion(vector3(1, 0, 0));
            jugador_->mover();
            break;
        case SDLK_DOWN:
            jugador_->set_direccion(vector3(-1, 0, 0));
            jugador_->mover();
            break;
        case SDLK_LEFT:
            jugador_->set_direccion(vector3(0, 1, 0));
            jugador_->mover();
            break;
        case SDLK_RIGHT:
            jugador_->set_direccion(vector3(0, -1, 0));
            jugador_->mover();
            break;
        default:
            break;
        }
        break;
    }

    default:
        break;
    }


    switch (modo_camara_) {
    case primera_persona:
        camara_->mover(jugador_->get_direccion() * velocidad);
        camara_->set_direccion(jugador_->get_direccion());
        camara_->actualizar_angulos_desde_direccion();
        break;
    case perspectiva:
        camara_->mover(jugador_->get_direccion() * velocidad);
        break;
    case normal:
        break;
    }

}

modo_camara escena::get_modo_camara() const
{
    return modo_camara_;
}

camara* escena::get_camara() const
{
    return camara_;
}

void escena::addEntidad(entidad& entidad) {
    entidades_.push_back(entidad);
}
