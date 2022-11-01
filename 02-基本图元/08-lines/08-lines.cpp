// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "08-lines.h"
#include "OpenGLWindow.h"

#include <math.h>

class SamplerTriangle : public OpenGLWindow
{
public:

  //TODO: triangle fan / triangle strip 区别就是fan的顶点不会变化，strip每次的 顶点会发生变化
  
  virtual void render()
  {
    #define M_PI (3.14159265358979323846)
    // 指定以下的操作针对投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 将投影矩阵清空为单位矩阵
    glLoadIdentity();
    glOrtho(0, _width, _height, 0, -100, 100);

    float cx = 100;
    float cy = 100;
    float cz = 0;
    float r = 80;

    glColor3f(1, 1, 1);

    Vertex rect[] = {
      {10, 10, 0, 1, 0, 0},
      {110, 10, 0, 0, 1, 0},
      {110, 110, 0, 0, 0, 1},
      {10, 110, 0, 1, 0, 1},
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), rect);
    glColorPointer(3, GL_FLOAT, sizeof(Vertex), &rect[0].r);
    // GL_LINE_LOOP 首尾连接，形成封闭的形状
    //  glDrawArrays(GL_LINE_LOOP, 0, sizeof(rect)/sizeof(rect[0]));  
    // GL_LINE_STRIP 和 GL_LINE_LOOP最大的区别就是首尾不封闭
    glDrawArrays(GL_LINE_STRIP, 0, sizeof(rect)/sizeof(rect[0]));  
    // GL_LINES 两个点，连成一条线
    // glDrawArrays(GL_LINES, 0, sizeof(rect)/sizeof(rect[0]));  
  }

private:
  struct Vertex {
    float x, y, z;
    float r,g, b;
  };

};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
