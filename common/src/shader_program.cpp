//
// Created by ukonnra on 2020/8/4.
//

#include "shader_program.h"

shader_program::shader_program(
    const std::vector<std::shared_ptr<shader>> &shaders) {
  int success;
  char infoLog[512];

  const auto rawId = glCreateProgram();
  for (const auto &s : shaders) {
    glAttachShader(rawId, s->id);
  }
  glLinkProgram(rawId);
  glGetProgramiv(rawId, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(rawId, 512, nullptr, infoLog);
    std::cerr << "ERROR::SHADER::PROGRAM::LINK_FAILED\n"
              << infoLog << std::endl;
    return;
  }

  for (const auto &s : shaders) {
    glDeleteShader(s->id);
  }

  this->id = rawId;
}
