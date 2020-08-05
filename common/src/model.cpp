//
// Created by ukonnra on 2020/8/3.
//

#include "model.h"

model::model(const std::string &path) { loadModel(path); }

void model::loadModel(const std::string &path) {
  Importer importer;
  const auto scene = importer.ReadFile(
      path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

  if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
      !scene->mRootNode) {
    std::cerr << "Error when loading model: " << importer.GetErrorString()
              << std::endl;
    return;
  }

  directory = path.substr(0, path.find_last_of('/'));

  processNode(scene->mRootNode, scene);
}

void model::draw() const {
  for (const auto &m : meshes) {
    m.draw();
  }
}

void model::processNode(const aiNode *node, const aiScene *scene) {
  for (unsigned int i = 0; i < node->mNumMeshes; i++) {
    auto mesh = scene->mMeshes[node->mMeshes[i]];
    meshes.push_back(processMesh(mesh, scene));
  }

  for (unsigned int i = 0; i < node->mNumChildren; i++) {
    processNode(node->mChildren[i], scene);
  }
}

std::vector<texture> model::loadMaterialTextures(const aiMaterial *m,
                                                 aiTextureType type,
                                                 texture_type typeName) {
  std::vector<texture> textures;
  for (auto i = 0; i < m->GetTextureCount(type); i++) {
    aiString path;
    m->GetTexture(type, i, &path);
    auto id = genTextureFromFile(path.C_Str(), directory);
    textures.emplace_back(id, typeName, path.C_Str());
  }
  return textures;
}

mesh model::processMesh(const aiMesh *m, const aiScene *s) {
  std::vector<vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<texture> textures;

  for (unsigned int i = 0; i < m->mNumVertices; ++i) {
    const auto v = m->mVertices[i];
    const auto n = m->mNormals[i];

    glm::vec2 tc{0, 0};
    if (m->mTextureCoords[0]) {
      tc.x = m->mTextureCoords[0][i].x;
      tc.y = m->mTextureCoords[0][i].y;
    }

    vertices.emplace_back(glm::vec3{v.x, v.y, v.z}, glm::vec3{n.x, n.y, n.z}, tc);
  }

  for (unsigned int i = 0; i < m->mNumFaces; i++) {
    const auto face = m->mFaces[i];
    for (auto j = 0; j < face.mNumIndices; j++) {
      indices.push_back(face.mIndices[j]);
    }
  }

  if (m->mMaterialIndex >= 0) {
    auto material = s->mMaterials[m->mMaterialIndex];
  }

  return {vertices, indices, textures};
}