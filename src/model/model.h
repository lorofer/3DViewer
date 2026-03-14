#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "wireframe.h"
#include "obj_parser.h"

namespace s21 {
class Model {
	Wireframe wireframe_;
	ObjParser parser_;

public:
	void SetWireframeFromFile(std::string file) noexcept;
	std::vector<float> GetVertexBuffer() const noexcept;
	// std::shared_ptr<const VertexBuffer::VerticesVector> GetVertices() const noexcept;
};
}

#endif