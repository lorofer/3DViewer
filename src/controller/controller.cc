#include "controller.h"

s21::Controller::Controller() {
	ShowView();
}

void s21::Controller::ShowView() {
	view_.show();
}

void s21::Controller::SetWireframeFromFile(std::string file) noexcept {
	model_.SetWireframeFromFile(file);
	view_.OnModelLoaded();
}

std::vector<float> s21::Controller::GetVertexBuffer() const noexcept {
	// vbo_ = model_.GetVertexBuffer();
	// return vbo_;
	return model_.GetVertexBuffer();
}