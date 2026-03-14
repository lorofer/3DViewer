#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <string>
#include <memory>

#include "model.h"

namespace s21 {
class IController {
public:
	virtual ~IController() = default;
	virtual void SetModelFromFile(std::string file) noexcept = 0;
	virtual std::shared_ptr<const VertexBuffer::VerticesVector> GetVertices() const noexcept = 0;
};
}

#endif