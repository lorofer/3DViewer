#ifndef MODEL_FACADE_H
#define MODEL_FACADE_H

#include "model.h"
#include "obj_parser.h"

namespace s21 {
class ModelFacade {
	Model model_;
	ObjParser parser_;

public:
	void SetModelFromFile(std::string file) noexcept;
	std::shared_ptr<const VertexBuffer::VerticesVector> GetVertices() const noexcept;
};
}

#endif