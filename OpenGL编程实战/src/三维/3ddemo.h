#include <Windows.h>

#include "CELLMath.hpp"
#include "OpenGLWindow.h"
// #include "glaux.h"
#include "glut.h"

using namespace CELL;

struct Vertex {
  float x, y, z;
};

class Demo : public OpenGLWindow {

  public:
    Demo() {
  }

  virtual void render() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadIdentity();

    gluPerspective(60, double(_width) / double(_height), 0.1, 1000);
    float3 arVert[] = {float3(0.5f, 0, -0.8), float3(0.2f, 0.3, -0.8), float3(0.8f, 0.3, -0.8)
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(float3), arVert);
    glDrawArrays(GL_TRIANGLES, 0, 3);

  }
};

class SampleCube : public OpenGLWindow {
 public:
  SampleCube() {}

  virtual void render() { 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, double(_width) / double(_height), 0.1, 1000);
    Vertex cubeVertex[] = {
            {-1.0f, -1.0f, 1.0f}, {1.0f, -1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {-1.0f, 1.0f, 1.0f},
            {-1.0f, -1.0f, -1.0f}, {1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, -1.0f}, {1.0f, -1.0f, -1.0f},
            {-1.0f, 1.0f, -1.0f}, {-1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, -1.0f},

            {-1.0f, -1.0f, -1.0f}, {1.0f, -1.0f, -1.0f}, {1.0f, -1.0f, 1.0f}, {-1.0f, -1.0f, 1.0f},
            {1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, -1.0f, 1.0f},
            {-1.0f, -1.0f, -1.0f}, {-1.0f, -1.0f, 1.0f}, {-1.0f, 1.0f, 1.0f}, {-1.0f, 1.0f, -1.0f},
    };

     for (int i = 0; i < sizeof(cubeVertex) / sizeof(cubeVertex[0]); ++i) {
      cubeVertex[i].z -= 5;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), cubeVertex);
    glDrawArrays(GL_QUADS, 0, 24);
  }
};

struct ColorVertex {
  unsigned char r, g, b, a;
  float x, y, z, w;
};

class ColorCube : public OpenGLWindow {
 public:
  ColorCube() {}

  virtual void render() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, double(_width) / double(_height), 0.1, 1000);
    ColorVertex cubeVertex[] = {{255, 0, 0, 255, -1.0f, -1.0f, 1.0f},
                           {255, 0, 0, 255, 1.0f, -1.0f, 1.0f},
                           {255, 0, 0, 255, 1.0f, 1.0f, 1.0f},
                           {255, 0, 0, 255, -1.0f, 1.0f, 1.0f},

                           {0, 255, 0, 255, -1.0f, -1.0f, -1.0f},
                           {0, 255, 0, 255, -1.0f, 1.0f, -1.0f},
                           {0, 255, 0, 255, 1.0f, 1.0f, -1.0f},
                           {0, 255, 0, 255, 1.0f, -1.0f, -1.0f},

                           {0, 0, 255, 255, -1.0f, 1.0f, -1.0f},
                           {0, 0, 255, 255, -1.0f, 1.0f, 1.0f},
                           {0, 0, 255, 255, 1.0f, 1.0f, 1.0f},
                           {0, 0, 255, 255, 1.0f, 1.0f, -1.0f},

                           {0, 255, 255, 255, -1.0f, -1.0f, -1.0f},
                           {0, 255, 255, 255, 1.0f, -1.0f, -1.0f},
                           {0, 255, 255, 255, 1.0f, -1.0f, 1.0f},
                           {0, 255, 255, 255, -1.0f, -1.0f, 1.0f},

                           {255, 0, 255, 255, 1.0f, -1.0f, -1.0f},
                           {255, 0, 255, 255, 1.0f, 1.0f, -1.0f},
                           {255, 0, 255, 255, 1.0f, 1.0f, 1.0f},
                           {255, 0, 255, 255, 1.0f, -1.0f, 1.0f},

                           {255, 255, 255, 255, -1.0f, -1.0f, -1.0f},
                           {255, 255, 255, 255, -1.0f, -1.0f, 1.0f},
                           {255, 255, 255, 255, -1.0f, 1.0f, 1.0f},
                           {255, 255, 255, 255, -1.0f, 1.0f, -1.0f}
    };

    for (int i = 0; i < sizeof(cubeVertex) / sizeof(cubeVertex[0]); ++i) {
      cubeVertex[i].z -= 5;
    }
#if 1
        glEnable(GL_DEPTH_TEST);
        glInterleavedArrays( GL_C4UB_V3F, 0, cubeVertex );
#else

    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(ColorVertex), &cubeVertex[0].x);
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(ColorVertex), cubeVertex);
    glDrawArrays(GL_QUADS, 0, 24);
    #endif
  }
};