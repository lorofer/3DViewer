#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "obj_parser.h"
#include "wireframe.h"

namespace s21 {
class Model {
  Wireframe wireframe_;
  ObjParser parser_;

 public:
  void SetWireframeFromFile(std::string file) noexcept;

  std::vector<float> GetVertexBuffer() const noexcept;
  int GetNumOfVertices() const noexcept;

  std::vector<int> GetEdgesBuffer() const noexcept;
  int GetNumOfEdges() const noexcept;
};
}  // namespace s21

#endif