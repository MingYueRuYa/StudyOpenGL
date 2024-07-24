// 茶壶.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <stdlib.h>
#include <windows.h>
#include <vector>

#include "OpenGLWindow.h"
#include "glaux.h"
#include "glut.h"

class SimpleTriangle : public OpenGLWindow {
  virtual void render() {
    glMatrixMode(GL_PROJECTION);
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

int __stdcall WinMain(HINSTANCE hIns,
                      HINSTANCE hPrev,
                      LPSTR lpCmdLine,
                      int nShowCmd) {
  SimpleTriangle st;
  st.main(800, 600);

  return 0;
}
