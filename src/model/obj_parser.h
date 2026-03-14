#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <string>

#include "model.h"

namespace s21 {
class ObjParser {
	Model model_;

public:
	Model ParseObj(const std::string filename) noexcept;

private:
	void VarticesParsing(std::ifstream& obj_file) noexcept;

	void FacesParsing(std::ifstream& obj_file) noexcept;
	int GetVertexFromFaceLine(std::string& vertex_data) const noexcept;
	int IndexOfVerterToPositiveForm(int index) const noexcept;
};
}

#endif