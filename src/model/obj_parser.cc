#include <fstream>
#include <sstream>

#include "obj_parser.h"

s21::Model s21::ObjParser::ParseObj(const std::string filename) noexcept {
	std::ifstream obj_file(filename);

	std::string prefix = "";
	while (obj_file >> prefix) {
		if (prefix == "v") {
			VarticesParsing(obj_file);
		} else if (prefix == "f") {
			FacesParsing(obj_file);
		} else {
			std::string skip = "";
			std::getline(obj_file, skip);
		}
	}

	return model_;
}

void s21::ObjParser::VarticesParsing(std::ifstream& obj_file) noexcept {
	float x, y, z;
	obj_file >> x >> y >> z;
	model_.AddVertex(x, y, z);
}

void s21::ObjParser::FacesParsing(std::ifstream& obj_file) noexcept {
	std::string face_line = "";
	std::getline(obj_file, face_line);

	std::vector<int> vertex_indexes = {};

	std::stringstream ss(face_line);

	std::string vertex_data = "";
	while (ss >> vertex_data) {
		int index = GetVertexFromFaceLine(vertex_data);
		index = IndexOfVerterToPositiveForm(index);
		vertex_indexes.push_back(index - 1);
	}

	model_.AddFace(s21::Face(vertex_indexes));
}

int s21::ObjParser::GetVertexFromFaceLine(std::string& vertex_data) const noexcept {
	int vertex = -1;
	int end_of_vertex = vertex_data.find_first_of("/");

	std::string vertex_srt = vertex_data.substr(0, end_of_vertex);

	vertex = std::stoi(vertex_srt);
	return vertex;
}

int s21::ObjParser::IndexOfVerterToPositiveForm(int index) const noexcept {
	if (index < 0) {
		return model_.GetNumOfVertices() + index + 1;
	}
	return index;
}
