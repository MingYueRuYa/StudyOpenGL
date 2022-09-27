// test-glfw.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GLFW/glfw3.h"
#include <stdlib.h>

static void error_callback(int error, const char *desc)
{
    fprintf(stderr, "Error: %s\n", desc);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int _tmain(int argc, _TCHAR* argv[])
{
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simple example", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0,1,1,1);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

