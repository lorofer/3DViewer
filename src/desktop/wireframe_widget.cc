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
    // Симметричная проекция
    glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, 0.1f, 10.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Отодвигаем камеру
    glTranslatef(0, 0, -5);
}

void s21::WireframeWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (vbo_data_.empty() || ebo_data_.empty()) return;
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vbo_data_.data());
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glDrawElements(GL_LINES, ebo_data_.size(), GL_UNSIGNED_INT, ebo_data_.data());
    
    glDisableClientState(GL_VERTEX_ARRAY);
}

void s21::WireframeWidget::UpdateModel(std::vector<float> new_vbo, std::vector<int> new_ebo) noexcept {
	vbo_data_ = std::move(new_vbo);
	ebo_data_ = std::move(new_ebo);
	update();
}