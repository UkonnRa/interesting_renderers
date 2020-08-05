//
// Created by ukonnra on 2020/8/4.
//

#include <utility>
#include "abstract_application.h"

abstract_application::abstract_application(const std::string &name,
                                           size_t width, size_t height)
    : name(name), width(width), height(height) {
  if (!glfwInit()) {
    std::cerr << "Failed to init GLFW" << std::endl;
    return;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    return;
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return;
  }
  glViewport(0, 0, width, height);
}

abstract_application::~abstract_application() {
  if (program != nullptr) {
    glDeleteProgram(program->id);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

void abstract_application::start() {
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(program->id);

    auto mvp = this->mvp();
    auto uniformMVP = glGetUniformLocation(program->id, "MVP");
    glUniformMatrix4fv(uniformMVP, 1, GL_FALSE, &mvp[0][0]);

    render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void abstract_application::addModels(std::vector<model> &ms) {
  for (const auto &m : ms) {
    this->models.push_back(m);
  }
}

void abstract_application::setProgram(
    const std::shared_ptr<shader_program> &p) {
  this->program = p;
}

glm::mat4 abstract_application::mvp() {
  glm::mat4 model(1.0f);
  auto view = glm::lookAt(camera, {0, 0, 0}, {0, 1, 0});
  auto projection = glm::perspective(glm::radians(fov), float(width) / height, 0.1f, 100.0f);
  return projection * view * model;
}
