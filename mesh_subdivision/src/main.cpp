//
// Created by ukonnra on 2020/8/3.
//

#include <abstract_application.h>
#include <application.h>
#include <model.h>
#include <shader.h>
#include <shader_program.h>

std::shared_ptr<application> app;

void onKey(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (action == GLFW_PRESS) {
    if (key == GLFW_KEY_ESCAPE) {
      glfwSetWindowShouldClose(window, true);
    } else if (key == GLFW_KEY_W) {
      app->camera += glm::vec3{0, -1, 0};
    } else if (key == GLFW_KEY_S) {
      app->camera += glm::vec3{0, 1, 0};
    } else if (key == GLFW_KEY_Q) {
      app->rotating = !app->rotating;
    }
  }
}

void onScroll(GLFWwindow* window, double xoffset, double yoffset) {
  if (yoffset > 0) {
    app->fov = std::max(app->fov - 5, 20.0f);
  } else if (yoffset < 0) {
    app->fov = std::min(app->fov + 5, 120.0f);
  }
}

int main() {
  app = std::make_shared<application>("mesh_subdivision", 800, 600);
  glfwSetKeyCallback(app->window, onKey);
  glfwSetScrollCallback(app->window, onScroll);

  std::vector<std::shared_ptr<shader>> shaders{
      std::make_shared<vert_shader>("./shaders/stable-position.vert"),
      std::make_shared<frag_shader>("./shaders/pure-color.frag"),
  };

  auto models = std::vector<model>{
      model("model/bunny/bunny.obj"),
  };

  app->addModels(models);
  app->setProgram(std::make_shared<shader_program>(shaders));

  app->start();
  std::cout << "hello" << std::endl;
}