// draw field class

#pragma once

#include <tools/matrix.h>
#include <tools/sCamera.h>
#include <tools/sPoint.h>

#include <QMouseEvent>
#include <QWidget>
#include <cmath>

class DrawField final : public QWidget {


 public:
  DrawField(QWidget *parent, double x1, double y1, double z1, double x2,
            double y2, double z2, double x3, double y3, double z3, double x4,
            double y4, double z4);
  ~DrawField() override;

  void keyPressEventFU(const QKeyEvent *event);

  void putPoint(double x, double y, double z) const;
  void putLine3D(double x1, double y1, double z1, double x2, double y2,
                 double z2) const;
  void putLine3D(const sPoint &b, const sPoint &e);

  // void putParallelepiped(sPoint p1, sPoint p2);
  // void putSphere(sPoint c, double r);

 private:
  const size_t W = 1280;
  const size_t H = 720;
  const double aspect = static_cast<double>(W) / static_cast<double>(H);

  const double n = 1;
  const double f = 10000;
  const double fov = 65;
  const double t = n * tan(fov / 2);  // top
  const double r = t * aspect;        // right

  Matrix<double> *C_;

  int **display;

  sCamera cam;

  void refresh_C_();
  void refresh_display() const;

  sPoint p1, p2, p3, p4;
  Matrix<double> M_rotate;
  void M_rotate_refresh();
  double angleX;
  double angleY;
  void drawBilinearSurface();
  sPoint calBilinearSurface(double u, double w);
  void paintEvent(QPaintEvent *event) override;
};