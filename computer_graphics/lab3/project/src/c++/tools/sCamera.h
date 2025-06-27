// camera class

#pragma once

#include <tools/sPoint.h>

#include <string>

class sCamera {
 public:
  sCamera();
  void move(double x, double y, double z);
  void moveForward(double s);
  void moveBack(double s);
  void moveRight(double s);
  void moveLeft(double s);
  void moveUp(double s);
  void moveDown(double s);

  void rotateOX(double a);  // around R, a in degree
  void rotateOY(double a);  // around F, a in degree
  void rotateOZ(double a);  // around U, a in degree

  [[nodiscard]] sPoint o() const;
  [[nodiscard]] sPoint f() const;
  [[nodiscard]] sPoint u() const;
  [[nodiscard]] sPoint r() const;

  [[nodiscard]] sPoint vf() const;
  [[nodiscard]] sPoint vu() const;
  [[nodiscard]] sPoint vr() const;

  [[nodiscard]] std::string print() const;

 private:
  sPoint O;  // center
  sPoint F;  // forward
  sPoint U;  // up
  sPoint R;  // right

  /*mode: 1-OX, 2-OY, 3-OZ*/
  void rotate(double alpha, int mode);  // alpha in degree

  static double c(double a);   // cos
  static double s(double a);   // sin
  static double c1(double a);  // 1 - cos
};
