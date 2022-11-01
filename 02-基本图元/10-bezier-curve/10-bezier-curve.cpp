// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "10-bezier-curve.h"
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

    glColor3f(1, 0, 1);

    Vertex _line[360] = {0};
    Vertex p0 = {10, 10, 0, 1, 0, 1};
    Vertex p1 = {100, 100, 0, 0, 0, 1};
    Vertex p2 = {200, 10, 0, 1, 0, 0};
    Vertex p3 = {300, 150, 0, 1, 0, 1};

    int index = 0;
    for (float t = 0; t <  1.0f; t += 0.01f, ++index) {
      // 贝塞尔曲线的公式
        _line[index].x = (1-t)*(1-t)*(1-t)*p0.x + 3*t*(1-t)*(1-t)*p1.x + 3*t*t*(1-t)*p2.x + t*t*t*p3.x;
        _line[index].y = (1-t)*(1-t)*(1-t)*p0.y + 3*t*(1-t)*(1-t)*p1.y + 3*t*t*(1-t)*p2.y + t*t*t*p3.y;
        _line[index].z = 0;
        _line[index].r = p0.r;
        _line[index].g = p1.g;
        _line[index].b = p2.b;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), _line);
    glColorPointer(3, GL_FLOAT, sizeof(Vertex), &_line[0].r);
    // GL_LINE_LOOP 首尾连接，形成封闭的形状
    //  glDrawArrays(GL_LINE_LOOP, 0, sizeof(rect)/sizeof(rect[0]));  
    // GL_LINE_STRIP 和 GL_LINE_LOOP最大的区别就是首尾不封闭
    glDrawArrays(GL_LINE_STRIP, 0, index-1);
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
