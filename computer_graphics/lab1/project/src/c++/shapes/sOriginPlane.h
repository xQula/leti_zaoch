// sOriginPlane.h
// This file is a header for "sOriginPlane.cc" file

#pragma once

// ---------- sOriginPlane ----------

class sOriginPlane
{

public:
    sOriginPlane(const sOriginPlane &other);
    sOriginPlane();
    sOriginPlane(int x, int y);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
private:
    const int _x;
    const int _y;
};
