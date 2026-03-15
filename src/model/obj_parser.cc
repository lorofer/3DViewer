#include <fstream>
#include <sstream>

#include "obj_parser.h"

s21::Wireframe s21::ObjParser::ParseObj(const std::string filename) noexcept {
	wireframe_.Clear();

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

	return wireframe_;
}

void s21::ObjParser::VarticesParsing(std::ifstream& obj_file) noexcept {
	float x, y, z;
	obj_file >> x >> y >> z;
	wireframe_.AddVertex(x, y, z);
}

void s21::ObjParser::FacesParsing(std::ifstream& obj_file) noexcept {
	std::string face_line = "";
	std::getline(obj_file, face_line);

	std::vector<int> vertex_indexes = {};

	std::stringstream ss(face_line);

	bool is_first = true;
	int first = -1;
	int prev = -1;

	std::string vertex_data = "";
	while (ss >> vertex_data) {
		int curr = GetIndexFromFaceLine(vertex_data);
		curr = IndexOfVerterToPositiveForm(curr);
		curr--;

		if (is_first) {
			first = prev = curr;
			is_first = false;
			continue;
		}

		wireframe_.AddEdge(prev, curr);
		prev = curr;
	}

	wireframe_.AddEdge(prev, first);
}

int s21::ObjParser::GetIndexFromFaceLine(std::string& vertex_data) const noexcept {
	int vertex = -1;
	int end_of_vertex = vertex_data.find_first_of("/");

	std::string vertex_srt = vertex_data.substr(0, end_of_vertex);

	vertex = std::stoi(vertex_srt);
	return vertex;
}

int s21::ObjParser::IndexOfVerterToPositiveForm(int index) const noexcept {
	if (index < 0) {
		return wireframe_.GetNumOfVertices() + index + 1;
	}
	return index;
}
