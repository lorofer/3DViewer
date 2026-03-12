#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>

// struct Vertex {
// 	float x, y, z;
// };

class Vertices {
public:
	using VerticesVector = std::vector<float>;

private:
	std::shared_ptr<VerticesVector> vertices_ = std::make_shared<VerticesVector>();

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
	Vertices vertices_;
	std::vector<Face> faces_ = {};

public:
	void AddVertex(float x, float y, float z) noexcept;
	std::shared_ptr<const Vertices::VerticesVector> GetVertices() const noexcept;
	int GetNumOfVertices() const noexcept;

	void AddFace(Face f) noexcept;
};

#endif