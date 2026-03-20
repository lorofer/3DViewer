#include "model.h"

void s21::Model::SetWireframeFromFile(std::string file) noexcept {
  wireframe_ = parser_.ParseObj(file);
}

std::vector<float> s21::Model::GetVertexBuffer() const noexcept {
  return wireframe_.GetVertexBuffer();
}

int s21::Model::GetNumOfVertices() const noexcept {
  return wireframe_.GetNumOfVertices();
}

int s21::Model::GetNumOfEdges() const noexcept {
  return wireframe_.GetNumOfEdges();
}

std::vector<int> s21::Model::GetEdgesBuffer() const noexcept {
  return wireframe_.GetEdgesBuffer();
}