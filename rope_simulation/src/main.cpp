//
// Created by ukonnra on 2020/8/3.
//

#include "sharing.h"
#include <iostream>

void printMat(const glm::mat3& m) {
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "=========" << std::endl;
}

int main() {
  auto m = glm::mat3(1.0f);
  printMat(m);
  glm::mat3 m1;
  printMat(m1);
  glm::mat3 m2(2.0f);
  printMat(m2);
}
