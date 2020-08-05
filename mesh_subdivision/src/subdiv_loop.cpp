//
// Created by ukonnra on 2020/8/5.
//

#include "subdiv_loop.h"
#include <map>

typedef std::tuple<unsigned int, unsigned int> side_pair;
// opposite point index, another opposite point index, new point index
typedef std::tuple<unsigned int, unsigned int, unsigned int> points;
typedef std::map<side_pair, points> cache_map;

std::optional<mesh> subdiv_loop::decrease(std::shared_ptr<mesh> m) {
  if (m->indices.size() % 3 != 0) {
    std::cerr << "All faces should be triangles" << std::endl;
    return std::nullopt;
  }

  const auto faces_count = m->indices.size() / 3;

  cache_map map;

  std::vector<vertex> new_vertices;
  std::vector<unsigned int> new_indices;

  for (int i = 0; i < faces_count; i++) {
    for (int j = 0; j < 3; j++) {
      const auto a = m->indices[i * 3 + j], b = m->indices[i * 3 + (j + 1) % 3];
      const side_pair p {std::min(a, b), std::max(a, b)};
      const auto exist_side = map.find(p);
      if (exist_side != map.end()) {
        // No registered side
        const auto new_v = m->vertices[a].averge(m->vertices[b]);
        new_vertices.push_back(new_v);
      }
    }
  }

  return std::make_optional<mesh>({{}, {}, {}});
}

std::optional<mesh> subdiv_loop::increase(std::shared_ptr<mesh> m) {
  return std::make_optional<mesh>({{}, {}, {}});
}
