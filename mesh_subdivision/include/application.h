//
// Created by ukonnra on 2020/8/4.
//

#ifndef INTERESTING_RENDERERS_APPLICATION_H
#define INTERESTING_RENDERERS_APPLICATION_H

#include <abstract_application.h>

class application : public abstract_application {
public:
  bool rotating = true;
  double rotating_degree = 0.0;

  application(const std::string &name, size_t width, size_t height);
  void render() override;
  glm::mat4 mvp() override;

private:
  double previous_time;
};

#endif // INTERESTING_RENDERERS_APPLICATION_H
