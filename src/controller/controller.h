#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "icontroller.h"
#include "model.h"
#include "view.h"

namespace s21 {
class Controller : public IController {
	s21::Model model_ = {};
	s21::View view_ = {this};

public:
	Controller();

private:
	void ShowView();

public:
	void SetWireframeFromFile(std::string file) noexcept override;

	std::vector<float> GetVertexBuffer() const noexcept override;
	std::vector<int> GetEdgesBuffer() const noexcept override;

	int GetNumOfVertices() const noexcept override;
	int GetNumOfEdges() const noexcept override;
};
}

#endif