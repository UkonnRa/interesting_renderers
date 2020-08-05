//
// Created by ukonnra on 2020/8/3.
//

#ifndef INTERESTING_RENDERERS_MODEL_H
#define INTERESTING_RENDERERS_MODEL_H

#include <utility>

#include "drawable.h"
#include "mesh.h"
#include "sharing.h"

class model : public drawable {
public:
  explicit model(const std::string &path);
  explicit model(std::vector<mesh> meshes) : meshes(std::move(meshes)) {}

  void draw() const override;

private:
  std::vector<mesh> meshes;
  std::string directory;

  void loadModel(const std::string &path);
  void processNode(const aiNode *node, const aiScene *scene);

  mesh processMesh(const aiMesh *rawMesh, const aiScene *rawScene);

  std::vector<texture> loadMaterialTextures(const aiMaterial *m,
                                            aiTextureType type,
                                            texture_type typeName);
};

#endif // INTERESTING_RENDERERS_MODEL_H
