#pragma once
#include "SDL.h"
#include "SDL_opengl.h"
#include "../Escena/camara.h"
#include "../Player/player.h"

enum modo_camara
{
    primera_persona,
    normal,
    perspectiva
};

struct coordinate
{
    int height, width;
};


class escena final
{
    modo_camara modo_camara_ = normal;
    camara* camara_;
    player* jugador_;

    

public:
    escena();
    ~escena();
    void cambiar_camara();
    void rotar_camara(float x, float y) const;
    void actualizar_escena();
    void mover_jugador(const SDL_Event& evento) const;
    modo_camara get_modo_camara() const;
    camara* get_camara() const;
    void dibujar_jugador(bool primera_persona);
    void escena::drawCube(GLuint textura);
};
