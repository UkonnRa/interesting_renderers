//
// Created by ukonnra on 2020/8/3.
//

#include "mesh.h"

mesh::mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices,
           std::vector<texture> textures)
    : vertices(std::move(vertices)), indices(std::move(indices)),
      textures(std::move(textures)) {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(vertex),
               this->vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               this->indices.size() * sizeof(unsigned int),
               this->indices.data(), GL_STATIC_DRAW);

  // Position
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), nullptr);

  // Normal
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex),
                        (void *)offsetof(vertex, normal));

  // Texture Coord
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex),
                        (void *)offsetof(vertex, texCoords));

  glBindVertexArray(0);
}

void mesh::draw() const {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
  glBindVertexArray(0);
}
