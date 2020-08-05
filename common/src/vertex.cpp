//
// Created by ukonnra on 2020/8/3.
//

#include "vertex.h"

vertex::vertex(const glm::vec3 &position, const glm::vec3 &normal,
               const glm::vec2 &texCoords)
    : position(position), normal(normal), texCoords(texCoords) {}

[[nodiscard]] vertex vertex::averge(const vertex &v) const {
  return {
      (this->position + v.position) / 2.0f,
      (this->normal + v.normal) / 2.0f,
      (this->texCoords + v.texCoords) / 2.0f,
  };
}
