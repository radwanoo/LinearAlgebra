#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "Matrix.h"
#include <QSpinBox>
#include "GuiMatrix.h"
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private:
	Ui::MainWindow* ui;
	//	void AddMatrix();
	GuiMatrix* matrix;
	QHBoxLayout* box;

	QPushButton* detBtn;
	QLineEdit* detResult;

	QSpinBox* rows;
	QSpinBox* cols;
public slots:
	void MatrixRowsSet();
	void MatrixColsSet();
	void calculateDet();

};

