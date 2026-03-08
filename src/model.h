#ifndef MODEL_H
#define MODEL_H

#include <vector>

class Vertex {
	float x_, y_, z_;
public:
	Vertex(float x, float y, float z) noexcept : x_(x), y_(y), z_(z) {}
};

class Face {
	std::vector<int> vertex_indexes_;
public:
	Face(std::vector<int> v) noexcept : vertex_indexes_(v) {}
};

class Model {
	std::vector<Vertex> vertices_;
	std::vector<Face> faces_;

public:
	void AddVertex(Vertex v) noexcept;
	int GetNumOfVertices() const noexcept;

	void AddFace(Face f) noexcept;
};

#endif