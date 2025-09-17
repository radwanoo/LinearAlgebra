#include "ControlsWindow.h"
#include <QMainWindow>

ControlsWindow::ControlsWindow(QWidget* parent) {

	detCount = new QPushButton("Calculate Determinant", this);
	detResult = new QLineEdit("Det A = ", this);

	makeInverse = new QPushButton("Inverse", this);
	matrix = new GuiMatrix(3, 3, false, this);

	layout = new QVBoxLayout(this);

	layout->addWidget(matrix);
	layout->addWidget(detCount);
	layout->addWidget(detResult);
	layout->addWidget(makeInverse);

	setLayout(layout);
	setWindowFlags(Qt::Tool);
	setWindowTitle("Results Panel");
}