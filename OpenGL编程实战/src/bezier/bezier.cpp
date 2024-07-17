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

#pragma comment(lib, "legacy_stdio_definitions.lib")

int _width = 50;
int _height = 50;

void init() { glShadeModel(GL_FLAT); }

struct float3 {
  float x, y, z;
};

float3 _line_data[360] = {};

void draw_bezier() {
  //float3 p1 = {-25, 0, 0};
  //float3 p2 = {0, 25, 0};
  //float3 p3 = {25, 0, 0};
  //float3 p4 = {35, 25, 0};

  //glColor3f(0,1,0);
  //int idx = 0;
  //for (float i = 0.0; i < 1.0f; i+=0.01f, idx++) {
  //  _line_data[idx].x = (1 - i) * (1 - i) * (1 - i) * p1.x +
  //                      3 * i * (1 - i) * (1 - i) * p2.x +
  //                      3 * i * i * (1 - i) * p3.x + i * i * i * p4.x;
  //  _line_data[idx].y = (1 - i) * (1 - i) * (1 - i) * p1.y +
  //                      3 * i * (1 - i) * (1 - i) * p2.y +
  //                      3 * i * i * (1 - i) * p3.y + i * i * i * p4.y;
  //  _line_data[idx].z = 0;
  //}

  float3 p0 = {-25, 0, 0};
  float3 p1 = {0, 25, 0};
  float3 p2 = {25, 50, 0};
  float3 p3 = {35, 25, 0};

  int indx = 0;
  for (float t = 0; t < 1.0f; t += 0.01f, ++indx) {
    _line_data[indx].x = (1 - t) * (1 - t) * (1 - t) * p0.x +
                    3 * t * (1 - t) * (1 - t) * p1.x +
                    3 * t * t * (1 - t) * p2.x + t * t * t * p3.x;
    _line_data[indx].y = (1 - t) * (1 - t) * (1 - t) * p0.y +
                    3 * t * (1 - t) * (1 - t) * p1.y +
                    3 * t * t * (1 - t) * p2.y + t * t * t * p3.y;
    _line_data[indx].z = 0;
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof(float3), _line_data);
  glDrawArrays(GL_LINE_STRIP, 0, indx-1);
}

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

void CALLBACK display() {
  draw_bezier();
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
  // glOrtho(0, _width, _height,0,  0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
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