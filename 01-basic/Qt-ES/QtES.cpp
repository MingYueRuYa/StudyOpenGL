#include "QtES.h"
#include "OpenGLESWidget.h"
#include <QHBoxLayout>

QtES::QtES(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    OpenGLESWidget *gles = new OpenGLESWidget(this);

    gles->resize(400,400);
    gles->show();

    QWidget*    center  =   centralWidget();
    QHBoxLayout* layout  =   new QHBoxLayout(center);
    layout->addWidget(gles);

    /// @brief 必须先加入layout，在调用setup()
    /// @param parent 
    gles->setup();
}
