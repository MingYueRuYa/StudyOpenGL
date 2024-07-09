// 茶壶.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <windows.h>
// #include<GL\glut.h>
#include "glut.h"
#include "glaux.h"
#include <stdlib.h>

#pragma comment(lib, "legacy_stdio_definitions.lib")

// 3.cpp : 定义控制台应用程序的入口点。
//

//#include "windows.h"
//#include "gl.h"
//#include "glu.h"
//#include "glaux.h"
//void myinit(void);
//void draw_triangle(void);
//void CALLBACK display(void);
//void CALLBACK myReshape(GLsizei w, GLsizei h);
//void draw_triangle(void)
//{
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(0.0, 25.0);
//    glVertex2f(25.0, -25.0);
//    glVertex2f(-25.0, -25.0);
//    glEnd();
//}
//void CALLBACK display(void)
//{
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    /* draw an original triangle */
//    glLoadIdentity();
//    glColor3f(1.0, 1.0, 1.0);         /* white */
//    draw_triangle();
//    /* translating a triangle along X_axis  */
//    glLoadIdentity();
//    glTranslatef(-20.0, 0.0, 0.0);
//    glColor3f(1.0, 0.0, 0.0);           /* red */
//    draw_triangle();
//    /* scaling a triangle along X_axis by 1.5 and along Y_axis by 0.5  */
//    glLoadIdentity();
//    glScalef(1.5, 0.5, 1.0);
//    glColor3f(0.0, 1.0, 0.0);           /* green */
//    draw_triangle();
//    /* rotating a triangle in a counterclockwise direction about Z_axis */
//    glLoadIdentity();
//    glRotatef(90.0, 0.0, 0.0, 1.0);
//    glColor3f(0.0, 0.0, 1.0);          /* blue */
//    draw_triangle();
//    /*  scaling a triangle along Y_axis and reflecting it about Y_axis  */
//    glLoadIdentity();
//    glScalef(1.0, -0.5, 1.0);
//    glColor3f(1.0, 1.0, 0.0);          /* yellow */
//    draw_triangle();
//    glFlush();
//}
//void myinit(void)
//{
//    glShadeModel(GL_FLAT);
//}
//void CALLBACK myReshape(GLsizei w, GLsizei h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    if (w <= h)
//        glOrtho(-50.0, 50.0, -50.0 * (GLfloat)h / (GLfloat)w,
//            50.0 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
//    else
//        glOrtho(-50.0 * (GLfloat)w / (GLfloat)h,
//            50.0 * (GLfloat)w / (GLfloat)h, -50.0, 50.0, -1.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//void main(void)
//{
//    auxInitDisplayMode(AUX_SINGLE | AUX_RGBA);
//    auxInitPosition(0, 0, 500, 500);
//    auxInitWindow(L"Geometric Transformations");
//    myinit();
//    auxReshapeFunc(myReshape);
//    auxMainLoop(display);
//}
//


void init() {
    glShadeModel(GL_FLAT);
}

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
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
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

void draw_triangle()
{
  //glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 25.0);
    glVertex2f(25.0, -25.0);
    glVertex2f(-25.0, -25.0);
    glEnd();
  glFlush();
}

void CALLBACK display() {
  // draw_points();
  // draw_wire_teapot();
    draw_lines();
    draw_triangle();
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