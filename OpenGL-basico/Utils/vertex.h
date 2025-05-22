#pragma once

#include "../Utils/vector2.h"
#include "../Utils/vector3.h"

struct vertex
{
    vector3 position, normal;
    vector2 tex_coords;

    explicit vertex(const vector3& position, const vector3& normal, const vector2 tex_coords)
        : position(position), normal(normal), tex_coords(tex_coords)
    {
    }
};
