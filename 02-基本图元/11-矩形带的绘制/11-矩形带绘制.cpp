// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "11-矩形带绘制.h"
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

    Vertex _line[] = {
        {10, 110, 0},
        {10, 10, 0},

        {110, 110, 0},
        {110, 10, 0},

        {210, 110, 0},
        {210, 10, 0},
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), _line);
    glDrawArrays(GL_TRIANGLE_STRIP, 0,sizeof(_line)/sizeof(_line[0]));
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
