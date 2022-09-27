// 02-窗口的封装.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "02-窗口的封装.h"

#include "OpenGLWindow.h"

class SamplerTriangle : public OpenGLWindow {
 public:
  virtual void render() {
    //! 指定以下的操作针对投影矩阵
    glMatrixMode(GL_PROJECTION);
    //! 将投影举证清空成单位矩阵
    glLoadIdentity();
    glOrtho(0, _width, _height, 0, -100, 100);

    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);

    glVertex3f(_width * 0.5f, 0, 0);
    glVertex3f(_width, _height, 0);
    glVertex3f(0, _height, 0);

    glEnd();
  }
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                       _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine,
                       _In_ int nCmdShow) {
  SamplerTriangle instance;
  instance.main(800, 600);

  return 0;
}
