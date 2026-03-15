#include <GL/glu.h>

#include "wireframe_widget.h"

void s21::WireframeWidget::initializeGL() {
	initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void s21::WireframeWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect = (float)width / (float)height;
	float fov = 45.0f;
	float nearPlane = 0.1f;
	float farPlane = 100.0f;

	gluPerspective(fov, aspect, nearPlane, farPlane);

	glMatrixMode(GL_MODELVIEW);
}

void s21::WireframeWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (vbo_data_.empty() || ebo_data_.empty()) {
		return;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -5.0f);

	glRotatef(rotate_x_, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate_y_, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate_z_, 0.0f, 0.0f, 1.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vbo_data_.data());

	glColor3f(0.5f, 0.5f, 1.0f);
	glDrawElements(GL_LINES, ebo_data_.size(), GL_UNSIGNED_INT, ebo_data_.data());

	glDisableClientState(GL_VERTEX_ARRAY);
}

void s21::WireframeWidget::UpdateModel(std::vector<float> new_vbo, std::vector<int> new_ebo) noexcept {
	vbo_data_ = std::move(new_vbo);
	ebo_data_ = std::move(new_ebo);
	update();
}

void s21::WireframeWidget::RotateX(int value) {
	rotate_x_ = (float)value;
	update();
}

void s21::WireframeWidget::RotateY(int value) {
	rotate_y_ = (float)value;
	update();
}

void s21::WireframeWidget::RotateZ(int value) {
	rotate_z_ = (float)value;
	update();
}