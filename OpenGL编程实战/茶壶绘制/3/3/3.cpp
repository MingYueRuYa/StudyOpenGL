// 3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"
// #include<GL\glut.h>
#include "glut.h"
#include <stdlib.h>

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.5);
	glColor3f(0.0, 1.0, 0.0);

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glRotatef(215,1.0,1.0,1.0);
	///////////////////////////////////绘制四边形///////////////////////////////////
	glutWireTeapot(0.2);
	//glBegin(GL_POLYGON);
	//  glVertex2f(-0.5,-0.5);
	//  glVertex2f(-0.5,0.5);
	//  glVertex2f(0.5,0.5);
	//  glVertex2f(0.5,-0.5);
	//glEnd();


	glFlush();


}
void  myReshape(GLsizei w, GLsizei h)

{

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-1.5, 1.5, -1.5, 1.50 , -10.0, 10.0);
//	if (w <= h)
//		// glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.50 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
//		glOrtho(-1.5, 1.5, -1.5 , 1.50 , -20.0, 20.0);
//	else
//
//		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
//
//			1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void myKeyboard(unsigned char key, int x, int y)
{
	if (key == 27)exit(0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(100, 100);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL程序");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	init();
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return 0;
}