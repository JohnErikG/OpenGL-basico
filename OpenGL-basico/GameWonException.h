#pragma once
#include <exception>

class GameWonException : public std::exception {
public:
    const char* what() const noexcept override {
        return "El jugador gano";
    }
};