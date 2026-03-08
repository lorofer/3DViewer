#include "model.h"

void Model::AddVertex(Vertex v) noexcept {
	vertices_.push_back(v);
}

int Model::GetNumOfVertices() const noexcept {
	return vertices_.size();
}

void Model::AddFace(Face f) noexcept {
	faces_.push_back(f);
}