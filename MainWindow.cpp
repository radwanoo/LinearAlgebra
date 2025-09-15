#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	rows = new QSpinBox(this);
	rows->setValue(3);
	rows->setRange(1, 10);
	connect(rows, &QSpinBox::valueChanged, this, &MainWindow::MatrixRowsSet);

	cols = new QSpinBox(this);
	cols->setValue(3);
	rows->setRange(1, 10);
	connect(cols, &QSpinBox::valueChanged, this, &MainWindow::MatrixColsSet);


	matrix = new GuiMatrix(3, 3, this);
	matrix->getLayout()->addWidget(rows, 0, 3);
	matrix->getLayout()->addWidget(cols, 1, 3);

	box = new QHBoxLayout;
	box->addWidget(matrix, 0, Qt::AlignCenter);
	ui->centralwidget->setLayout(box);

	detBtn = new QPushButton("Calculate Determinant", this);
	connect(detBtn, &QPushButton::clicked, this, &MainWindow::calculateDet);
	matrix->getLayout()->addWidget(detBtn, 2, 3);

	detResult = new QLineEdit(this);
	detResult->setReadOnly(true);
	matrix->getLayout()->addWidget(detResult, 3, 3);

}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::MatrixRowsSet() {

}

void MainWindow::MatrixColsSet() {

}

void MainWindow::calculateDet() {
	detResult->setText("Det A = " + QString::number(matrix->getMatrix().det()));
	std::cout << matrix->getMatrix();
}