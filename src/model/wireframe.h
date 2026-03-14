#ifndef WIREFRAME_H
#define WIREFRAME_H

#include <vector>
#include <memory>

namespace s21 {
struct Vertex {
	float x, y, z;
};

class Face {
	std::vector<int> vertex_indexes_;
public:
	Face(std::vector<int> v) noexcept : vertex_indexes_(v) {}
};

class Wireframe {
	// VertexBuffer vertices_;
	std::vector<Vertex> vertices_ = {};
	std::vector<Face> faces_ = {};

public:
	void AddVertex(float x, float y, float z) noexcept;
	// std::shared_ptr<const VertexBuffer::VerticesVector> GetVertices() const noexcept;
	int GetNumOfVertices() const noexcept;
	std::vector<float> GetVertexBuffer() const noexcept;

	void AddFace(Face f) noexcept;
};
}

#endif