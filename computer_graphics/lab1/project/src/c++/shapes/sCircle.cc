// sCircle.cc
// This file is responsible for circle class and circle consruction

#include <QWidget>
#include <cmath>
#include <utility>
#include <shapes/sCircle.h>

// ---------- sCircle ----------

sCircle::sCircle(const sPoint &center, const int R,
                 const sOriginPlane &beginOfCoords)
    : point(std::move(center)), r(R), origin(beginOfCoords) {}

// ---------- sCircle ----------

sCircle::sCircle(const int center_x, const int center_y, const int R,
                 const sOriginPlane &beginOfCoords)
    : point(center_x, center_y, beginOfCoords), r(R), origin(beginOfCoords) {}

// ---------- sdraw ----------

void sCircle::sdraw(QPainter &local_qpainter) const {
  const int x_0 = point.x();  // x coordinate
  const int y_0 = point.y();  // y coodrinate
  // counting y coordinates for putting points (from start x - r to end x + r)
  for (int x = x_0 - r; x <= x_0 + r; x++) {
    const double horde =
        sqrt(r * r - (x - x_0) * (x - x_0));  // horde from begit to circle
    double y_new = y_0 + horde;               // adding + horde to draw
    y_new = y_new < 0 ? y_new - 0.5
                      : y_new + 0.5;          // counting nearest integer value
    const int y_1 = static_cast<int>(y_new);  // making an integer value

    y_new = y_0 - horde;  // adding - horde to draw
    y_new = y_new < 0 ? y_new - 0.5
                      : y_new + 0.5;          // counting nearest integer value
    const int y_2 = static_cast<int>(y_new);  // making an integer value

    local_qpainter.drawPoint(x + origin.getX(),
                             y_1 + origin.getY());  // drawing point up
    local_qpainter.drawPoint(x + origin.getX(),
                             y_2 + origin.getY());  // drawing point down
  }
}

// ---------- getCenter ----------

sPoint sCircle::getCenter() const {
  return point;  // returning center point (with coordinates insides)
}

// ---------- getR ----------

int sCircle::getR() const {
  return r;  // returning semidiameter length
}