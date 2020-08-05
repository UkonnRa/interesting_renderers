//
// Created by ukonnra on 2020/8/3.
//

#include "texture.h"

#include <utility>

texture::texture(unsigned int id, texture_type type, std::string path)
    : id(id), type(type), path(std::move(path)) {}
