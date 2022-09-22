// glut.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "glut.h"

void display()
{
    glClearColor(0, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutSwapBuffers();
}

int _tmain(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("test glut");
    glutDisplayFunc(display);
    glutMainLoop();
	return 0;
}

