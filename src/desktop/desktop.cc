#include "desktop.h"

s21::MainWin::MainWin() {
	setWindowTitle("3DViewer v2.0");
	setFixedSize(1280, 720);

	setCentralWidget(central_);

	scene_3d_widget_ = new Scene3DWidget(this);
	model_manager_ = new ModelManager(this);

	QHBoxLayout *container = new QHBoxLayout(central_);
	container->addWidget(scene_3d_widget_, 2);
	container->addWidget(model_manager_, 1);
}

// --------------------

void s21::Scene3DWidget::initializeGL() {
	vbo_.create();
	vbo_.bind();
	vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);

}

void s21::Scene3DWidget::paintGL() {}

void s21::Scene3DWidget::resizeGL(int w, int h) {}

// --------------------

s21::ModelManager::ModelManager(QWidget *parent) : QWidget(parent) {
	AddMoveSliders();
	AddRotateSliders();
	AddScaleSliders();
	AddChooseFileButton();

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(move_sliders_);
	layout->addWidget(rotate_sliders_);
	layout->addWidget(scale_slider_);
	layout->addStretch();
	layout->addWidget(choose_file_btn_);
}

void s21::ModelManager::AddMoveSliders() {
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

void s21::ModelManager::AddRotateSliders() {
	rotate_sliders_ = new SlidersGroup(this, "Rotate");

	Slider *x = new Slider(rotate_sliders_, "X");
	Slider *y = new Slider(rotate_sliders_, "Y");
	Slider *z = new Slider(rotate_sliders_, "Z");

	x->SetRange(-10, 10);
	x->SetValue(0);

	y->SetRange(-10, 10);
	y->SetValue(0);

	z->SetRange(-10, 10);
	z->SetValue(0);

	rotate_sliders_->AddSlider(x);
	rotate_sliders_->AddSlider(y);
	rotate_sliders_->AddSlider(z);

	rotate_sliders_->AddStretch();
}

void s21::ModelManager::AddScaleSliders() {
	scale_slider_ = new SlidersGroup(this, "Scale");

	Slider *scale = new Slider(scale_slider_, "-", "+");

	scale->SetRange(-10, 10);
	scale->SetValue(0);

	scale_slider_->AddSlider(scale);

	scale_slider_->AddStretch();
}

void s21::ModelManager::AddChooseFileButton() {
	choose_file_btn_ = new QPushButton("Выбрать файл");
	choose_file_btn_->setMinimumHeight(40);
	connect(choose_file_btn_, SIGNAL(clicked()), this, SLOT(ChooseFile()));
}

void s21::ModelManager::ChooseFile() {
	QString file_path = QFileDialog::getOpenFileName(nullptr, "Выберите файл");
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
}

void s21::Slider::SetRange(int min, int max) {
	slider_->setRange(min, max);
}

void s21::Slider::SetValue(int value) {
	slider_->setValue(value);
}

// --------------------

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	s21::MainWin *win = new s21::MainWin();
	win->show();

	return app.exec();
}