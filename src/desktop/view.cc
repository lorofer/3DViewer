#include "view.h"

s21::View::View(IController *c) : controller_(c), vertex_buffer_({}), central_(new QWidget()) {
	setWindowTitle("3DViewer v2.0");
	setFixedSize(1280, 720);

	setCentralWidget(central_);

	wireframe_widget_ = new WireframeWidget(this);
	model_manager_ = new WireframeControllerWidget(this);

	QHBoxLayout *container = new QHBoxLayout(central_);
	container->addWidget(wireframe_widget_, 2);
	container->addWidget(model_manager_, 1);
}

void s21::View::SetWireframeFromFile(const QString &file) {
	controller_->SetWireframeFromFile(file.toStdString());
}

void s21::View::OnModelLoaded() {
	// vertex_buffer_ = controller_->GetVertexBuffer();
	// qDebug() << "View: model loaded, vertices:" << (vertex_buffer_ ? vertex_buffer_->size() : 0);
	wireframe_widget_->UpdateModel(controller_->GetVertexBuffer());
}