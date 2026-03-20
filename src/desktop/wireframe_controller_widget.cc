#include <QFileInfo>

#include "wireframe_controller_widget.h"

s21::WireframeControllerWidget::WireframeControllerWidget(QWidget *parent) : QWidget(parent) {
	AddMoveSliders();
	AddRotateSliders();
	AddScaleSliders();
	AddChooseFileButton();
	AddChooseFileDialog();

	wifeframe_info_ = new WifeframeInfo(this);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(move_sliders_);
	layout->addWidget(rotate_sliders_);
	layout->addWidget(scale_slider_);
	layout->addStretch();
	layout->addWidget(wifeframe_info_);
	layout->addWidget(choose_file_btn_);
}

void s21::WireframeControllerWidget::UpdateWireframeInfo(std::string filename, int vertices_count, int edges_count) {
	wifeframe_info_->UpdateWireframeInfo(filename, vertices_count, edges_count);
}

void s21::WireframeControllerWidget::AddMoveSliders() {
	move_sliders_ = new SlidersGroup(this, "Move");

	Slider *x = new Slider(move_sliders_, "X");
	Slider *y = new Slider(move_sliders_, "Y");
	Slider *z = new Slider(move_sliders_, "Z");

	x->SetRange(-10, 10);
	x->SetValue(0);
	connect(x, SIGNAL(ValueChanged(int)), this, SIGNAL(MoveXChanged(int)));

	y->SetRange(-10, 10);
	y->SetValue(0);
	connect(y, SIGNAL(ValueChanged(int)), this, SIGNAL(MoveYChanged(int)));

	z->SetRange(-10, 10);
	z->SetValue(0);
	connect(z, SIGNAL(ValueChanged(int)), this, SIGNAL(MoveZChanged(int)));

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

	scale->SetRange(1, 19);
	scale->SetValue(10);
	connect(scale, SIGNAL(ValueChanged(int)), this, SIGNAL(ScaleChanged(int)));

	scale_slider_->AddSlider(scale);

	scale_slider_->AddStretch();
}

void s21::WireframeControllerWidget::AddChooseFileButton() {
	choose_file_btn_ = new QPushButton("Choose a model");
	choose_file_btn_->setMinimumHeight(40);
	connect(choose_file_btn_, SIGNAL(clicked()), this, SLOT(OpenChooseFileDialog()));
}

void s21::WireframeControllerWidget::AddChooseFileDialog() {
	choose_file_dialog_ = new QFileDialog(this, "Choose a model", "", "*.obj");
	choose_file_dialog_->setFileMode(QFileDialog::ExistingFile);
	connect(choose_file_dialog_, SIGNAL(fileSelected(const QString&)), parent(), SLOT(SetWireframeFromFile(const QString&)));
}

void s21::WireframeControllerWidget::OpenChooseFileDialog() {
	choose_file_dialog_->open();
}

// --------------------

s21::SlidersGroup::SlidersGroup(QWidget *parent, QString label) : QWidget(parent) {
	label_ = new QLabel(label);

	QFont *font = new QFont();
	font->setPointSize(11);
	label_->setFont(*font);

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

	QFont *font = new QFont();
	font->setPointSize(11);
	left_label_->setFont(*font);
	right_label_->setFont(*font);

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

// --------------------

s21::WifeframeInfo::WifeframeInfo(QWidget *parent) : QWidget(parent) {
	QVBoxLayout *wireframe_info_layout = new QVBoxLayout(this);

	QHBoxLayout *filename_layout = new QHBoxLayout();
	filename_layout->addWidget(filename_label_);
	filename_layout->addWidget(filename_value_);

	QHBoxLayout *vertices_layout = new QHBoxLayout();
	vertices_layout->addWidget(vertices_label_);
	vertices_layout->addWidget(vertices_value_);

	QHBoxLayout *edges_layout = new QHBoxLayout();
	edges_layout->addWidget(edges_label_);
	edges_layout->addWidget(edges_value_);

	wireframe_info_layout->addLayout(filename_layout);
	wireframe_info_layout->addLayout(vertices_layout);
	wireframe_info_layout->addLayout(edges_layout);
}

void s21::WifeframeInfo::UpdateWireframeInfo(std::string filename, int vertices_count, int edges_count) {
	// QString qfilename = QString::fromStdString(filename);
	QFileInfo file_info(QString::fromStdString(filename));

	filename_value_->setText(file_info.fileName());
	vertices_value_->setText(QString::number(vertices_count));
	edges_value_->setText(QString::number(edges_count));
}