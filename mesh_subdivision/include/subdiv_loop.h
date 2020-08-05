//
// Created by ukonnra on 2020/8/5.
//

#ifndef INTERESTING_RENDERERS_SUBDIV_LOOP_H
#define INTERESTING_RENDERERS_SUBDIV_LOOP_H

#include "subdiv.h"

class subdiv_loop: public subdiv {
public:
  std::optional<mesh> decrease(std::shared_ptr<mesh> m) override;
  std::optional<mesh> increase(std::shared_ptr<mesh> m) override;
  // Say N triangles, then indices are 3N
  // Return a mapping of
  std::vector<int> extract_adjacent_triangle(const std::vector<unsigned int>& indices) const;
};

#endif // INTERESTING_RENDERERS_SUBDIV_LOOP_H
