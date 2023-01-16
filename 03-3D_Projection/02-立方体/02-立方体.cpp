// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "02-立方体.h"
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
    gluPerspective(60, double(_width)/double(_height), 0.1, 1000);

   Vertex cubeVertices[] =
    {
            { 255,0,0,255, -1.0f,-1.0f, 1.0f },
            { 255,0,0,255, 1.0f,-1.0f, 1.0f },
            { 255,0,0,255, 1.0f, 1.0f, 1.0f },
            { 255,0,0,255, -1.0f, 1.0f, 1.0f },

            { 0,255,0,255, -1.0f,-1.0f,-1.0f },
            { 0,255,0,255, -1.0f, 1.0f,-1.0f },
            { 0,255,0,255, 1.0f, 1.0f,-1.0f },
            { 0,255,0,255, 1.0f,-1.0f,-1.0f },

            { 0,0,255,255, -1.0f, 1.0f,-1.0f },
            { 0,0,255,255, -1.0f, 1.0f, 1.0f },
            { 0,0,255,255, 1.0f, 1.0f, 1.0f },
            { 0,0,255,255, 1.0f, 1.0f,-1.0f },

            { 0,255,255,255, -1.0f,-1.0f,-1.0f },
            { 0,255,255,255, 1.0f,-1.0f,-1.0f },
            { 0,255,255,255, 1.0f,-1.0f, 1.0f },
            { 0,255,255,255, -1.0f,-1.0f, 1.0f },

            { 255,0,255,255, 1.0f,-1.0f,-1.0f },
            { 255,0,255,255, 1.0f, 1.0f,-1.0f },
            { 255,0,255,255, 1.0f, 1.0f, 1.0f },
            { 255,0,255,255, 1.0f,-1.0f, 1.0f },

            { 255,255,255,255, -1.0f,-1.0f,-1.0f },
            { 255,255,255,255, -1.0f,-1.0f, 1.0f },
            { 255,255,255,255, -1.0f, 1.0f, 1.0f },
            { 255,255,255,255, -1.0f, 1.0f,-1.0f }
    };
    for (int i = 0 ;i < sizeof(cubeVertices) /sizeof(cubeVertices[0]); ++ i )
    {
        cubeVertices[i].z   -=  5;
    }

#if 1
    glEnable(GL_DEPTH_TEST);
    glInterleavedArrays(GL_C4UB_V3F, 0, cubeVertices);
#else
    // glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &cubeVertices[0].x);
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(Vertex), cubeVertices);
#endif

    glDrawArrays(GL_QUADS, 0, 24);
  }

private:
  struct Vertex
  {
    unsigned char r, g, b, a;
    float x, y, z, w;
  };
};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
