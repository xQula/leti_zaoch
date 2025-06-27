#include <QWidget>
#include <QPainter>
#include <cmath>

#include <tools/sPoint.h>

sPoint::sPoint()
: _x(0.0), _y(0.0), _z(0.0){}

sPoint::sPoint(const double x, const double y, const double z)
: _x(x), _y(y), _z(z){}

sPoint::sPoint(const sPoint& toCopied)
: _x(toCopied.getX()), _y(toCopied.getY()), _z(toCopied.getZ()){}

double sPoint::getX() const
{
    return _x;
}

double sPoint::getY() const
{
    return _y;
}

double sPoint::getZ() const
{
    return _z;
}

void sPoint::setX(const double new_x)
{
    _x = new_x;
}

void sPoint::setY(const double new_y)
{
    _y = new_y;
}

void sPoint::setZ(const double new_z)
{
    _z = new_z;
}

double sPoint::x() const {return getX();}
    
double sPoint::y() const {return getY();}

double sPoint::z() const {return getZ();}

void sPoint::add(const sPoint& other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
}

void sPoint::sub(const sPoint& other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
}

void sPoint::mul(double x)
{
    _x *= x;
    _y *= x;
    _z *= x;
}

std::string sPoint::print(const std::string& prefix) const
{
    std::string res = prefix + "(" + std::to_string(_x) + ", " + std::to_string(_y) + ", " + std::to_string(_z) + ")";
    return res;
}

double sPoint::vector_len() const
{
    return sqrt(_x*_x + _y*_y + _z*_z);
}