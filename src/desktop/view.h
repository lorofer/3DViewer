#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include <QtWidgets>

#include "icontroller.h"

namespace s21 {
class GLWidget;
class ModelManager;

class View : public QMainWindow {
	Q_OBJECT

private:
	IController *controller_;
	std::shared_ptr<const std::vector<float>> vertex_buffer_;

	QWidget *central_;
	GLWidget *gl_widget_;
	ModelManager *model_manager_;

public:
	View(IController *c);
	void OnModelLoaded();

public slots:
	void SetModelFromFile(const QString &file);
};
}

#endif