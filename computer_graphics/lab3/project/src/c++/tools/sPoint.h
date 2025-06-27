// point class

#pragma once

#include <string>

class sPoint {
 public:
  sPoint();
  sPoint(double x, double y, double z);
  sPoint(const sPoint& toCopied);

  [[nodiscard]] double getX() const;

  [[nodiscard]] double getY() const;

  [[nodiscard]] double getZ() const;

  void setX(double new_x);

  void setY(double new_y);

  void setZ(double new_z);

  [[nodiscard]] double x() const;

  [[nodiscard]] double y() const;

  [[nodiscard]] double z() const;

  void add(const sPoint& other);

  void sub(const sPoint& other);

  void mul(double x);

  [[nodiscard]] std::string print(const std::string& prefix) const;

  [[nodiscard]] double vector_len() const;

 private:
  double _x;
  double _y;
  double _z;
};
