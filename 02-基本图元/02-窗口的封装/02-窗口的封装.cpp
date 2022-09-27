// 02-���ڵķ�װ.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "02-���ڵķ�װ.h"

#include "OpenGLWindow.h"

class SamplerTriangle : public OpenGLWindow {
 public:
  virtual void render() {
    //! ָ�����µĲ������ͶӰ����
    glMatrixMode(GL_PROJECTION);
    //! ��ͶӰ��֤��ճɵ�λ����
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
