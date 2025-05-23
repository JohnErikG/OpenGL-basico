#pragma once
#include "../Utils/vector3.h"
#include <vector>

class player {
    std::vector<vector3> cuerpo_;
    vector3 direccion_;
    vector3 up_;
    float velocidad_ = 1.0f;
    int segmentos_;
    bool contacto_;

public:
    explicit player(const vector3& posicion_inicial = vector3(2, 0, 0),
        const vector3& direccion = vector3(1, 0, 0), const vector3& up = vector3(0,1,0), int segmentos = 3);

    const std::vector<vector3>& get_cuerpo() const;
    vector3 get_direccion() const;
    vector3 get_up() const;
    float get_velocidad() const;
    int get_segmentos() const;
    bool get_contacto() const;

    void set_direccion(const vector3& direccion);
    void set_up(const vector3& up);
    void set_segmentos(const int segmentos);
    void set_contacto(bool contacto);

    void crecer(const std::vector<vector3>& bloques);
    void mover();
    void caer();
};