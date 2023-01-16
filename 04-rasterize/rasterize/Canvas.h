#ifndef canvas_h
#define canvas_h

#include <string>
#include <vector>

#include "GTMATH.hpp"

namespace GT {
struct Point {
 public:
  float m_x;
  float m_y;
  float m_z;
  RGBA m_color;
  floatV2 m_uv;
  Point(float _x = 0, float _y = 0, float _z = 0,
        RGBA _color = RGBA(0, 255, 0, 0), floatV2 _uv = floatV2(0.0, 0.0)) {
    m_x = _x;
    m_y = _y;
    m_z = _z;
    m_color = _color;
    m_uv = _uv;
  }
  ~Point() {}
};

class Canvas {
 private:
  int m_width;
  int m_height;
  RGBA *m_buffer;

 public:
  Canvas(int _width, int _height, void *_buffer) {
    if (_width <= 0 || _height <= 0) {
      m_width = -1;
      m_height = -1;
      m_buffer = nullptr;
    }

    m_width = _width;
    m_height = _height;
    m_buffer = (RGBA *)_buffer;
  }
  ~Canvas() {}

  void clear() {
    if (m_buffer != NULL) {
      memset(m_buffer, 0, sizeof(RGBA) * m_width * m_height);
    }
  }
  //======画点操作
  void drawPoint(Point _pt) {
    if (_pt.m_x < 0 || _pt.m_x >= m_width || _pt.m_y < 0 ||
        _pt.m_y >= m_height) {
      return;
    }
    int _index = _pt.m_y * m_width + _pt.m_x;
    m_buffer[_index] = _pt.m_color;
  }
  //======画线操作
  void drawLine(std::vector<Point> &results, const Point &v0, const Point &v1);

 public:
  void testDrawLine();
};

}  // namespace GT

#endif  // canvas_h