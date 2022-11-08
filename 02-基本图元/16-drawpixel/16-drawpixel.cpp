// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "16-drawpixel.h"
#include "OpenGLWindow.h"

#include <math.h>

class SamplerTriangle : public OpenGLWindow
{
public:

    SamplerTriangle()
    {
        _pixel = new char[100*200*4];

        for (int i = 0; i< 100*200*4; ++i)
        {
            _pixel[i] = rand()%255;
        }
    }

  virtual void render()
  {
    #define M_PI (3.14159265358979323846)
    // 指定以下的操作针对投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 将投影矩阵清空为单位矩阵
    glLoadIdentity();
    glOrtho(0, _width, _height, 0, -100, 100);

    glColor3f(1, 0, 0);

    Vertex vertex[] = {
        {10, 10, 0, 1, 0, 0},
        {110, 10, 0, 1, 0, 0},
        {10, 110, 0, 1, 0, 1},
        {110, 110, 0, 1, 0, 0}
    };

    glColor3f(0, 1, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &vertex[0]);
    glColorPointer(3, GL_FLOAT, sizeof(Vertex), &vertex[0].r);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    Vertex vertex_1[] = {
        {10, 10, 0, 1, 0, 0},
        {110, 10, 0, 1, 0, 0},
        {10, 110, 0, 1, 0, 1},
        {110, 110, 0, 1, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        vertex_1[i].x += 150;
    }

    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &vertex_1[0]);
    glColorPointer(3, GL_FLOAT, sizeof(Vertex), &vertex_1[0].r);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // 指定像素操作的光栅位置
    glRasterPos2i(100, 300);
    // 绘制的时候坐标是从下往上
    glDrawPixels(100, 300, GL_RGBA, GL_UNSIGNED_INT, _pixel);
  }

private:
  struct Vertex {
    float x, y, z;
    float r,g, b;
  };

  char *_pixel;

};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
