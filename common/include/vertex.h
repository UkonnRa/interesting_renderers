//
// Created by ukonnra on 2020/8/3.
//

#ifndef INTERESTING_RENDERERS_VERTEX_H
#define INTERESTING_RENDERERS_VERTEX_H

#include "sharing.h"

class vertex {
public:
  const glm::vec3 position, normal;
  const glm::vec2 texCoords;

  vertex(const glm::vec3 &position, const glm::vec3 &normal,
         const glm::vec2 &texCoords);

  [[nodiscard]] vertex averge(const vertex& v) const;
};

#endif // INTERESTING_RENDERERS_VERTEX_H
