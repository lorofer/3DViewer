#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>
#include <memory>

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLBuffer>

#include "model.h"

namespace s21 {
class MoveSliders;
class RotateSliders;
class SlidersGroup;
class Slider;

// class View : public QMainWindow {
// 	Q_OBJECT
//
// private:
// 	IController *controller_;
// 	std::shared_ptr<const VertexBuffer::VerticesVector> vertex_buffer_;
//
// 	QWidget *central_;
// 	Scene3DWidget *scene_3d_widget_;
// 	ModelManager *model_manager_;
//
// public:
// 	View(IController *c);
// 	void OnModelLoaded();
//
// public slots:
// 	void SetModelFromFile(const QString &file);
// };

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions {
	Q_OBJECT

private:
	// QMatrix4x4 projection_matrix_;
	// QOpenGLBuffer vbo_;
	// QOpenGLBuffer ibo_;
	std::shared_ptr<const VertexBuffer::VerticesVector> vertex_buffer_;

public:
	GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

	void UpdateModel(std::shared_ptr<const VertexBuffer::VerticesVector> vertex_buffer) noexcept;

	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;
};

class ModelManager : public QWidget {
	Q_OBJECT

private:
	SlidersGroup *move_sliders_;
	SlidersGroup *rotate_sliders_;
	SlidersGroup *scale_slider_;
	QPushButton *choose_file_btn_;
	QFileDialog *choose_file_dialog_;

	void AddMoveSliders();
	void AddRotateSliders();
	void AddScaleSliders();
	void AddChooseFileButton();
	void AddChooseFileDialog();

public slots:
	void OpenChooseFileDialog();

public:
	ModelManager(QWidget *parent);
};

class SlidersGroup : public QWidget {
	Q_OBJECT

private:
	QLabel *label_;
	QVBoxLayout *layout_;

public:
	SlidersGroup(QWidget *parent, QString label);
	void AddSlider(Slider *slider);
	void AddStretch();
};

class Slider : public QWidget {
	Q_OBJECT

private:
	QSlider *slider_ = new QSlider(Qt::Horizontal);
	QLabel *left_label_ = new QLabel("");
	QLabel *right_label_ = new QLabel("");

public:
	Slider(QWidget *parent, QString left_label = "", QString right_label = "");
	void SetRange(int min, int max);
	void SetValue(int value);
};
}

#endif