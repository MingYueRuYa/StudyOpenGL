// 茶壶.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <windows.h>
// #include<GL\glut.h>
#include <stdlib.h>
#include "glaux.h"
#include "glut.h"

#pragma comment(lib, "legacy_stdio_definitions.lib")

void init() {
  glShadeModel(GL_FLAT);
}

void DrawMyObjects() {
  /* draw some points  */
  glPointSize(10);
  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(0.0, 0.0);
  glVertex2f(-1.0, 15.0);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(1.0, 15.0);
  glColor3f(0.0, 1.0, 1.0);
  glVertex2f(3.0, 15.0);
  glEnd();

/* draw some line_segments */
  glLineWidth(5);
  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-3.0, 4.0);
  glVertex2f(-11.0, 8.0);
  glColor3f(1.0, 0.0, 1.0);
  glVertex2f(-5.0, 4.0);
  glVertex2f(-13.0, 4.0);
  glEnd();

    /* draw one opened_line  */
  glLineWidth(2);
  glBegin(GL_LINE_STRIP);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-3.0, 9.0);
  glVertex2f(2.0, 6.0);
  glVertex2f(3.0, 9.0);
  glVertex2f(-2.0, 6.0);
  glVertex2f(-3.0, 9.0);
  glEnd();


    /* draw one closed_line  */
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(7.0, 7.0);
  glVertex2f(9.0, 9.0);
  glVertex2f(10.0, 8.0);
  glVertex2f(11.0, 9.0);
  glVertex2f(13.0, 7.0);
  glVertex2f(11.0, 5.0);
  glVertex2f(10.0, 6.0);
  glVertex2f(9.0, 5.0);
  glEnd();

  /* draw one filled_polygon  */
  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 0.2);
  glVertex2f(-10.0, 4.0);
  glVertex2f(-8.0, 4.0);
  glVertex2f(-6.0, 1.0);
  glVertex2f(-8.0, -2.0);
  glVertex2f(-10.0, -2.0);
  glVertex2f(-12.0, 1.0);
  glEnd();

  /* draw some filled_quandrangles  */
  glBegin(GL_QUADS);
  glColor3f(0.7, 0.5, 0.2);
  glVertex2f(-2.0, 3.0);
  glVertex2f(-3.0, -1.0);
  glVertex2f(1.0, -1.0);
  glVertex2f(0.0, 3.0);
  glEnd();

    /* draw some filled_strip_quandrangles  */
  glBegin(GL_QUAD_STRIP);
  glVertex2f(6.0, -2.0);
  glVertex2f(5.5, 1.0);
  glVertex2f(8.0, -1.0);
  glColor3f(0.8, 0.0, 0.0);
  glVertex2f(9.0, 2.0);
  glVertex2f(11.0, -2.0);
  glColor3f(0.0, 0.0, 0.8);
  glVertex2f(11.0, 2.0);
  glVertex2f(13.0, -1.0);
  glColor3f(0.0, 0.8, 0.0);
  glVertex2f(14.0, 1.0);
  glEnd();

   /* draw some filled_triangles  */ 
  glBegin(GL_TRIANGLES);
  glColor3f(0.2, 0.7, 0.5);
  glVertex2f(-12.0, -7.0);
  glVertex2f(-7.0, -4.5);
  glVertex2f(-5.5, -9.0);
  glEnd();

  /* draw some filled_strip_triangles  */
  glBegin(GL_TRIANGLE_STRIP);
  glVertex2f(-1.0, -8.0);
  glVertex2f(-2.5, -5.0);
  glColor3f(0.8, 0.8, 0.0);
  glVertex2f(1.0, -7.0);
  glColor3f(0.0, 0.8, 0.8);
  glVertex2f(2.0, -4.0);
  glColor3f(0.8, 0.0, 0.8);
  glVertex2f(4.0, -6.0);
  glEnd();

    /* draw some filled_fan_triangles  */
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(8.0, -6.0);
  glVertex2f(10.0, -3.0);
  glColor3f(0.8, 0.2, 0.5);
  glVertex2f(12.5, -4.5);
  glColor3f(0.2, 0.5, 0.8);
  glVertex2f(13.0, -7.5);
  glColor3f(0.8, 0.5, 0.2);
  glVertex2f(10.5, -9.0);
  glEnd();


}

void CALLBACK display() {
  glColor3f(1.0, 1.0, 0.0);
  DrawMyObjects();
  glFlush();
 }


void CALLBACK myReshape(GLsizei w, GLsizei h)

{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
    glOrtho(-20, 20, -20 * (GLfloat)h / (GLfloat)w,
            20 * (GLfloat)h / (GLfloat)w, -20.0, 20.0);
  else {
    glOrtho(-20 * (GLfloat)w / (GLfloat)h, 20 * (GLfloat)w / (GLfloat)h, -20,
            20, -20.0, 20.0);
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