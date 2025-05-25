#pragma once
#include <exception>

class GameOverException : public std::exception {
public:
    const char* what() const noexcept override {
        return "El jugador murio";
    }
};