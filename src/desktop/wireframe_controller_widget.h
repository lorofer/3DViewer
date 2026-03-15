#ifndef DESKTOP_H
#define DESKTOP_H

#include <QtWidgets>

namespace s21 {
class SlidersGroup;
class Slider;

class WireframeControllerWidget : public QWidget {
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

public:
	WireframeControllerWidget(QWidget *parent);

public slots:
	void OpenChooseFileDialog();

signals:
	void MoveXChanged(int value);
	void MoveYChanged(int value);
	void MoveZChanged(int value);

	void RotateXChanged(int value);
	void RotateYChanged(int value);
	void RotateZChanged(int value);
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

signals:
    void ValueChanged(int value);
};
}

#endif