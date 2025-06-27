#include <gui/mainWindow.h>

#include <QColor>
#include <QPainter>
#include <QWidget>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

double deg2rad(double a) { return (M_PI * a) / 180.0; }

unsigned calcColour(unsigned char r, unsigned char g, unsigned char b) {
  unsigned res = 0, buff = 0;
  buff = b;
  res |= buff << 0;
  buff = g;
  res |= buff << 8;
  buff = r;
  res |= buff << 16;
  buff = 255;
  res |= buff << 24;
  return res;
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), cam() {
  resize(W, H);
  this->setStyleSheet(
      "background-color: rgb(0,0,0); margin:0px; border:1px solid "
      "rgb(0, 0, 0); ");

  double newy = cam_begin_R * cos(deg2rad(cam_begin_angle));
  double newz = cam_begin_R * sin(deg2rad(cam_begin_angle));
  cam.move(0.0, -newy, newz);
  cranch(false);

  C_ = NULL;
  refresh_C_();

  display = new unsigned *[H];
  for (size_t li = 0; li < H; ++li) display[li] = new unsigned[W];
  refresh_display();

  z_buffer = new double *[W];
  for (size_t li = 0; li < W; ++li) z_buffer[li] = new double[H];
  refresh_z_buffer();
}

MainWindow::~MainWindow() {
  if (C_ != NULL) delete C_;

  for (size_t li = 0; li < H; ++li) delete display[li];
  delete display;

  for (size_t li = 0; li < W; ++li) delete z_buffer[li];
  delete z_buffer;
}

void MainWindow::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);

  refresh_display();
  refresh_z_buffer();

  putRectangle3D(Point(-15, 10, 20), Point(15, 10, 20), Point(-15, 10, -15),
                 Point(15, 10, -15), calcColour(0, 0, 0));

  putRectangle3D(Point(5, -10, 10), Point(-5, -10, 10), Point(5, -10, 5),
                 Point(-5, -10, 5), calcColour(255, 255, 255));


  putTriangle3D(Triangle(Point(0, 0, 12), Point(-5, 5, 7), Point(5, 5, 7)),
                calcColour(100, 20, 0));
  putTriangle3D(Triangle(Point(0, 0, -12), Point(-5, 5, 7), Point(5, 5, 7)),
                calcColour(20, 100, 0));

  putTriangle3D(Triangle(Point(0, 0, 12), Point(5, -5, 7), Point(-5, -5, 7)),
                calcColour(255, 255, 0));
  putTriangle3D(Triangle(Point(0, 0, -12), Point(5, -5, 7), Point(-5, -5, 7)),
                calcColour(255, 0, 255));

  putTriangle3D(Triangle(Point(0, 0, 12), Point(5, 5, 7), Point(5, -5, 7)),
                calcColour(255, 50, 100));
  putTriangle3D(Triangle(Point(0, 0, -12), Point(5, 5, 7), Point(5, -5, 7)),
                calcColour(0, 255, 255));

  putTriangle3D(Triangle(Point(0, 0, 12), Point(-5, 5, 7), Point(-5, -5, 7)),
                calcColour(255, 0, 0));
  putTriangle3D(Triangle(Point(0, 0, -12), Point(-5, 5, 7), Point(-5, -5, 7)),
                calcColour(0, 0, 255));

  QPainter qp(this);
  for (size_t li = 0; li < H; ++li)
    for (size_t lj = 0; lj < W; ++lj) {
      qp.setPen(QColor(display[li][lj]));
      qp.drawPoint(lj, li);
    }
}

void MainWindow::cranch(bool where) {
  const double drotate = 1;
  int times = (int)(cam_begin_angle / drotate + 0.5);
  for (int i = 0; i < times; ++i) {
    cam.rotateOX(where ? drotate : -drotate);
  }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  int key = event->key();

  double dd = 5;

  if (key == Qt::Key_Left) {
    // cam.rotateOX(60);
    cranch(true);

    double x_new, y_new;
    rotateVector(cam.o().x(), cam.o().y(), -dd, &x_new, &y_new);
    double dx = x_new - cam.o().x();
    double dy = y_new - cam.o().y();
    cam.move(dx, dy, 0.0);
    cam.rotateOZ(-dd);

    // cam.rotateOX(-60);
    cranch(false);
  } else if (key == Qt::Key_Right) {
    // cam.rotateOX(60);
    cranch(true);

    double x_new, y_new;
    rotateVector(cam.o().x(), cam.o().y(), dd, &x_new, &y_new);
    double dx = x_new - cam.o().x();
    double dy = y_new - cam.o().y();
    cam.move(dx, dy, 0.0);
    cam.rotateOZ(dd);

    // cam.rotateOX(-60);
    cranch(false);
  }

  refresh_C_();
  update();
}

