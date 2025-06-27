// sCircle.h
// This file is a header for "sCircle.cc" file

#pragma once

#include <shapes/sPoint.h>
#include <shapes/sOriginPlane.h>

// ---------- sCircle ----------

class sCircle
{
public:
    sCircle(const sPoint& center, int R, const sOriginPlane &beginOfCoords); // constructor
    sCircle(int center_x, int center_y, int R, const sOriginPlane &beginOfCoords); // constructor
    void sdraw(QPainter& local_qpainter) const; // drawing circle
    [[nodiscard]] sPoint getCenter() const; // getting center point
    [[nodiscard]] int getR() const; // getting semidiameter length
private:
    const sPoint point; // center point object (with coordinates inside)
    const int r; // semidiameter length
    const sOriginPlane origin; // begin of coodrdinates
};