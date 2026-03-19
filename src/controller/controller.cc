#include "controller.h"

s21::Controller::Controller() {
	ShowView();
}

void s21::Controller::ShowView() {
	view_.show();
}

void s21::Controller::SetWireframeFromFile(std::string file) noexcept {
	model_.SetWireframeFromFile(file);
	view_.OnModelLoaded(file);
}

std::vector<float> s21::Controller::GetVertexBuffer() const noexcept {
	return model_.GetVertexBuffer();
}

std::vector<int> s21::Controller::GetEdgesBuffer() const noexcept {
	return model_.GetEdgesBuffer();
}

int s21::Controller::GetNumOfVertices() const noexcept {
	return model_.GetNumOfVertices();
}

int s21::Controller::GetNumOfEdges() const noexcept {
	return model_.GetNumOfEdges();
}
