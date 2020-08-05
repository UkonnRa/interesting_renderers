//
// Created by ukonnra on 2020/8/3.
//

#include "vertex.h"

vertex::vertex(const glm::vec3 &position, const glm::vec3 &normal,
               const glm::vec2 &texCoords)
    : position(position), normal(normal),
      texCoords(texCoords) {}