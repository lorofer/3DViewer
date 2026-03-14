#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <string>
#include <memory>

#include "wireframe.h"

namespace s21 {
class IController {
public:
	virtual ~IController() = default;
	virtual void SetWireframeFromFile(std::string file) noexcept = 0;
	virtual std::vector<float> GetVertexBuffer() const noexcept = 0;
	virtual std::vector<int> GetEdgesBuffer() const noexcept = 0;
};
}

#endif