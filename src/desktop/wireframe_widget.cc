#include "wireframe_widget.h"

void s21::WireframeWidget::initializeGL() {
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void s21::WireframeWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);

    QMatrix4x4 projection;
    projection.perspective(45.0f, (float)width/height, 0.1f, 100.0f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixf(projection.constData());
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void s21::WireframeWidget::paintGL() {
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// if (!vertex_buffer_) {
	// 	return;
	// }

	// glLoadIdentity();
    // glTranslatef(0, 0, -5);

	// glEnableClientState(GL_VERTEX_ARRAY);

	// glVertexPointer(3, GL_FLOAT, 0, vertex_buffer_->data());
	// glColor3f(1.0f, 1.0f, 1.0f);
	// glDrawArrays(GL_TRIANGLES, 0, vertex_buffer_->size() / 3);

	// glDisableClientState(GL_VERTEX_ARRAY);
}

void s21::WireframeWidget::UpdateModel(std::vector<float> new_vbo) noexcept {
	vbo_ = std::move(new_vbo);
	update();
}