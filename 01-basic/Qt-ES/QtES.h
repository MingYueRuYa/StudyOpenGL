#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtES.h"

class QtES : public QMainWindow
{
    Q_OBJECT

public:
    QtES(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtESClass ui;
};
