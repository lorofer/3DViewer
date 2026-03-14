#include "model.h"

void s21::Model::SetWireframeFromFile(std::string file) noexcept {
	wireframe_ = parser_.ParseObj(file);
}

std::vector<float> s21::Model::GetVertexBuffer() const noexcept {
	return wireframe_.GetVertexBuffer();
}

std::vector<int> s21::Model::GetEdgesBuffer() const noexcept {
	return wireframe_.GetEdgesBuffer();
}