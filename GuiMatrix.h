#pragma once
#include <QWidget>
#include "Matrix.h"
#include <QGridLayout>
#include <QVector>
#include <QLineEdit>
#include <QRegularExpression>
#include <QValidator>

#define TEST_RET return 0

class GuiMatrix : public QWidget
{
private:
	QGridLayout* layout;
	QVector<QVector<QLineEdit*>> edit;
	QRegularExpression expNumbers;
	
public:
	GuiMatrix(int rows, int cols, QWidget* parent = nullptr);
	~GuiMatrix() = default;

	Matrix getMatrix() const;
	void setMatrix(const Matrix& mat);
	QGridLayout* getLayout() const;

};

