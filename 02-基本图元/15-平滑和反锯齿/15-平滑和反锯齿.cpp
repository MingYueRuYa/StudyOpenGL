﻿// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "15-平滑和反锯齿.h"
#include "OpenGLWindow.h"
#include "CELLMath.hpp"

#include <math.h>

using namespace CELL;

class SamplerTriangle : public OpenGLWindow
{
public:

    SamplerTriangle()
    {
        _spline.addPoint(float3(10, 10, 0));
        _spline.addPoint(float3(20, 100, 0));
        _spline.addPoint(float3(100, 80, 0));
        _spline.addPoint(float3(200, 100, 0));
        _spline.addPoint(float3(300, 10, 0));
        _spline.addPoint(float3(400, 150, 0));

        for (float t = 0; t < 1.0f; t += 0.01f)
        {
            float3 pos = _spline.interpolate(t);
            _array.push_back(pos);
        }

        for (int i = 0; i < _spline.getNumPoints(); ++i)
        {
          _keys.push_back(_spline.getPoint(i));
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
    // 设置线的平滑
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnableClientState(GL_VERTEX_ARRAY);  
    glVertexPointer(3, GL_FLOAT, sizeof(float3), &_array[0]);
    glDrawArrays(GL_LINE_STRIP, 0, _array.size());

    glColor3f(1, 0, 1);
    // 设置点的平滑
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    // 设置多边形的平滑
    //glEnable(GL_POLYGON_SMOOTH);
    //glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

     glPointSize(8);
     glEnableClientState(GL_VERTEX_ARRAY);
     glVertexPointer(3, GL_FLOAT, sizeof(float3), &_keys[0]);
     glDrawArrays(GL_POINTS, 0, _keys.size());
  }

private:
  struct Vertex {
    float x, y, z;
    float r,g, b;
  };

  tspline<float> _spline;
  std::vector<float3> _array;
  std::vector<float3> _keys;

};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
