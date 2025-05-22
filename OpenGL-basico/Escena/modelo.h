#pragma once
#include <vector>
#include "../Utils/vertex.h"
#include "../Utils/vector3.h"

class modelo {
public:
	std::vector<vertex> vertices;
	std::vector<unsigned int> indices;


	explicit modelo(const std::vector<vertex>& vertices, std::vector<unsigned int>& indices) :vertices(vertices),indices(indices) {

	};
};