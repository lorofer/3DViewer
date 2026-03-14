#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>

namespace s21 {
class VertexBuffer {
public:
	using VerticesVector = std::vector<float>;

private:
	std::shared_ptr<VerticesVector> vertex_buffer_ = std::make_shared<VerticesVector>();
	size_t size_ = 0;

public:
	void AddVertex(float x, float y, float z) noexcept;
	std::shared_ptr<const VerticesVector> GetVertices() const noexcept;
	int GetSize() const noexcept;
};

class Face {
	std::vector<int> vertex_indexes_;
public:
	Face(std::vector<int> v) noexcept : vertex_indexes_(v) {}
};

class Model {
	VertexBuffer vertices_;
	std::vector<Face> faces_ = {};

public:
	void AddVertex(float x, float y, float z) noexcept;
	std::shared_ptr<const VertexBuffer::VerticesVector> GetVertices() const noexcept;
	int GetNumOfVertices() const noexcept;

	void AddFace(Face f) noexcept;
};
}

#endif