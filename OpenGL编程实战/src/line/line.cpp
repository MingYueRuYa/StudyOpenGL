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

struct Vertex {
  float x, y, z;
  float r, g, b;
};

void draw_lines() {
  Vertex data[] = {{0, 0, 0, 1.0, 0.0, 0.0},
                   {20, 0, 0, 0, 1.0, 1},
                   {20, 20, 0, 0, 0, 1},
                   {0, 20, 0, 1, 0, 0}};
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof(Vertex), data);
  glColorPointer(3, GL_FLOAT, sizeof(Vertex), &data[0].r);
  glDrawArrays(GL_LINE_LOOP, 0, 4);
}

Vertex _circle_data[360] = {};

void draw_circle_by_line() {
  
  float cx = 0, cy = 0, cz = 0;
  float r = 25;

  for (int i = 0; i < 360; i++) {
    _circle_data[i].x = r * cos(M_PI / 180.0 * i) + cx;
    _circle_data[i].y = r * sin(M_PI / 180.0 * i) + cy;
    _circle_data[i].z = 0;
    _circle_data[i].r = 1;
    _circle_data[i].g = 1;
    _circle_data[i].b = 1;
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof(Vertex), _circle_data);
  glColorPointer(3, GL_FLOAT, sizeof(Vertex), &_circle_data[0].r);
  glDrawArrays(GL_LINE_LOOP, 0, sizeof(_circle_data)/sizeof(_circle_data[0]));

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
  draw_lines();
  draw_circle_by_line();
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