void MainWindow::rotateVector(double x_old, double y_old, double angle_degrees,
                              double *x_new, double *y_new) {
  double a = deg2rad(angle_degrees);

  double x = x_old, y = y_old;

  double si = sin(a);
  double co = cos(a);

  *x_new = x * co - y * si;
  *y_new = x * si + y * co;
}

Point MainWindow::projectionOnCamera(const Point &p) {
  return projectionOnCamera(p.x(), p.y(), p.z());
}

Point MainWindow::projectionOnCamera(double x, double y, double z) {
  Point cam_o = cam.o();
  double obj_x = x - cam_o.x();
  double obj_y = y - cam_o.y();
  double obj_z = z - cam_o.z();

  Matrix<double> old_v(3, 1);
  old_v.set(obj_x, 0, 0);
  old_v.set(obj_y, 1, 0);
  old_v.set(obj_z, 2, 0);

  Matrix<double> new_v = C_->multiply(old_v);

  double x_ = new_v.get(0, 0);
  double y_ = new_v.get(1, 0);
  double z_ = new_v.get(2, 0);

  return Point(x_, y_, z_);
}

Point MainWindow::projection3DOn2D(const Point &p) {
  return projection3DOn2D(p.x(), p.y(), p.z());
}

Point MainWindow::projection3DOn2D(double x, double y, double z) {
  Point cam_o = cam.o();
  double obj_x = x - cam_o.x();
  double obj_y = y - cam_o.y();
  double obj_z = z - cam_o.z();

  Matrix<double> old_v(3, 1);
  old_v.set(obj_x, 0, 0);
  old_v.set(obj_y, 1, 0);
  old_v.set(obj_z, 2, 0);

  Matrix<double> new_v = C_->multiply(old_v);
  double x_ = new_v.get(0, 0);
  double y_ = new_v.get(1, 0);
  double z_ = new_v.get(2, 0);

  double xp, zp;

  xp = ((n * x_) / y_);
  zp = ((n * z_) / y_);

  double x_res, y_res;
  x_res = ((xp + r) * (W - 1)) / (r + r);
  y_res = ((zp + t) * (H - 1)) / (t + t);

  return Point(x_res, y_res, 0.0);
}

bool MainWindow::isOnDisplay(int x, int y) {
  if (x < 0 || x >= (int)W) return false;
  if (y < 0 || y >= (int)H) return false;
  return true;
}

void MainWindow::refresh_C_() {
  Point vx(cam.vr());
  Point vy(cam.vf());
  Point vz(cam.vu());

  Matrix<double> C(3, 3);
  C.set(vx.x(), 0, 0);
  C.set(vy.x(), 0, 1);
  C.set(vz.x(), 0, 2);
  C.set(vx.y(), 1, 0);
  C.set(vy.y(), 1, 1);
  C.set(vz.y(), 1, 2);
  C.set(vx.z(), 2, 0);
  C.set(vy.z(), 2, 1);
  C.set(vz.z(), 2, 2);
  // std::cout << C.toString() << std::endl;
  Matrix<double> C_buff = C.inverse();

  if (C_ != NULL) delete C_;
  C_ = new Matrix<double>(C_buff);
}

void MainWindow::refresh_display() {
  for (size_t li = 0; li < H; ++li)
    for (size_t lj = 0; lj < W; ++lj) display[li][lj] = GlobalBackgroundColor;
}

void MainWindow::refresh_z_buffer() {
  double max_double = numeric_limits<double>::infinity();
  for (size_t li = 0; li < W; ++li)
    for (size_t lj = 0; lj < H; ++lj) z_buffer[li][lj] = max_double;
}

void MainWindow::putPointOnScreen(int x, int y, unsigned **display,
                                  unsigned colo, double **z_buffer,
                                  const Triangle &tri) {
  Point O(0.0, 0.0, 0.0);
  double _x = ((double)x * r * 2.0) / ((double)W - 1) - r;
  double _y = ((double)y * t * 2.0) / ((double)H - 1) - t;
  Point P(_x, n, _y);

  Point crossP = tri.crossLine(O, P);
  double z_crossed = crossP.y();

  if (z_crossed < z_buffer[x][y]) {
    if (n <= z_crossed && z_crossed <= f) {
      z_buffer[x][y] = z_crossed;
      size_t display_y = (size_t)y;
      size_t display_x = (size_t)x;
      display[H - 1 - display_y][display_x] = colo;
    }
  }
}

