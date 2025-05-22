#pragma once
#include <vector>
#include <assimp/Importer.hpp>
#include "../Utils/vertex.h"
#include "../Escena/modelo.h"

class ManejadorModelos
{
    static Assimp::Importer importer_;
    static modelo* cubo_;

public:
    static modelo load_model(const std::string& file_path);
    static modelo& load_cube();
};
