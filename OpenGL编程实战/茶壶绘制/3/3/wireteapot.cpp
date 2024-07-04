#include "stdafx.h"
#include "GLUT.H"

void init()
{
	glClearColor(1.0,1.0,1.0,0.5);
	glColor3f(0.0,1.0,0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireTeapot(0.8);
	glFlush();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.5,1.5,-1.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h,1.5*(GLfloat)w/(GLfloat)h,-1.5,1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myKeyBoard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL³ÌÐò");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyBoard);
	init();
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return 0;
}
