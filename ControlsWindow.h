#include <QWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include "GuiMatrix.h"
#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class QWindow; }
QT_END_NAMESPACE

class ControlsWindow :
    public QWidget
{
    Q_OBJECT

public:
    ControlsWindow(QWidget* parent = nullptr);

private:
    QPushButton* detCount;
    QLineEdit* detResult;
    QPushButton* makeInverse;
    GuiMatrix* matrix;
    QVBoxLayout* layout;
};

