#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <string>

#include "model.h"

class ObjParser {
	Model model_;

public:
	void ParseObj(const std::string filename) noexcept;

private:
	void VarticesParsing(std::ifstream& obj_file) noexcept;

	void FacesParsing(std::ifstream& obj_file) noexcept;
	int GetVertexFromFaceLine(std::string& vertex_data) const noexcept;
	int IndexOfVerterToPositiveForm(int index) const noexcept;
};

#endif