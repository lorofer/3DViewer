#include "model.h"

void Vertices::AddVertex(float x, float y, float z) noexcept {
	vertices_->push_back(x);
	vertices_->push_back(y);
	vertices_->push_back(z);
}

std::shared_ptr<const typename Vertices::VerticesVector> Vertices::GetVertices() const noexcept {
	return vertices_;
}

int Vertices::GetSize() const noexcept {
	return vertices_->size();
}

// --------------------

void Model::AddVertex(float x, float y, float z) noexcept {
	vertices_.AddVertex(x, y, z);
}

std::shared_ptr<const Vertices::VerticesVector> Model::GetVertices() const noexcept {
	return vertices_.GetVertices();
}

int Model::GetNumOfVertices() const noexcept {
	return vertices_.GetSize();
}

void Model::AddFace(Face f) noexcept {
	faces_.push_back(f);
}