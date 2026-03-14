#include "model.h"

void s21::VertexBuffer::AddVertex(float x, float y, float z) noexcept {
	vertex_buffer_->push_back(x);
	vertex_buffer_->push_back(y);
	vertex_buffer_->push_back(z);
	size_++;
}

std::shared_ptr<const typename s21::VertexBuffer::VerticesVector> s21::VertexBuffer::GetVertices() const noexcept {
	return vertex_buffer_;
}

int s21::VertexBuffer::GetSize() const noexcept {
	return vertex_buffer_->size();
}

// --------------------

void s21::Model::AddVertex(float x, float y, float z) noexcept {
	vertices_.AddVertex(x, y, z);
}

std::shared_ptr<const s21::VertexBuffer::VerticesVector> s21::Model::GetVertices() const noexcept {
	return vertices_.GetVertices();
}

int s21::Model::GetNumOfVertices() const noexcept {
	return vertices_.GetSize();
}

void s21::Model::AddFace(Face f) noexcept {
	faces_.push_back(f);
}