//
// Created by ukonnra on 2020/8/4.
//

#ifndef INTERESTING_RENDERERS_SHADER_PROGRAM_H
#define INTERESTING_RENDERERS_SHADER_PROGRAM_H

#include "shader.h"
#include "sharing.h"

class shader_program {
public:
  int id = -1;

  explicit shader_program(const std::vector<std::shared_ptr<shader>> &shaders);
};

#endif // INTERESTING_RENDERERS_SHADER_PROGRAM_H
