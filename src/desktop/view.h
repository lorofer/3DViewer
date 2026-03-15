#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>

#include "icontroller.h"
#include "wireframe_controller_widget.h"
#include "wireframe_widget.h"

namespace s21 {
class View : public QMainWindow {
	Q_OBJECT

private:
	IController *controller_;
	std::vector<float> vertex_buffer_;

	QWidget *central_;
	WireframeWidget *wireframe_widget_;
	WireframeControllerWidget *model_manager_;

	void ConnectSignals();

public:
	View(IController *c);
	void OnModelLoaded();

public slots:
	void SetWireframeFromFile(const QString &file);
};
}

#endif