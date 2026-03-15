#include "wireframe_controller_widget.h"

s21::WireframeControllerWidget::WireframeControllerWidget(QWidget *parent) : QWidget(parent) {
	AddMoveSliders();
	AddRotateSliders();
	AddScaleSliders();
	AddChooseFileButton();
	AddChooseFileDialog();

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(move_sliders_);
	layout->addWidget(rotate_sliders_);
	layout->addWidget(scale_slider_);
	layout->addStretch();
	layout->addWidget(choose_file_btn_);
}

void s21::WireframeControllerWidget::AddMoveSliders() {
	move_sliders_ = new SlidersGroup(this, "Move");

	Slider *x = new Slider(move_sliders_, "X");
	Slider *y = new Slider(move_sliders_, "Y");
	Slider *z = new Slider(move_sliders_, "Z");

	x->SetRange(-10, 10);
	x->SetValue(0);

	y->SetRange(-10, 10);
	y->SetValue(0);

	z->SetRange(-10, 10);
	z->SetValue(0);

	move_sliders_->AddSlider(x);
	move_sliders_->AddSlider(y);
	move_sliders_->AddSlider(z);

	move_sliders_->AddStretch();
}

void s21::WireframeControllerWidget::AddRotateSliders() {
	rotate_sliders_ = new SlidersGroup(this, "Rotate");

	Slider *x = new Slider(rotate_sliders_, "X");
	Slider *y = new Slider(rotate_sliders_, "Y");
	Slider *z = new Slider(rotate_sliders_, "Z");

	x->SetRange(-360, 360);
	x->SetValue(0);
	connect(x, SIGNAL(ValueChanged(int)), this, SIGNAL(RotateXChanged(int)));

	y->SetRange(-360, 360);
	y->SetValue(0);
	connect(y, SIGNAL(ValueChanged(int)), this, SIGNAL(RotateYChanged(int)));

	z->SetRange(-360, 360);
	z->SetValue(0);
	connect(z, SIGNAL(ValueChanged(int)), this, SIGNAL(RotateZChanged(int)));

	rotate_sliders_->AddSlider(x);
	rotate_sliders_->AddSlider(y);
	rotate_sliders_->AddSlider(z);

	rotate_sliders_->AddStretch();
}

void s21::WireframeControllerWidget::AddScaleSliders() {
	scale_slider_ = new SlidersGroup(this, "Scale");

	Slider *scale = new Slider(scale_slider_, "-", "+");

	scale->SetRange(-10, 10);
	scale->SetValue(0);

	scale_slider_->AddSlider(scale);

	scale_slider_->AddStretch();
}

void s21::WireframeControllerWidget::AddChooseFileButton() {
	choose_file_btn_ = new QPushButton("Выбрать файл");
	choose_file_btn_->setMinimumHeight(40);
	connect(choose_file_btn_, SIGNAL(clicked()), this, SLOT(OpenChooseFileDialog()));
}

void s21::WireframeControllerWidget::AddChooseFileDialog() {
	choose_file_dialog_ = new QFileDialog(this, "Выберите файл", "", "*.obj");
	choose_file_dialog_->setFileMode(QFileDialog::ExistingFile);
	connect(choose_file_dialog_, SIGNAL(fileSelected(const QString&)), parent(), SLOT(SetWireframeFromFile(const QString&)));
}

void s21::WireframeControllerWidget::OpenChooseFileDialog() {
	choose_file_dialog_->open();
}

// --------------------

s21::SlidersGroup::SlidersGroup(QWidget *parent, QString label) : QWidget(parent) {
	label_ = new QLabel(label);
	layout_ = new QVBoxLayout(this);
	layout_->addWidget(label_);
}

void s21::SlidersGroup::AddSlider(Slider *slider) {
	layout_->addWidget(slider);
}

void s21::SlidersGroup::AddStretch() {
	layout_->addStretch();
}

// --------------------

s21::Slider::Slider(QWidget *parent, QString left_label, QString right_label) : QWidget(parent) {
	left_label_->setText(left_label);
	right_label_->setText(right_label);

	QHBoxLayout *sldr_layout = new QHBoxLayout(this);
	sldr_layout->addWidget(left_label_);
	sldr_layout->addWidget(slider_);
	sldr_layout->addWidget(right_label_);

	connect(slider_, SIGNAL(valueChanged(int)), this, SIGNAL(ValueChanged(int)));
}

void s21::Slider::SetRange(int min, int max) {
	slider_->setRange(min, max);
}

void s21::Slider::SetValue(int value) {
	slider_->setValue(value);
}