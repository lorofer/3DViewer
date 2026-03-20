#include "wireframe.h"

#include <algorithm>

bool s21::Edge::operator<(const Edge& other) const noexcept {
  int min1 = std::min(a, b);
  int max1 = std::max(a, b);
  int min2 = std::min(other.a, other.b);
  int max2 = std::max(other.a, other.b);
  return std::tie(min1, max1) < std::tie(min2, max2);
}

// --------------------

bool s21::Vertex::operator<(const Vertex& other) const noexcept {
  return std::tie(x, y, z) < std::tie(other.x, other.y, other.z);
}

// --------------------

void s21::Wireframe::Clear() noexcept {
  vertices_.clear();
  edges_.clear();
}

void s21::Wireframe::AddVertex(float x, float y, float z) noexcept {
  vertices_.insert(Vertex{x, y, z});
}

int s21::Wireframe::GetNumOfVertices() const noexcept {
  return vertices_.size();
}

std::vector<float> s21::Wireframe::GetVertexBuffer() const noexcept {
  std::vector<float> vbo = {};
  vbo.reserve(vertices_.size() * 3);

  for (const Vertex& vertex : vertices_) {
    vbo.push_back(vertex.x);
    vbo.push_back(vertex.y);
    vbo.push_back(vertex.z);
  }

  return vbo;
}

void s21::Wireframe::AddEdge(int a, int b) noexcept {
  edges_.insert(Edge{a, b});
}

int s21::Wireframe::GetNumOfEdges() const noexcept { return edges_.size(); }

std::vector<int> s21::Wireframe::GetEdgesBuffer() const noexcept {
  std::vector<int> ebo = {};
  ebo.reserve(edges_.size() * 2);

  for (const Edge& edge : edges_) {
    ebo.push_back(edge.a);
    ebo.push_back(edge.b);
  }

  return ebo;
}