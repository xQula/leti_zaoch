// sPoint.h
// This file is a header for "sPoint.cc" file

#pragma once


#include <QPainter>
#include <shapes/sOriginPlane.h>

// ---------- sPoint ----------

class sPoint
{

public:
    sPoint(int x, int y, const sOriginPlane &beginOfCoords);

    void sdraw(QPainter& qp) const;

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    void setX(int new_x);
    void setY(int new_y);

    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;
private:
    int _x;
    int _y;
    const sOriginPlane origin;
};
