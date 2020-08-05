//
// Created by ukonnra on 2020/8/5.
//

#ifndef INTERESTING_RENDERERS_SUBDIV_H
#define INTERESTING_RENDERERS_SUBDIV_H

#include <mesh.h>
#include <sharing.h>
#include <optional>

class subdiv {
public:
  virtual std::optional<mesh> increase(std::shared_ptr<mesh> m) = 0;
  virtual std::optional<mesh> decrease(std::shared_ptr<mesh> m) = 0;
};

#endif // INTERESTING_RENDERERS_SUBDIV_H
