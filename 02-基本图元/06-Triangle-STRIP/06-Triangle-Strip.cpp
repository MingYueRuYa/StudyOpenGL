// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "06-Triangle-Strip.h"
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

    float3 rect[] = {
      {110, 10, 0},
      {10, 10, 0},
      {10, 110, 0},
      {110, 110, 0},
      {210, 10, 0},
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(float3), rect);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 5);
    
  }

private:

  struct float3 {
    float x, y, z;
    float w;
  };

  float3 _circle[360 * 3] = {0};

};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
