#include "view.h"
#include "desktop.h"

s21::View::View(IController *c) : controller_(c), vertex_buffer_(nullptr), central_(new QWidget()) {
	setWindowTitle("3DViewer v2.0");
	setFixedSize(1280, 720);

	setCentralWidget(central_);

	gl_widget_ = new GLWidget(this);
	model_manager_ = new ModelManager(this);

	QHBoxLayout *container = new QHBoxLayout(central_);
	container->addWidget(gl_widget_, 2);
	container->addWidget(model_manager_, 1);
}

void s21::View::SetModelFromFile(const QString &file) {
	controller_->SetModelFromFile(file.toStdString());
}

void s21::View::OnModelLoaded() {
	vertex_buffer_ = controller_->GetVertices();
	qDebug() << "View: model loaded, vertices:" << (vertex_buffer_ ? vertex_buffer_->size() : 0);
	gl_widget_->UpdateModel(vertex_buffer_);
}