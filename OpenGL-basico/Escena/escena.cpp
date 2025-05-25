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
    entidad ecubo = entidad(cubo.vertices, cubo.indices, posicion, vector3(1, 1, 1), textura,entidad::jugador);
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
    modelo manzana = ManejadorModelos::load_model("../Modelos/Apple.obj");
    printf("Se cargaron %d vertices", manzana.vertices.size());
    modelo pinchos = ManejadorModelos::load_model("../Modelos/spike.obj");
    printf("Se cargaron %d vertices", pinchos.vertices.size());
    modelo portal = ManejadorModelos::load_model("../Modelos/Portal_01.fbx");
    addEntidad(entidad(portal.vertices, portal.indices, vector3(14, 3.5, 0), vector3(0.47, 0.47, 0.47), manejadorT::texturapor().getId(), entidad::piso));
    addEntidad(entidad(manzana.vertices, manzana.indices, vector3(7, 1, 0), vector3(0.01f, 0.01f, 0.01f), manejadorT::texturaM().getId(), entidad::manzana));
    addEntidad(entidad(manzana.vertices, manzana.indices, vector3(12, 0, 0), vector3(0.01f, 0.01f, 0.01f), manejadorT::texturaM().getId(), entidad::manzana));
    addEntidad(entidad(manzana.vertices, manzana.indices, vector3(8, 3, 0), vector3(0.01f, 0.01f, 0.01f), manejadorT::texturaM().getId(), entidad::manzana));
    addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(5, -1.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId(), entidad::pincho));
    addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(5, -1.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId(), entidad::pincho));
    addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(13, -0.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId(), entidad::pincho));
    addEntidad(entidad(pinchos.vertices, pinchos.indices, vector3(12, 3.5f, 0), vector3(0.05f, 0.055f, 0.05f), manejadorT::imagenM().getId(), entidad::pincho));
    modelo cubo = ManejadorModelos::load_cube();
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(-1, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(0, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(1, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(2, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(3, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(4, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(6, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(7, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(7, 0, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(8, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(11, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(12, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(13, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, -1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, 0, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 0, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 1, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(8, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(7, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(6, 2, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(6, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(10, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(11, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(12, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(13, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
    addEntidad(entidad(cubo.vertices, cubo.indices, vector3(14, 3, 0), vector3(1, 1, 1), manejadorT::texturaS().getId(), entidad::piso));
}

escena::~escena()
{
    delete camara_;
    camara_ = nullptr;
}

void escena::calcular_manzanas() {
    bool borrado = false;
    for (entidad& manzana : manzanas_) {
        if (manzana.activa_ && manzana.posicion_.get_x() == jugador_->get_cuerpo()[0].get_x() && manzana.posicion_.get_y() == jugador_->get_cuerpo()[0].get_y()) {
            manzana.set_activa();
            jugador_->crecer(bloques_);
            borrado = true;
            break;
        }
    }
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

    for (const entidad& e : entidades_) {
         e.dibujar();
    }

    for (const entidad& e : manzanas_) {
        if (e.activa_) {
            e.dibujar();
        }
    }

    if (!jugador_->get_contacto()) {
        jugador_->caer();
        if (jugador_->get_cuerpo()[0].get_y() < -20) {
            printf("Mori");
        }
        switch (modo_camara_) {
        case primera_persona:
            camara_->mover(vector3(0,-1,0) * jugador_->get_velocidad());
            camara_->set_direccion(jugador_->get_direccion());
            camara_->actualizar_angulos_desde_direccion();
            break;
        case perspectiva:
            camara_->mover(vector3(0, -1, 0) * jugador_->get_velocidad());
            break;
        case normal:
            break;
        }
        for (const vector3& segmento : jugador_->get_cuerpo()) {
            if (calcular_colisiones(vector3(0, 0, 0), segmento) == 3) {
                printf("Mori");
            }
        }
        calcular_gravedad();
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

unsigned int escena::calcular_colisiones(const vector3& direccion, const vector3& segmento) {
    
    vector3 nueva_posicion = segmento + direccion * jugador_->get_velocidad();
    
    for (int i = 1; i < jugador_->get_segmentos(); i++) {
        if (jugador_->get_cuerpo()[i].get_x() == nueva_posicion.get_x() && jugador_->get_cuerpo()[i].get_y() == nueva_posicion.get_y()) {
            return 1;
        }
    }
    
    for (const vector3& bloque : bloques_) {
        if (bloque.get_x() == nueva_posicion.get_x() && bloque.get_y() == nueva_posicion.get_y()) {
            return 2;
        }
    }

    for (const vector3& pincho : pinchos_) {
        if (pincho.get_x() == nueva_posicion.get_x() && pincho.get_y() + 0.5f == nueva_posicion.get_y()) {
            return 3;
        }
    }
    
    return 0;

}


void escena::mover_jugador(const SDL_Event& evento)
{
    const float velocidad = 1.0f;
    vector3 movimiento;
    bool choca = false;
    switch (modo_camara_)
    {
    case primera_persona:
    {
        vector3 direccion = camara_->get_direccion();
        if (std::abs(direccion.get_x()) >= std::abs(direccion.get_z()) && std::abs(direccion.get_x()) >= std::abs(direccion.get_y())) {
            direccion = vector3(direccion.get_x(), 0, 0);
        }
        else if ((std::abs(direccion.get_y()) >= std::abs(direccion.get_z()) && std::abs(direccion.get_y()) > std::abs(direccion.get_x()))) {
            direccion = vector3(0, direccion.get_y(), 0);
        }
        else {
            direccion = vector3(0, 0, 0);
        }
        direccion.normalize();
        switch (evento.key.keysym.sym) {
        case SDLK_UP:
            jugador_->set_direccion(direccion);
            choca = calcular_colisiones(direccion,jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
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
            choca = calcular_colisiones(vector3(1, 0, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        case SDLK_DOWN:
            jugador_->set_direccion(vector3(-1, 0, 0));
            choca = calcular_colisiones(vector3(-1, 0, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        case SDLK_LEFT:
            jugador_->set_direccion(vector3(0, 1, 0));
            choca = calcular_colisiones(vector3(0, 1, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        case SDLK_RIGHT:
            jugador_->set_direccion(vector3(0, -1, 0));
            choca = calcular_colisiones(vector3(0, -1, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
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
            choca = calcular_colisiones(vector3(1, 0, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        case SDLK_DOWN:
            jugador_->set_direccion(vector3(-1, 0, 0));
            choca = calcular_colisiones(vector3(-1, 0, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        case SDLK_LEFT:
            jugador_->set_direccion(vector3(0, 1, 0));
            choca = calcular_colisiones(vector3(0, 1, 0),jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        case SDLK_RIGHT:
            jugador_->set_direccion(vector3(0, -1, 0));
            choca = calcular_colisiones(vector3(0, -1, 0), jugador_->get_cuerpo()[0]) != 0;
            if (!choca) {
                jugador_->mover();
            }
            break;
        default:
            break;
        }
        break;
    }
    }

    switch (modo_camara_) {
    case primera_persona:
        if (!choca) {
            camara_->mover(jugador_->get_direccion() * velocidad);
        }
        camara_->set_direccion(jugador_->get_direccion());
        camara_->actualizar_angulos_desde_direccion();
        break;
    case perspectiva:
        if (!choca) {
            camara_->mover(jugador_->get_direccion() * velocidad);
        }
        break;
    case normal:
        break;
    }

    calcular_manzanas();
    calcular_gravedad();

}

void escena::calcular_gravedad() {
    for (const vector3& segmento : jugador_->get_cuerpo()) {
        if (calcular_colisiones(vector3(0, -1, 0), segmento) == 2 ) {
            jugador_->set_contacto(true);
            return;
        }
    }
    jugador_->set_contacto(false);
}

modo_camara escena::get_modo_camara() const
{
    return modo_camara_;
}

camara* escena::get_camara() const
{
    return camara_;
}

void escena::addEntidad(const entidad& e) {
    switch (e.tipo_) {
    case entidad::manzana:
        manzanas_.push_back(e);
        break;
    case entidad::piso:
        bloques_.push_back(e.posicion_);
        entidades_.push_back(e);
        break;
    case entidad::pincho:
        pinchos_.push_back(e.posicion_);
        entidades_.push_back(e);
        break;
    }
}
