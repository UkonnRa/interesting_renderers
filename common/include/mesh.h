//
// Created by ukonnra on 2020/8/3.
//

#ifndef INTERESTING_RENDERERS_MESH_H
#define INTERESTING_RENDERERS_MESH_H

#include "drawable.h"
#include "sharing.h"
#include "texture.h"
#include "vertex.h"

class mesh : public drawable {
private:
  const std::vector<vertex> vertices;
  const std::vector<unsigned int> indices;
  const std::vector<texture> textures;
  unsigned int VAO, VBO, EBO;

public:
  mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices,
       std::vector<texture> textures);

  void draw() const override;
};

#endif // INTERESTING_RENDERERS_MESH_H
