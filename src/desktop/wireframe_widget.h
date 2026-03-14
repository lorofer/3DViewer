#ifndef WIREFRAME_WIDGET_H
#define WIREFRAME_WIDGET_H

#include <vector>

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLBuffer>

namespace s21 {
class WireframeWidget : public QOpenGLWidget, public QOpenGLFunctions {
	Q_OBJECT

private:
	std::vector<float> vbo_data_ = {};
	std::vector<int> ebo_data_ = {};
	// QOpenGLBuffer vbo_ = {};
    // QOpenGLBuffer ebo_ = {};
	// int index_count_ = 0;

public:
	WireframeWidget(QWidget *parent) : QOpenGLWidget(parent) {}

	void initializeGL() override;
	void resizeGL(int width, int height) override;
	void paintGL() override;

	void UpdateModel(std::vector<float> new_vbo, std::vector<int> new_ebo) noexcept;
};
}

#endif