// sPoint.cc
// This file is responsible for point class and point consruction

#include <shapes/sPoint.h>

// ---------- sPoint ----------

sPoint::sPoint(const int x, int y, const sOriginPlane &beginOfCoords)
: _x(x), _y(y), origin(beginOfCoords)
{}

// ---------- sDraw ----------

void sPoint::sdraw(QPainter& qp) const {
    qp.drawPoint(x() + origin.getX(), y() + origin.getY());
}

// ---------- getX ----------

int sPoint::getX() const
{
    return _x;
}

// ---------- getY ----------

int sPoint::getY() const
{
    return _y;
}

// ---------- setX ----------

void sPoint::setX(const int new_x)
{
    _x = new_x;
}

// ---------- setY ----------

void sPoint::setY(const int new_y)
{
    _y = new_y;
}

// ---------- x ----------

int sPoint::x() const
{
    return getX();
}

// ---------- y ----------

int sPoint::y() const
{
    return getY();
}