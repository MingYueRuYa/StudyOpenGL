#pragma once

#include <Windows.h>
#include <gl/GL.h>

class GLContext {
 protected:
  int _format;
  // 窗口
  HWND _hWnd;
  // 绘制设备上下文
  HDC _hDC;
  // OpenGL上下文
  HGLRC _hRC;

 public:
  GLContext() {
    _format = 0;
    _hWnd = 0;
    _hDC = 0;
    _hRC = 0;
  }

  ~GLContext() { shutdown(); }

  bool setup(HWND hWnd, HDC hDC) {
    _hWnd = hWnd;
    _hDC = hDC;
    unsigned PixelFormat;

    PPIXELFORMATDESCRIPTOR pfd = {
        sizeof(PPIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        24,
        8,
        0,
        PFD_MAIN_PLANE,
        0,
        0,
        0,
        0};
    if (_format == 0) {
      PixelFormat = ChoosePixelFormat(_hDC, &pfd);
    } else {
      PixelFormat = _format;
    }

    if (!SetPixelFormat(_hDC, PixelFormat, &pfd)) {
      return false;
    }

    _hRC = wglCreateContext(_hDC);
    if (!wglMakeCurrent(_hDC, _hRC)) {
      return false;
    }

    return true;
  }

  void shutdown() {
    if (_hRC != NULL) {
      wglMakeCurrent(NULL, NULL);
      wglDeleteContext(_hRC);
      _hRC = NULL;
    }

    if (_hDC != NULL) {
      ReleaseDC(_hWnd, _hDC);
      _hDC = NULL;
    }
  }

  void swapBuffer() { SwapBuffers(_hDC); }
};
