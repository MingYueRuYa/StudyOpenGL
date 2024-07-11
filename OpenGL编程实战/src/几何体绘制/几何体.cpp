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