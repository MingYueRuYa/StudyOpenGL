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

void init() { glShadeModel(GL_FLAT); }

void draw_points() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0, 0);
  glPointSize(10);
  glBegin(GL_POINTS);
  glVertex2f(-1.0, 0.0);
  glVertex2f(-1.0, 0.0);
  glVertex2f(1.0, 0.0);
  glVertex2f(0.0, 1.0);
  glVertex2f(0.0, -1.0);
  glEnd();

  glFlush();
}

void draw_lines() {
  glColor3f(1.0, 1.0, 0.0);
  glLineWidth(2.0);
  glBegin(GL_LINES);
  glVertex2f(-25.0, 0.0);
  glVertex2f(25.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.0, -25.0);
  glVertex2f(0.0, 25.0);
  glEnd();
  glFlush();
}

void draw_wire_teapot() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0);
  glutWireTeapot(0.4);
  glFlush();
}

void draw_triangle() {
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.0, 25.0);
  glVertex2f(25.0, -25.0);
  glVertex2f(-25.0, -25.0);
  glEnd();
  glFlush();
}

void draw_fill_triangle() {
  glBegin(GL_TRIANGLES);
  glVertex2f(-25.0, 0);
  glVertex2f(0.0, 25);
  glVertex2f(0.0, 0);
  glEnd();
  glFlush();
}

void draw_circle_by_triangle() {
  glColor3f(0.2, 0.5, 0.5);
  glBegin(GL_TRIANGLES);

  float cx = 0, cy = 0, cz = 0;
  float r = 25;

  for (int i = 0; i < 360; i++) {
    float x1 = r * cos(M_PI / 180.0 * i) + cx;
    float y1 = r * sin(M_PI / 180.0 * i) + cy;

    float x2 = r * cos(M_PI / 180.0 * (i + 1)) + cx;
    float y2 = r * sin(M_PI / 180.0 * (i + 1)) + cy;

    glVertex3f(cx, cy, cz);
    glVertex3f(x1, y1, cz);
    glVertex3f(x2, y2, cz);
  }

  glEnd();
  glFlush();
}

void CALLBACK display() {
  // draw_lines();
  //  glClearColor(0.0, 0.0, 0.0, 1.0);
  //  glClear(GL_COLOR_BUFFER_BIT);
  //  glLoadIdentity();
  //  draw_lines();
  //  glLoadIdentity();
  //  glColor3f(1.0, 1.0, 1.0);
  //  /* draw an original triangle */
  //  draw_triangle();
  //
  //  /* translating a triangle along X_axis  */
  //  glLoadIdentity();
  //  glColor3f(1.0, 0.0, 0.0);
  //  glTranslatef(-20, 0.0, 0.0);
  //  draw_triangle();
  //
  ///* scaling a triangle along X_axis by 1.5 and along Y_axis by 0.5  */
  //  glLoadIdentity();
  //  glColor3f(0.0,1.0,0.0);
  //  glScalef(1.5, 0.5, 0);
  //  draw_triangle();
  //
  //  /* rotating a triangle in a counterclockwise direction about Z_axis */
  //  glLoadIdentity();
  //  glRotatef(90.0, 0.0, 0.0, 1.0);
  //  glColor3f(0.0,0.0,1.0);
  //  draw_triangle();
  //
  ///*  scaling a triangle along Y_axis and reflecting it about Y_axis  */
  //  glLoadIdentity();
  //  glScalef(1.0, -1,1.0);
  //  glColor3f(1.0, 0.5, 0.0);
  //  draw_triangle();

  glLoadIdentity();
  // glColor3f(0.0, 0.5, 0.50);
  // draw_fill_triangle();

  draw_circle_by_triangle();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)

{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
    glOrtho(-50, 50, -50 * (GLfloat)h / (GLfloat)w,
            50 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
  else {
    glOrtho(-50 * (GLfloat)w / (GLfloat)h, 50 * (GLfloat)w / (GLfloat)h, -50,
            50, -1.0, 1.0);
  }

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