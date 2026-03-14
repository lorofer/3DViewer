#include "wireframe.h"

void s21::Wireframe::AddVertex(float x, float y, float z) noexcept {
	vertices_.push_back(Vertex{x, y, z});
}

// std::shared_ptr<const s21::VertexBuffer::VerticesVector> s21::Model::GetVertices() const noexcept {
// 	return vertices_.GetVertices();
// }

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

void s21::Wireframe::AddFace(Face f) noexcept {
	faces_.push_back(f);
}