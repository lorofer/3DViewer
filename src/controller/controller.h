#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "icontroller.h"
#include "model_facade.h"
#include "view.h"

namespace s21 {
class Controller : public IController {
	s21::ModelFacade model_facade_ = {};
	s21::View view_ = {this};

public:
	Controller();

private:
	void ShowView();

public:
	void SetModelFromFile(std::string file) noexcept override;
	std::shared_ptr<const VertexBuffer::VerticesVector> GetVertices() const noexcept override;
};
}

#endif