void MainWindow::printLineBeziers(int x1, int y1, int x2, int y2, unsigned colo,
                                  unsigned **display, double **z_buffer,
                                  const Triangle &tri) {
  int deltaX = abs(x2 - x1);
  int deltaY = abs(y2 - y1);
  int signX = x1 < x2 ? 1 : -1;
  int signY = y1 < y2 ? 1 : -1;
  //
  int error = deltaX - deltaY;
  //
  // qp.drawPoint(x2, y2);
  if (isOnDisplay(x2, y2))
    putPointOnScreen(x2, y2, display, colo, z_buffer, tri);
  while (x1 != x2 || y1 != y2) {
    // qp.drawPoint(x1, y1);
    if (isOnDisplay(x1, y1))
      putPointOnScreen(x1, y1, display, colo, z_buffer, tri);
    int error2 = error * 2;
    //
    if (error2 > -deltaY) {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX) {
      error += deltaX;
      y1 += signY;
    }
  }
}

void MainWindow::putTriangle3D(const Triangle &tri, unsigned colo) {
  Triangle tri_camera(projectionOnCamera(tri.p1()),
                      projectionOnCamera(tri.p2()),
                      projectionOnCamera(tri.p3()));
  if (tri_camera.p1().y() < n && tri_camera.p2().y() < n &&
      tri_camera.p3().y() < n)
    return;
  Point A;
  Point B;
  Point C;
  if (tri_camera.p1().y() < 0) {
    double x_ = -tri_camera.p1().x();
    double z_ = -tri_camera.p1().z();
    double y_ = tri_camera.p1().y();

    double xp = ((n * x_) / y_);
    double zp = ((n * z_) / y_);
    double x_res, y_res;
    x_res = ((xp + r) * (W - 1)) / (r + r);
    y_res = ((zp + t) * (H - 1)) / (t + t);
    A = Point(x_res, y_res, 0.0);
  } else
    A = projection3DOn2D(tri.p1());

  if (tri_camera.p2().y() < 0) {
    double x_ = -tri_camera.p2().x();
    double z_ = -tri_camera.p2().z();
    double y_ = tri_camera.p2().y();

    double xp = ((n * x_) / y_);
    double zp = ((n * z_) / y_);
    double x_res, y_res;
    x_res = ((xp + r) * (W - 1)) / (r + r);
    y_res = ((zp + t) * (H - 1)) / (t + t);
    B = Point(x_res, y_res, 0.0);
  } else
    B = projection3DOn2D(tri.p2());

  if (tri_camera.p3().y() < 0) {
    double x_ = -tri_camera.p3().x();
    double z_ = -tri_camera.p3().z();
    double y_ = tri_camera.p3().y();

    double xp = ((n * x_) / y_);
    double zp = ((n * z_) / y_);
    double x_res, y_res;
    x_res = ((xp + r) * (W - 1)) / (r + r);
    y_res = ((zp + t) * (H - 1)) / (t + t);
    C = Point(x_res, y_res, 0.0);
  } else
    C = projection3DOn2D(tri.p3());

  int x0 = (int)(A.x()), y0 = (int)(A.y());
  int x1 = (int)(B.x()), y1 = (int)(B.y());
  int x2 = (int)(C.x()), y2 = (int)(C.y());

  int tmp = 0;
  if (y0 > y1) {
    tmp = y0;
    y0 = y1;
    y1 = tmp;
    tmp = x0;
    x0 = x1;
    x1 = tmp;
  }
  if (y0 > y2) {
    tmp = y0;
    y0 = y2;
    y2 = tmp;
    tmp = x0;
    x0 = x2;
    x2 = tmp;
  }
  if (y1 > y2) {
    tmp = y1;
    y1 = y2;
    y2 = tmp;
    tmp = x1;
    x1 = x2;
    x2 = tmp;
  }

  int cross_x1 = 0, cross_x2 = 0;

  int dx1 = x1 - x0;
  int dy1 = y1 - y0;
  int dx2 = x2 - x0;
  int dy2 = y2 - y0;

  int top_y = y0;

  while (top_y < y1) {
    cross_x1 = x0 + dx1 * (top_y - y0) / dy1;
    cross_x2 = x0 + dx2 * (top_y - y0) / dy2;
    printLineBeziers(cross_x1, top_y, cross_x2, top_y, colo, display, z_buffer,
                     tri_camera);
    ++top_y;
  }

  dx1 = x2 - x1;
  dy1 = y2 - y1;

  while (top_y < y2) {
    cross_x1 = x1 + dx1 * (top_y - y1) / dy1;
    cross_x2 = x0 + dx2 * (top_y - y0) / dy2;
    printLineBeziers(cross_x1, top_y, cross_x2, top_y, colo, display, z_buffer,
                     tri_camera);
    ++top_y;
  }
}

void MainWindow::putRectangle3D(const Point &lu, const Point &ru,
                                const Point &ld, const Point &rd,
                                unsigned colo) {
  Triangle one1(lu, ru, ld);
  Triangle two2(ld, rd, ru);

  putTriangle3D(one1, colo);
  putTriangle3D(two2, colo);
}
