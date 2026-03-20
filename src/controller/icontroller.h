#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <memory>
#include <string>

#include "wireframe.h"

namespace s21 {
class IController {
 public:
  virtual ~IController() = default;

  virtual void SetWireframeFromFile(std::string file) noexcept = 0;

  virtual std::vector<float> GetVertexBuffer() const noexcept = 0;
  virtual std::vector<int> GetEdgesBuffer() const noexcept = 0;

  virtual int GetNumOfVertices() const noexcept = 0;
  virtual int GetNumOfEdges() const noexcept = 0;
};
}  // namespace s21

#endif