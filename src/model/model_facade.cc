#include "model_facade.h"

void s21::ModelFacade::SetModelFromFile(std::string file) noexcept {
	model_ = parser_.ParseObj(file);
}

std::shared_ptr<const s21::VertexBuffer::VerticesVector> s21::ModelFacade::GetVertices() const noexcept {
	return model_.GetVertices();
}