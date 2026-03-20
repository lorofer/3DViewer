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

	ConnectSignals();
}

void s21::View::SetWireframeFromFile(const QString &file) {
	controller_->SetWireframeFromFile(file.toStdString());
}

void s21::View::OnModelLoaded(std::string filename) {
	wireframe_widget_->UpdateModel(controller_->GetVertexBuffer(), controller_->GetEdgesBuffer());
	model_manager_->UpdateWireframeInfo(filename, controller_->GetNumOfVertices(), controller_->GetNumOfEdges());
}

void s21::View::ConnectSignals() {
	connect(model_manager_, SIGNAL(MoveXChanged(int)), wireframe_widget_, SLOT(MoveX(int)));
	connect(model_manager_, SIGNAL(MoveYChanged(int)), wireframe_widget_, SLOT(MoveY(int)));
	connect(model_manager_, SIGNAL(MoveZChanged(int)), wireframe_widget_, SLOT(MoveZ(int)));

	connect(model_manager_, SIGNAL(RotateXChanged(int)), wireframe_widget_, SLOT(RotateX(int)));
	connect(model_manager_, SIGNAL(RotateYChanged(int)), wireframe_widget_, SLOT(RotateY(int)));
	connect(model_manager_, SIGNAL(RotateZChanged(int)), wireframe_widget_, SLOT(RotateZ(int)));

	connect(model_manager_, SIGNAL(ScaleChanged(int)), wireframe_widget_, SLOT(ScaleChanged(int)));
}