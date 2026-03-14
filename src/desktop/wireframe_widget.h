#ifndef WIREFRAME_WIDGET_H
#define WIREFRAME_WIDGET_H

#include <vector>

#include <QtWidgets>
#include <QOpenGLWidget>

namespace s21 {
class WireframeWidget : public QOpenGLWidget, public QOpenGLFunctions {
	Q_OBJECT

private:
	std::vector<float> vbo_ = {};

public:
	WireframeWidget(QWidget *parent) : QOpenGLWidget(parent) {}

	void initializeGL() override;
	void resizeGL(int width, int height) override;
	void paintGL() override;

	void UpdateModel(std::vector<float> new_vbo) noexcept;
};
}

#endif