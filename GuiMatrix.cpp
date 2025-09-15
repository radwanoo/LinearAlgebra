#include "GuiMatrix.h"

GuiMatrix::GuiMatrix(int rows, int cols, QWidget* parent)
	: QWidget(parent) {
	layout = new QGridLayout;
	setLayout(layout);

	expNumbers = QRegularExpression("[+-]?\\d+([.]\\d+)?");
	QValidator* validator = new QRegularExpressionValidator(expNumbers, this);

	edit.resize(rows);
	for (int i = 0; i < rows; i++) {
		edit[i].resize(cols);
		for (int j = 0; j < cols; j++) {
			edit[i][j] = new QLineEdit(this);
			edit[i][j]->setValidator(validator);
			edit[i][j]->setText("0");
			layout->addWidget(edit[i][j], i, j);
		}
	}
}

Matrix GuiMatrix::getMatrix() const {
	Matrix result(edit.size(), edit[0].size());

	for (int i = 0; i < edit.size(); i++) {
		for (int j = 0; j < edit[0].size(); j++) {
			result(i + 1, j + 1) = edit[i][j]->text().toDouble();
		}
	}
	return result;
}

void GuiMatrix::setMatrix(const Matrix& mat) {

	//TEST_RET;
}

QGridLayout* GuiMatrix::getLayout() const {
	return layout;
}