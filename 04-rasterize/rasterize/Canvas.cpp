#include "Canvas.h"

#include <vector>

namespace GT {

void Canvas::drawLine(std::vector<Point> &results, const Point &v0,
                      const Point &v1) {
  Point start = v0;
  Point end = v1;
  // 1.确保x方向是从小到大的
  if (start.m_x > end.m_x) {
    std::swap(start, end);
  }
  results.push_back(start);

  // 2.保证y方向也是从小到大，如果需要翻转，必须记录
  bool flipY = false;
  if (start.m_y > end.m_y) {
    start.m_y *= -1;
    end.m_y *= -1;
    flipY = true;
  }

  // 3.保证斜率在0-1之间，如果需要调整，必须记录
  int deltaY = static_cast<int>(end.m_y - start.m_y);
  int deltaX = static_cast<int>(end.m_x - start.m_x);

  bool swapXY = false;
  if (deltaX < deltaY) {
    std::swap(start.m_x, start.m_y);
    std::swap(end.m_x, end.m_y);
    std::swap(deltaX, deltaY);
    swapXY = true;
  }

  // 4.brensenham
  int currentX = static_cast<int>(start.m_x);
  int currentY = static_cast<int>(start.m_y);
  int resultX = 0;
  int resultY = 0;

  Point currentPoint;
  int p = 2 * deltaY - deltaX;

  for (int i = 0; i < deltaX; ++i) {
    if (p >= 0) {
      currentY += 1;
      p -= 2 * deltaX;
    }

    currentX += 1;
    p += 2 * deltaY;

    // 处理新xy， flip and swap
    resultX = currentX;
    resultY = currentY;

    if (swapXY) {
      std::swap(resultX, resultY);
    }
    if (flipY) {
      resultY *= -1;
    }

    // 产生新顶点
    currentPoint.m_x = resultX;
    currentPoint.m_y = resultY;
    results.push_back(currentPoint);
  }
}

  void Canvas::testDrawLine()
  {
    std::vector<Point> results;
    drawLine(results, Point(100, 100), Point(200, 300));
    for (int i = 0; i < results.size(); ++i) {
        drawPoint(results[i]);
    }
  }

}  // namespace GT