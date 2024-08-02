#pragma once

#include "GLContext.h"

class OpenGLWindow : public GLContext {
 protected:
  int _width;
  int _height;

 public:
  OpenGLWindow(HINSTANCE hInst = 0) {
    WNDCLASSEX wnd;
    memset(&wnd, 0, sizeof(wnd));

    wnd.cbSize = sizeof(wnd);
    wnd.lpfnWndProc = wndProc;
    wnd.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
    wnd.hCursor = LoadCursor(hInst, IDC_ARROW);
    wnd.hIcon = 0;
    wnd.hIconSm = 0;
    wnd.hInstance = 0;
    wnd.lpszClassName = L"OpenGLWindow";
    wnd.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    RegisterClassExW(&wnd);
  }

  virtual bool main(int w, int h) {
    HWND hwnd =
        CreateWindowEx(0, L"OpenGLWindow", L"OpenGL", WS_OVERLAPPEDWINDOW,
                       10, 10, w, h, 0, 0, 0, this);
    DWORD err = GetLastError();
    if (hwnd) {
      UpdateWindow(hwnd);
      ShowWindow(hwnd, SW_SHOW);
    } else {
      return false;
    }

    if (!setup(hwnd, GetDC(hwnd))) {
      return false;
    }
    MSG msg = {0};
    while (WM_QUIT != msg.message) {
      if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      } else {
        RECT rect;
        GetClientRect(hwnd, &rect);
        _width = rect.right - rect.left;
        _height = rect.bottom - rect.top;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, _width, _height);

        render();

        swapBuffer();
      }
    }
    shutdown();
    return true;
  }
  virtual void render() {}

  virtual LRESULT events(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam) {
    switch (msgId) {
      case WM_CLOSE:
      case WM_DESTROY: {
        PostQuitMessage(0);
      } break;
      default:
        return DefWindowProc(_hWnd, msgId, wParam, lParam);
    }
    return 0;
  }

 protected:
  static LRESULT CALLBACK wndProc(HWND hWnd,
                                  UINT msgId,
                                  WPARAM wParam,
                                  LPARAM lParam) {
    if (msgId == WM_CREATE) {
      LPCREATESTRUCT pData = (LPCREATESTRUCT)lParam;
      OpenGLWindow* pThis = (OpenGLWindow*)pData->lpCreateParams;
      SetWindowLong(hWnd, GWL_USERDATA, (LONG)pThis);
      return DefWindowProc(hWnd, msgId, wParam, lParam);
    } else {
      OpenGLWindow* pThis = (OpenGLWindow*)GetWindowLong(hWnd, GWL_USERDATA);
      if (pThis) {
        return pThis->events(hWnd, msgId, wParam, lParam);
      } else {
        return DefWindowProc(hWnd, msgId, wParam, lParam);
      }
    }
  }
};
