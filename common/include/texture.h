//
// Created by ukonnra on 2020/8/3.
//

#ifndef INTERESTING_RENDERERS_TEXTURE_H
#define INTERESTING_RENDERERS_TEXTURE_H

#include "sharing.h"

enum texture_type { DIFFUSE, SPECULAR };

class texture {
private:
  const unsigned int id;
  const texture_type type;
  const std::string path;

public:
  texture(unsigned int id, texture_type type, std::string path);
};

#endif // INTERESTING_RENDERERS_TEXTURE_H
