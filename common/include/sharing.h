//
// Created by ukonnra on 2020/8/3.
//

#ifndef INTERESTING_RENDERERS_SHARING_H
#define INTERESTING_RENDERERS_SHARING_H

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <streambuf>
#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace Assimp;

unsigned int genTextureFromFile(const std::string &path,
                                const std::string &directory,
                                bool gamma = false);
#endif // INTERESTING_RENDERERS_SHARING_H
