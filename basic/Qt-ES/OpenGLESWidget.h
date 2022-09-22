#pragma once

#include <QWidget>
#include <QTimer>
#include "ui_OpenGLESWidget.h"

#include "GLESContext.h"

class OpenGLESWidget : public QWidget
{
    Q_OBJECT

public:
    OpenGLESWidget(QWidget *parent = Q_NULLPTR);
    ~OpenGLESWidget();

    /// @brief 必须等到加入布局之后在调用此函数
    void setup();

protected slots:
    void render();

private:
    Ui::OpenGLESWidget ui;
    QTimer timer_;
    GLESContext context_;
};
