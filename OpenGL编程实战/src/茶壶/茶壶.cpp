// 茶壶.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include "windows.h"
// #include<GL\glut.h>
#include "glut.h"
#include <stdlib.h>

void init() {
  glClearColor(1.0, 1.0, 1.0, 0.5);
  glColor3f(0.0, 1.0, 0.0);
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
  glVertex2f(-1.0, 0.0);
  glVertex2f(1.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.0, -1.0);
  glVertex2f(0.0, 1.0);
  glEnd();
  glFlush();
}

void draw_wire_teapot() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0);
  glutWireTeapot(0.4);
  glFlush();
}

void display() {
  // draw_points();
  // draw_wire_teapot();
  draw_lines();
}
void myReshape(GLsizei w, GLsizei h)

{
  // glViewport(0, 0, 100, 100);
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  //   glOrtho(-1.5, 1.5, -1.5, 1.50, -10.0, 10.0);
  if (w <= h)
    glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
            1.50 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
  else {
    glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5,
            1.5, -10.0, 10.0);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void myKeyboard(unsigned char key, int x, int y) {
  if (key == 27) exit(0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL程序");
  glutDisplayFunc(display);
  glutKeyboardFunc(myKeyboard);
  init();
  glutReshapeFunc(myReshape);
  glutMainLoop();
  return 0;
}