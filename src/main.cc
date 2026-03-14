#include <QApplication>

#include "controller.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	s21::Controller controller = {};

	return app.exec();
}