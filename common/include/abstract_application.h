//
// Created by ukonnra on 2020/8/4.
//

#ifndef INTERESTING_RENDERERS_ABSTRACT_APPLICATION_H
#define INTERESTING_RENDERERS_ABSTRACT_APPLICATION_H

#include "model.h"
#include "shader_program.h"
#include "sharing.h"

class abstract_application {
public:
  GLFWwindow *window;
  glm::vec3 camera{0, 0, -2};
  float fov = 45.0f;

protected:
  const std::string name;
  size_t width, height;
  std::vector<model> models;
  std::shared_ptr<shader_program> program = nullptr;

public:
  explicit abstract_application(const std::string &name, size_t width,
                                size_t height);
  virtual ~abstract_application();

  void start();
  void addModels(std::vector<model> &ms);
  void setProgram(const std::shared_ptr<shader_program> &program);
  virtual void render() = 0;
  virtual glm::mat4 mvp();
};

#endif // INTERESTING_RENDERERS_ABSTRACT_APPLICATION_H
