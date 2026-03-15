#ifndef WIREFRAME_H
#define WIREFRAME_H

#include <set>
#include <vector>

namespace s21 {
struct Vertex {
	float x, y, z;
	bool operator<(const Vertex& other) const noexcept;
};

struct Edge {
	int a, b;
	bool operator<(const Edge& other) const noexcept;
};

class Wireframe {
	std::set<Vertex> vertices_ = {};
	std::set<Edge> edges_ = {};

public:
	void Clear() noexcept;

	void AddVertex(float x, float y, float z) noexcept;
	int GetNumOfVertices() const noexcept;
	std::vector<float> GetVertexBuffer() const noexcept;

	void AddEdge(int a, int b) noexcept;
	std::vector<int> GetEdgesBuffer() const noexcept;
};
}

#endif