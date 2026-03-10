#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>

#include <QtWidgets>
#include <QOpenGLWidget>

namespace s21 {
class WireframeModelWidget;
class ModelManager;
class MoveSliders;
class RotateSliders;
class SlidersGroup;
class Slider;

class MainWin : public QMainWindow {
	Q_OBJECT

private:
	QWidget *central_ = new QWidget();
	WireframeModelWidget *wf_model_;
	ModelManager *model_manager_;

public:
	MainWin();

};

class WireframeModelWidget : public QOpenGLWidget {
	Q_OBJECT

public:
	WireframeModelWidget(QWidget *parent);
};

class ModelManager : public QWidget {
	Q_OBJECT

private:
	SlidersGroup *move_sliders_;
	SlidersGroup *rotate_sliders_;
	SlidersGroup *scale_slider_;

	void AddMoveSliders();
	void AddRotateSliders();
	void AddScaleSliders();

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