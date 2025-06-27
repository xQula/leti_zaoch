// sLine.h
// This file is a header for "sLine.cc" file

#pragma once

#include <shapes/sOriginPlane.h>
#include <shapes/sPoint.h>

// ---------- sLine ----------

class sLine {
 public:
  sLine(sPoint pointStart, sPoint pointFinish,
        const sOriginPlane &beginOfCoords);
  sLine(int x1, int y1, int x2, int y2, const sOriginPlane &beginOfCoords);

  void sdraw(QPainter &qp) const;

  [[nodiscard]] sPoint getBegin() const;
  [[nodiscard]] sPoint getEnd() const;

 private:
  const sPoint p1;
  const sPoint p2;
  const sOriginPlane origin;
};