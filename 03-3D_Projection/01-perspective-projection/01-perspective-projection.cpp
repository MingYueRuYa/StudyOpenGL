// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "01-perspective-projection.h"
#include "OpenGLWindow.h"
#include "CELLMath.hpp"

#include <iostream>
#include <math.h>
#include <gl/GLU.h>

using namespace CELL;

class SamplerTriangle : public OpenGLWindow
{
public:

    SamplerTriangle()
    {
    }

    virtual ~SamplerTriangle()
    {}

    virtual void onInitGL()
    {
    }

  virtual void render()
  {
    #define M_PI (3.14159265358979323846)
    // 指定以下的操作针对投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 将投影矩阵清空为单位矩阵
    glLoadIdentity();
    gluPerspective(70, double(_width)/double(_height), 0.1, 1000);

    float3 arVert[] = {
        float3(0.5f, 0, -0.5),
        float3(0.1f, 0.3, -0.5),
        float3(0.8f, 0.3, -0.5),
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(float3), arVert);
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }

private:
};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
