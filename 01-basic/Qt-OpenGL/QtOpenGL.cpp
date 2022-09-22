#include "QtOpenGL.h"

QtOpenGL::QtOpenGL(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    HWND hwnd = (HWND)winId();
    context_.setup(hwnd, ::GetDC(hwnd));
    QObject::connect(&timer_, SIGNAL(timeout()), this, SLOT(render()));
    timer_.setInterval(16);
    timer_.start();
}

QtOpenGL::~QtOpenGL()
{
    context_.shutdown();
}

void QtOpenGL::render()
{
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    context_.swapBuffer();
}
