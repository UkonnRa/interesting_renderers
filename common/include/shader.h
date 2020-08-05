//
// Created by ukonnra on 2020/8/4.
//

#ifndef INTERESTING_RENDERERS_SHADER_H
#define INTERESTING_RENDERERS_SHADER_H

#include "sharing.h"

class shader {
public:
  int id = -1;

  shader(const std::string &path, unsigned int type);
};

class vert_shader : public shader {
public:
  explicit vert_shader(const std::string &path)
      : shader(path, GL_VERTEX_SHADER) {}
};

class frag_shader : public shader {
public:
  explicit frag_shader(const std::string &path)
      : shader(path, GL_FRAGMENT_SHADER) {}
};

#endif // INTERESTING_RENDERERS_SHADER_H
