#include "player.h"
#include "../settings.h"

player::player(const vector3& posicion_inicial, const vector3& direccion, const vector3& up, const int segmentos)
{
    direccion_ = direccion;
    up_ = up;
    segmentos_ = segmentos;
    contacto_ = true;
    cuerpo_.clear();
    buffer_posiciones.clear();

    for (int i = 0; i < segmentos_; i++) {
        vector3 pos = posicion_inicial - direccion * static_cast<float>(i);
        cuerpo_.push_back(pos);
        buffer_posiciones.push_back(pos);
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

void player::set_velocidad(float velocidad) {
    velocidad_ = velocidad;
}

void player::set_up(const vector3& up) {
    up_ = up;
}

void player::mover() {
    // Muevo la cabeza
    vector3 nueva_cabeza = cuerpo_.front() + direccion_ * velocidad_;
    cuerpo_[0] = nueva_cabeza;

    if (buffer_posiciones.empty() || (nueva_cabeza - buffer_posiciones.back()).magnitude() >= 0.01f) {
        buffer_posiciones.push_back(nueva_cabeza);
    }

    // Calculamos la distancia máxima que debe cubrir el buffer
    float max_distancia = (segmentos_ - 1) + 1.0f; // margen adicional

    // Eliminamos posiciones antiguas que queden fuera del rango que necesitamos
    while (buffer_posiciones.size() > 1 &&
        (nueva_cabeza - buffer_posiciones.front()).magnitude() > max_distancia) {
        buffer_posiciones.pop_front();
    }

    // Para cada segmento, interpolamos su posición desde atrás hacia adelante (cabeza -> cola)
    for (int i = 0; i < segmentos_; ++i) {
        float distancia_objetivo = static_cast<float>(i); // distancia desde cabeza hacia cola

        float dist_buffer = 0.0f;
        int j = static_cast<int>(buffer_posiciones.size()) - 1;

        // Buscamos el segmento del buffer donde cae la distancia objetivo (recorriendo hacia atrás)
        for (; j > 0; --j) {
            float seg_dist = (buffer_posiciones[j] - buffer_posiciones[j - 1]).magnitude();
            if (dist_buffer + seg_dist >= distancia_objetivo) break;
            dist_buffer += seg_dist;
        }

        if (j <= 0) {
            cuerpo_[i] = buffer_posiciones.front();
            continue;
        }

        float seg_dist = (buffer_posiciones[j] - buffer_posiciones[j - 1]).magnitude();
        float restante = distancia_objetivo - dist_buffer;
        float t = seg_dist > 0.0f ? restante / seg_dist : 0.0f;

        // Interpolación entre buffer_posiciones[j] (más nuevo) y buffer_posiciones[j - 1] (más viejo)
        cuerpo_[i] = buffer_posiciones[j] * (1 - t) + buffer_posiciones[j - 1] * t;
    }
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
    vector3 desplazamiento(0, -1, 0);
    float paso = velocidad_;

    // Mover cuerpo
    for (int i = 0; i < segmentos_; i++) {
        cuerpo_[i] = cuerpo_[i] + desplazamiento * paso;
    }

    // Mover también todas las posiciones del buffer
    for (auto& pos : buffer_posiciones) {
        pos = pos + desplazamiento * paso;
    }
}