// sLine.cc
// This file is responsible for line class and line consruction

#include <shapes/sLine.h>

#include <QPainter>
#include <QWidget>
#include <utility>

// ---------- sLine ----------

sLine::sLine(sPoint pointStart, sPoint pointFinish,
             const sOriginPlane &beginOfCoords)
    : p1(std::move(pointStart)),
      p2(std::move(pointFinish)),
      origin(beginOfCoords) {}

// ---------- sLine ----------

sLine::sLine(const int x1, const int y1, const int x2, const int y2,
             const sOriginPlane &beginOfCoords)
    : p1(x1, y1, beginOfCoords),
      p2(x2, y2, beginOfCoords),
      origin(beginOfCoords) {}

// ---------- sDraw ----------

void sLine::sdraw(QPainter &qp) const {
  int x1 = p1.x();
  const int x2 = p2.x();
  int y1 = p1.y();
  const int y2 = p2.y();

  const int deltaX = abs(x2 - x1);
  const int deltaY = abs(y2 - y1);
  const int signX = x1 < x2 ? 1 : -1;
  const int signY = y1 < y2 ? 1 : -1;
  int error = deltaX - deltaY;
  qp.drawPoint(x2 + origin.getX(), y2 + origin.getY());

  while (x1 != x2 || y1 != y2) {
    qp.drawPoint(x1 + origin.getX(), y1 + origin.getY());
    int error2 = error * 2;

    if (error2 > -deltaY) {
      error = error - deltaY;
      x1 = x1 + signX;
    }
    if (error2 < deltaX) {
      error = error + deltaX;
      y1 = y1 + signY;
    }
  }
}

// ---------- getBegin ----------

sPoint sLine::getBegin() const { return p1; }

// ---------- getEnd ----------

sPoint sLine::getEnd() const { return p2; }