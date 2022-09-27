#include "OpenGLESWidget.h"

OpenGLESWidget::OpenGLESWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    QObject::connect(&timer_,SIGNAL(timeout()),this,SLOT(render()));
    timer_.setInterval(16);
    timer_.start();
}

OpenGLESWidget::~OpenGLESWidget()
{
    context_.shutdown();
}

void OpenGLESWidget::setup()
{
    context_.setup((HWND)winId(), ::GetDC((HWND)winId()));
}

void OpenGLESWidget::render()
{
    glClearColor(1,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    context_.swapBuffer();
}
