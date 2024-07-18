// 茶壶.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <windows.h>
// #include<GL\glut.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "glaux.h"
#include "glut.h"
#include "CELLMath.hpp"

using namespace CELL;

#pragma comment(lib, "legacy_stdio_definitions.lib")

int _width = 50;
int _height = 50;

void init() { glShadeModel(GL_FLAT); }


void draw_points() {
  glPointSize(10);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POINTS);
  glVertex2f(0, 0);
  glEnd();

  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  glVertex2f(_width, 0);
  glVertex2f(-_width, 0);
  glVertex2f(0, _height);
  glVertex2f(0, -_height);
  glVertex2f(_width / 2.0, _width / 2.0);
  glEnd();

  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_POINTS);
  glVertex2f(25, 25);
  glEnd();
  glFlush();
}

void draw_spline() { 
  std::vector<float3> _array;
  tspline<float> spline;
  spline.addPoint(float3(0, 0, 0));
  spline.addPoint(float3(10, 10, 0));
  spline.addPoint(float3(20, -10, 0));
  spline.addPoint(float3(40, 20, 0));
  spline.addPoint(float3(50, -20, 0));

  for (float i = 0; i < 1.0f; i+=0.01f) {
    float3 pos = spline.interpolate(i);
    _array.push_back(pos);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof(float3), &_array[0]);
  glDrawArrays(GL_LINE_STRIP, 0, _array.size());
}


void CALLBACK display() {
  draw_spline();
  draw_points();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)

{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
    glOrtho(-_width, _width, -_height * (GLfloat)h / (GLfloat)w,
            _height * (GLfloat)h / (GLfloat)w, 0.0, 10.0);
  else {
    glOrtho(-50 * (GLfloat)w / (GLfloat)h, 50 * (GLfloat)w / (GLfloat)h, -50,
            50, -1.0, 1.0);
  }

  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  auxInitDisplayMode(AUX_SINGLE | AUX_RGBA);
  auxInitPosition(0, 0, 500, 500);
  auxInitWindow(L"Geometric Transformation");
  init();
  auxReshapeFunc(myReshape);
  auxMainLoop(display);
  return 0;
}