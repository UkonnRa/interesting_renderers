//
// Created by ukonnra on 2020/8/4.
//

#include "application.h"

#include <utility>
void application::render() {
  for (const auto &m : models) {
    m.draw();
  }
}



application::application(const std::string &name, size_t width, size_t height)
    : abstract_application(name, width, height) {
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  previous_time = glfwGetTime();
}
glm::mat4 application::mvp() {
  auto current_time = glfwGetTime();

  if (this->rotating) {
    this->rotating_degree += .5 * (current_time - previous_time);
    previous_time = current_time;
  }

  glm::mat4 rotate = {
      std::sin(this->rotating_degree), 0, std::cos(this->rotating_degree),  0, 0, 1, 0, 0,
      std::cos(this->rotating_degree), 0, -std::sin(this->rotating_degree), 0, 0, 0, 0, 1,
  };

  glm::mat4 scale {
      4, 0, 0, 0,
      0, 4, 0, 0,
      0, 0, 4, 0,
      0, 0, 0, 1,
  };

  glm::mat4 translate {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, -0.1, 0, 1,
  };

  auto model =  rotate * scale * translate;
  auto view = glm::lookAt(camera, {0, 0, 0}, {0, 1, 0});
  auto projection = glm::perspective(glm::radians(fov), float(width) / height, 0.1f, 100.0f);
  return projection * view * model;
}
