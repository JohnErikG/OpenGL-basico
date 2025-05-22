#include "ManejadorModelos.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include "../Escena/modelo.h"

Assimp::Importer ManejadorModelos::importer_;
modelo* ManejadorModelos::cubo_ = nullptr;

void process_mesh(const aiMesh* mesh, std::vector<vertex>& vertices,
    std::vector<unsigned int>& indices)
{
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        auto position = vector3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        auto normal = vector3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
        vector2 texture;
        if (mesh->mTextureCoords[0]) texture = vector2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
        else texture = vector2(0.0f, 0.0f);

        vertices.emplace_back(position, normal, texture);
    }

    // Indices
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        const aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }
}


void process_node(const aiNode* node, const aiScene* scene, std::vector<vertex>& vertices,
    std::vector<unsigned int>& indices)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        process_mesh(mesh, vertices, indices);
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        process_node(node->mChildren[i], scene, vertices, indices);
    }
}

modelo ManejadorModelos::load_model(const std::string& file_path)
{
    const aiScene* scene = importer_.ReadFile(file_path,
        aiProcess_Triangulate |
        aiProcess_FlipUVs |
        aiProcess_GenNormals);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        // Error handling
        std::cerr << "ERROR::ASSIMP::" << importer_.GetErrorString() << '\n';
        throw std::runtime_error("Error loading model");
    }

    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;

    process_node(scene->mRootNode, scene, vertices, indices);

    return modelo(vertices,indices);
}

modelo& ManejadorModelos::load_cube() {
    if (cubo_ != nullptr) {
        return *cubo_;
    }
    float x = -0.5;
    float y = -0.5;
    float z = -0.5;
    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;
    vector3 posiciones[8] = {
        vector3(x, y, z),
        vector3(x + 1, y, z),
        vector3(x + 1, y + 1, z),
        vector3(x, y + 1, z),
        vector3(x, y, z + 1),
        vector3(x + 1, y, z + 1),
        vector3(x + 1, y + 1, z + 1),
        vector3(x, y + 1, z + 1)
    };

    vector3 normal = vector3(0, 0, 1);
    vertices.emplace_back(posiciones[4],normal,vector2(0,0));
    vertices.emplace_back(posiciones[5], normal, vector2(1, 0));
    vertices.emplace_back(posiciones[6], normal, vector2(1, 1));
    vertices.emplace_back(posiciones[7], normal, vector2(0, 1));
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);

    normal = vector3(0, 0, -1);
    vertices.emplace_back(posiciones[1], normal, vector2(0, 0));
    vertices.emplace_back(posiciones[0], normal, vector2(1, 0));
    vertices.emplace_back(posiciones[3], normal, vector2(1, 1));
    vertices.emplace_back(posiciones[2], normal, vector2(0, 1));
    indices.push_back(4);
    indices.push_back(5);
    indices.push_back(6);
    indices.push_back(4);
    indices.push_back(6);
    indices.push_back(7);

    normal = vector3(1,0,0);
    vertices.emplace_back(posiciones[5], normal, vector2(0, 0));
    vertices.emplace_back(posiciones[1], normal, vector2(1, 0));
    vertices.emplace_back(posiciones[2], normal, vector2(1, 1));
    vertices.emplace_back(posiciones[6], normal, vector2(0, 1));
    indices.push_back(8);
    indices.push_back(9);
    indices.push_back(10);
    indices.push_back(8);
    indices.push_back(10);
    indices.push_back(11);

    normal = vector3(-1, 0, 0);
    vertices.emplace_back(posiciones[0], normal, vector2(0, 0));
    vertices.emplace_back(posiciones[4], normal, vector2(1, 0));
    vertices.emplace_back(posiciones[7], normal, vector2(1, 1));
    vertices.emplace_back(posiciones[3], normal, vector2(0, 1));
    indices.push_back(12);
    indices.push_back(13);
    indices.push_back(14);
    indices.push_back(12);
    indices.push_back(14);
    indices.push_back(15);

    normal = vector3(0, 1, 0);
    vertices.emplace_back(posiciones[7], normal, vector2(0, 0));
    vertices.emplace_back(posiciones[6], normal, vector2(1, 0));
    vertices.emplace_back(posiciones[2], normal, vector2(1, 1));
    vertices.emplace_back(posiciones[3], normal, vector2(0, 1));
    indices.push_back(16);
    indices.push_back(17);
    indices.push_back(18);
    indices.push_back(16);
    indices.push_back(18);
    indices.push_back(19);
    
    normal = vector3(0, -1, 0);
    vertices.emplace_back(posiciones[0], normal, vector2(0, 0));
    vertices.emplace_back(posiciones[1], normal, vector2(1, 0));
    vertices.emplace_back(posiciones[5], normal, vector2(1, 1));
    vertices.emplace_back(posiciones[4], normal, vector2(0, 1));
    indices.push_back(20);
    indices.push_back(21);
    indices.push_back(22);
    indices.push_back(20);
    indices.push_back(22);
    indices.push_back(23);

    static modelo cubo = modelo(vertices, indices);
    cubo_ = &cubo;
    return cubo;
}