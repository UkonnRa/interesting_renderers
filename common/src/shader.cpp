//
// Created by ukonnra on 2020/8/4.
//

#include "shader.h"

shader::shader(const std::string &path, unsigned int type) {
  int success;
  char infoLog[512];

  std::ifstream f(path);
  auto rawShader = std::string((std::istreambuf_iterator<char>(f)),
                               std::istreambuf_iterator<char>());
  auto rawPtr = rawShader.data();

  auto rawId = glCreateShader(type);
  glShaderSource(rawId, 1, &rawPtr, nullptr);
  glCompileShader(rawId);
  glGetShaderiv(rawId, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(rawId, 512, nullptr, infoLog);
    std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    return;
  }

  this->id = rawId;
}
