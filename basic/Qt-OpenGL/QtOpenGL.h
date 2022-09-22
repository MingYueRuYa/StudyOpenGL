#pragma once

#include "ui_QtOpenGL.h"
#include "GLContext.h"
#include <QtWidgets/QWidget>
#include <QTimer>

class QtOpenGL : public QWidget
{
    Q_OBJECT

public:
    QtOpenGL(QWidget *parent = Q_NULLPTR);
    ~QtOpenGL();

protected slots:
    void render();

private:
    Ui::QtOpenGLClass ui;
    GLContext context_;
    QTimer timer_;
};
