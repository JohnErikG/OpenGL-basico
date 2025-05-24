#include "player.h"
#include "../settings.h"

player::player(const vector3& posicion_inicial, const vector3& direccion, const vector3& up, const int segmentos)
 {
    direccion_ = direccion;
    up_ = up;
    segmentos_ = segmentos;
    contacto_ = true;
    for (int i = 0; i < segmentos_; i++) {
        cuerpo_.push_back(posicion_inicial + vector3(-1, 0, 0) * i);
    }

}

const std::vector<vector3>& player::get_cuerpo() const {
    return cuerpo_;
}

float player::get_velocidad() const {
    return velocidad_;
}

vector3 player::get_direccion() const {
    return direccion_;
}

vector3 player::get_up() const {
    return up_;
}

int player::get_segmentos() const {
    return segmentos_;
}

bool player::get_contacto() const {
    return contacto_;
}

void player::set_direccion(const vector3& direccion) {
    direccion_ = direccion;
}

void player::set_contacto(bool contacto) {
    contacto_ = contacto;
}

void player::set_up(const vector3& up) {
    up_ = up;
}

void player::mover() {
    // Muevo la cabeza
    vector3 nueva_cabeza = cuerpo_.front() + direccion_ * velocidad_;

    // Mover cada segmento al lugar del anterior
    for (int i = segmentos_ - 1; i > 0; --i) {
        cuerpo_[i] = cuerpo_[i - 1];
    }
    cuerpo_[0] = nueva_cabeza;
}

void player::set_segmentos(int segmentos) {
    segmentos_ = segmentos;
}

void player::crecer(const std::vector<vector3>& bloques) {
    vector3 nueva_direccion = cuerpo_[segmentos_ - 1] - cuerpo_[segmentos_ - 2];
    vector3 nuevo_segmento = cuerpo_[segmentos_ - 1] + nueva_direccion;
    for (vector3 bloque : bloques) {
        if (bloque.get_x() == nuevo_segmento.get_x() && bloque.get_y() == nuevo_segmento.get_y()) {
            nuevo_segmento = nuevo_segmento + vector3(-1, 1, 0);
        }
    }
    cuerpo_.push_back(nuevo_segmento);
    set_segmentos(segmentos_ + 1);
}

void player::caer() {
    for (int i = 0; i < segmentos_;i++) {
        cuerpo_[i] = cuerpo_[i]+ vector3(0,-1,0)* velocidad_;
    }
}