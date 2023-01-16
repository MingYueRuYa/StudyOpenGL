#include "Canvas.h"

#include <vector>

namespace GT {

void Canvas::drawLine(std::vector<Point> &results, const Point &v0,
                      const Point &v1) {
  Point start = v0;
  Point end = v1;
  // 1.ȷ��x�����Ǵ�С�����
  if (start.m_x > end.m_x) {
    std::swap(start, end);
  }
  results.push_back(start);

  // 2.��֤y����Ҳ�Ǵ�С���������Ҫ��ת�������¼
  bool flipY = false;
  if (start.m_y > end.m_y) {
    start.m_y *= -1;
    end.m_y *= -1;
    flipY = true;
  }

  // 3.��֤б����0-1֮�䣬�����Ҫ�����������¼
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

    // ������xy�� flip and swap
    resultX = currentX;
    resultY = currentY;

    if (swapXY) {
      std::swap(resultX, resultY);
    }
    if (flipY) {
      resultY *= -1;
    }

    // �����¶���
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