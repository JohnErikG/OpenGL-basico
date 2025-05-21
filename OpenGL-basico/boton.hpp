#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include "FreeImage.h"
#include <stdio.h>
#include <conio.h>
#include <GL/glu.h>
class Boton {
protected:
    float x, y, w, h;
    float r, g, b;
    bool clickeado;

public:
    explicit Boton(float _x, float _y, float _w, float _h,
        float _r = 0.0f, float _g = 0.5f, float _b = 1.0f)
        : x(_x), y(_y), w(_w), h(_h), r(_r), g(_g), b(_b), clickeado(false) {
    }

    virtual ~Boton() = default;
	Boton(const Boton&) = default; 
    virtual void dibujar() const {
        glColor3f(r, g, b);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
        glEnd();

    }

    virtual void manejarEvento(const SDL_Event& evento) {
        if (evento.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX = evento.button.x;
            int mouseY = evento.button.y;
            if (contiene(mouseX, mouseY)) {
                clickeado = true;
                onClick();
            }
        }
        else if (evento.type == SDL_MOUSEBUTTONUP) {
            clickeado = false;
        }
    }

    virtual bool contiene(int mouseX, int mouseY) const {
        return mouseX >= x && mouseX <= x + w &&
            mouseY >= y && mouseY <= y + h;
    }

    virtual void onClick() {
        // Se puede sobrescribir en subclases
        std::cout<<"Botón clickeado";
    }

    // Accesores y modificadores opcionales
    void setColor(float _r, float _g, float _b) {
        r = _r;
        g = _g;
        b = _b;
    }

    void setPosicion(float _x, float _y) {
        x = _x;
        y = _y;
    }

    void setTamano(float _w, float _h) {
        w = _w;
        h = _h;
    }
};