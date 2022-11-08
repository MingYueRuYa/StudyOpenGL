// 03-Triangle-circle.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "17-OpenGL扩展.h"
#include "OpenGLWindow.h"

#include <iostream>
#include <math.h>

class SamplerTriangle : public OpenGLWindow
{
public:

    SamplerTriangle()
    {
        _pixel = new char[100*200*4];

        for (int i = 0; i< 100*200*4; ++i)
        {
            _pixel[i] = rand()%255;
        }
    }

  virtual void render()
  {
    char* ext = (char*)glGetString(GL_EXTENSIONS);

    PFNGLARRAYELEMENTEXTPROC glArrayElementExt = (PFNGLARRAYELEMENTEXTPROC)wglGetProcAddress("glArrayElementEXT");
    if (nullptr == glArrayElementExt) {
      std::cout << "not find glArrayElementExt" << std::endl;
    }
    else {
      glArrayElementExt(0);
    }
  }

private:
  struct Vertex {
    float x, y, z;
    float r,g, b;
  };

  char *_pixel;

};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  
  SamplerTriangle triangle;
  triangle.main(800, 600);
  return 0;
}
