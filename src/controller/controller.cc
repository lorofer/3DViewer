#include "controller.h"

s21::Controller::Controller() {
	ShowView();
}

void s21::Controller::ShowView() {
	view_.show();
}

void s21::Controller::SetModelFromFile(std::string file) noexcept {
	model_facade_.SetModelFromFile(file);
	view_.OnModelLoaded();
}

std::shared_ptr<const s21::VertexBuffer::VerticesVector> s21::Controller::GetVertices() const noexcept {
	return model_facade_.GetVertices();
}