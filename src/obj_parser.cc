#include <fstream>
#include <sstream>

#include "obj_parser.h"

void ObjParser::ParseObj(const std::string filename) noexcept {
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
}

void ObjParser::VarticesParsing(std::ifstream& obj_file) noexcept {
	float x, y, z;
	obj_file >> x >> y >> z;
	model_.AddVertex(Vertex(x, y, z));
}

void ObjParser::FacesParsing(std::ifstream& obj_file) noexcept {
	std::string face_line = "";
	std::getline(obj_file, face_line);

	std::vector<int> vertex_indexes = {};

	std::stringstream ss(face_line);

	std::string vertex_data = "";
	while (ss >> vertex_data) {
		int index = GetVertexFromFaceLine(vertex_data);
		index = IndexOfVerterToPositiveForm(index);
		vertex_indexes.push_back(index);
	}

	model_.AddFace(Face(vertex_indexes));
}

int ObjParser::GetVertexFromFaceLine(std::string& vertex_data) const noexcept {
	int vertex = -1;
	int end_of_vertex = vertex_data.find_first_of("/");

	std::string vertex_srt = vertex_data.substr(0, end_of_vertex);

	vertex = std::stoi(vertex_srt);
	return vertex;
}

int ObjParser::IndexOfVerterToPositiveForm(int index) const noexcept {
	if (index < 0) {
		return model_.GetNumOfVertices() + index + 1;
	}
	return index;
}
