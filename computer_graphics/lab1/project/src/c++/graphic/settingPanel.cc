// settingPanel.cc
// This file is responsible for constructing panel with parameters and start
// button

#include <graphic/drawField.h>
#include <graphic/mainWindow.h>
#include <graphic/settingPanel.h>

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <cmath>
#include <string>

using namespace std;

// ---------- settingPanel ----------

// constructor
SettingPanel::SettingPanel(QWidget *parent) : QWidget(parent) {
  _par = parent;

  grid = new QGridLayout();
  grid->setHorizontalSpacing(1);  // vertical interval
  grid->setVerticalSpacing(1);    // horizontal interval

  // "Circle" and "Point" fields placing

  auto *titleCircle1 = new QLabel( "Circle", this);
  titleCircle1->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(titleCircle1, 0, 0, 1, 4);
  auto *titleCircle2 = new QLabel( "Point", this);
  titleCircle2->setFont(QFont("Point", 14, QFont::Bold));
  grid->addWidget(titleCircle2, 5, 0, 1, 4);

  // "X-coordianate (X) " and "Y-coordianate (Y) " fields placing for each dot
  // and circle

  auto *Xlabel1 = new QLabel("(X) ", this);
  Xlabel1->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(Xlabel1, 1, 0, 1, 1);
  auto *Xlabel2 = new QLabel("(X) ", this);
  Xlabel2->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(Xlabel2, 6, 0, 1, 1);
  auto *Ylabel1 = new QLabel("(Y) ", this);
  Ylabel1->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(Ylabel1, 2, 0, 1, 1);
  auto *Ylabel2 = new QLabel("(Y) ", this);
  Ylabel2->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(Ylabel2, 7, 0, 1, 1);

  // "Semidiameter (R) " field placing

  auto *Rlabel1 = new QLabel("(R) ", this);
  Rlabel1->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(Rlabel1, 3, 0, 1, 1);

  // fields for input values

  bX1 = new QLineEdit(this);
  grid->addWidget(bX1, 1, 1, 1, 1);
  bY1 = new QLineEdit(this);
  grid->addWidget(bY1, 2, 1, 1, 1);
  bR1 = new QLineEdit(this);
  grid->addWidget(bR1, 3, 1, 1, 1);
  bX2 = new QLineEdit(this);
  grid->addWidget(bX2, 6, 1, 1, 1);
  bY2 = new QLineEdit(this);
  grid->addWidget(bY2, 7, 1, 1, 1);

  // fields for start drawing values

  bStart = new QPushButton("!TOUCH DRAW!", this);
  bStart->setFont(QFont("Circle", 14, QFont::Bold));
  grid->addWidget(bStart, 13, 0, 4, 2);

  setLayout(grid);

  connect(bStart, &QPushButton::released, this, &SettingPanel::check_and_start);
}

// ---------- isFailed ----------

// algorithm if the checking is failed (message about reason of failing)
void SettingPanel::ifFailed(const string &msg) {
  auto *error = new QDialog();
  error->setModal(true);
  auto *label = new QLabel(msg.c_str());
  auto *gr = new QGridLayout();
  gr->addWidget(label, 0, 0);
  error->setLayout(gr);
  error->show();
}

// ---------- check_and_start ----------

// treatment of input text and calling function named "non linear system" from
// "sup.cpp"
void SettingPanel::check_and_start() {
  if (bX1->text().isEmpty() || bY1->text().isEmpty() || bR1->text().isEmpty() ||
      bX2->text().isEmpty() || bY2->text().isEmpty()) {
    ifFailed(string("Please, input all the values"));
    return;
  }

  bool is_ok, res_ok = false;
  const int x01 = bX1->text().toInt(&is_ok);
  res_ok += !is_ok;
  const int y01 = bY1->text().toInt(&is_ok);
  res_ok += !is_ok;
  const int r1 = bR1->text().toInt(&is_ok);
  res_ok += !is_ok;
  const int x02 = bX2->text().toInt(&is_ok);
  res_ok += !is_ok;
  const int y02 = bY2->text().toInt(&is_ok);
  res_ok += !is_ok;

  res_ok = !res_ok;

  // checking error for input values is integer or not

  if (res_ok != true) {
    ifFailed(string("Please, input the integer values"));
    return;
  }

  // checking error for semidiameter positivity

  if (r1 <= 0) {
    ifFailed(string("Please, input the positive semidiameter number"));
    return;
  }

  // checking error for crossing circle borders

  double d = (static_cast<double>(x01) - static_cast<double>(x02)) *
             (static_cast<double>(x01) - static_cast<double>(x02));
  d = d + (static_cast<double>(y01) - static_cast<double>(y02)) *
              (static_cast<double>(y01) - static_cast<double>(y02));
  d = sqrt(d);
  if (d <= r1 + 0) {
    ifFailed(
        string("Please, input the point coordinates outside from the circle, "
               "not inside or on the circle"));
    return;
  }

  const sOriginPlane cb(0, 0);

  auto line21 = sPoint(0, 0, cb);
  auto line22 = sPoint(0, 0, cb);
  auto line31 = sPoint(0, 0, cb);
  auto line32 = sPoint(0, 0, cb);

  const auto r = static_cast<float>(r1);
  const auto x_0 = static_cast<float>(x01);  // center of circle
  const auto y_0 = static_cast<float>(y01);  // center of circle
  const auto x_1 = static_cast<float>(x02);
  const auto y_1 = static_cast<float>(y02);
  float point_1[] = {0, 0};
  float point_2[] = {0, 0};
  const float a = (x_1 - x_0) * (x_1 - x_0) + (y_0 - y_1) * (y_0 - y_1);
  const float b = -2 * ((x_1 - x_0) * (r * r + x_0 * x_1 - x_0 * x_0) +
                        x_0 * (y_0 - y_1) * (y_0 - y_1));
  const float c =
      (r * r + x_0 * x_1 - x_0 * x_0) * (r * r + x_0 * x_1 - x_0 * x_0) +
      (y_0 - y_1) * (y_0 - y_1) * (x_0 * x_0 - r * r);

  if (const float D = b * b - 4 * a * c; D > 0) {
    // x0 -- circle
    // x1 -- dot
    point_1[0] = (sqrt(D) - b) / (2 * a);
    float y_h =
        y_0 +
        sqrt(r * r - (point_1[0] - x_0) *
                         (point_1[0] - x_0));  // y high -- "+" square root
    float y_l =
        y_0 -
        sqrt(r * r - (point_1[0] - x_0) *
                         (point_1[0] - x_0));  // y low -- "-"" square root

    if (((point_1[0] - x_0) * (x_1 - point_1[0]) + (y_l - y_0) * (y_1 - y_l)) ==
        0) {
      point_1[1] = y_l;
    } else if (((point_1[0] - x_0) * (x_1 - point_1[0]) +
                (y_h - y_0) * (y_1 - y_h)) == 0) {
      point_1[1] = y_h;
    } else  // abs (number module) is necessary
    {
      if (abs(((point_1[0] - x_0) * (x_1 - point_1[0]) +
               (y_l - y_0) * (y_1 - y_l))) >=
          abs(((point_1[0] - x_0) * (x_1 - point_1[0]) +
               (y_h - y_0) * (y_1 - y_h))))  // abs -- absolute
      {
        point_1[1] =
            y_h;  // if y_l >= y_h => setting y_h (measurement error is less)
      } else      // final else
      {
        point_1[1] = y_l;
      }
    }

    point_2[0] = (-sqrt(D) - b) / (2 * a);
    y_h = y_0 + sqrt(r * r - (point_2[0] - x_0) * (point_2[0] - x_0));
    y_l = y_0 - sqrt(r * r - (point_2[0] - x_0) * (point_2[0] - x_0));
    if (((point_2[0] - x_0) * (x_1 - point_2[0]) + (y_l - y_0) * (y_1 - y_l)) ==
        0) {
      point_2[1] = y_l;
    } else if (((point_2[0] - x_0) * (x_1 - point_2[0]) +
                (y_h - y_0) * (y_1 - y_h)) == 0) {
      point_2[1] = y_h;
    } else  // abs (number module) is necessary
    {
      if (abs(((point_2[0] - x_0) * (x_1 - point_2[0]) +
               (y_l - y_0) * (y_1 - y_l))) >=
          abs(((point_2[0] - x_0) * (x_1 - point_2[0]) +
               (y_h - y_0) * (y_1 - y_h)))) {
        point_2[1] =
            y_h;  // if y_l >= y_h => setting y_h (measurement error is less)
      } else      // final else
      {
        point_2[1] = y_l;
      }
    }
  } else if (D == 0) {
    point_1[0] = -b / (2 * a);
    point_1[1] = y_0 + sqrt(r * r - (point_1[0] - x_0) * (point_1[0] - x_0));
    point_2[0] = point_1[0];
    point_2[1] = y_0 - sqrt(r * r - (point_1[0] - x_0) * (point_1[0] - x_0));
  }

  // setting values for sending to other function

  line21.setX(static_cast<int>(point_1[0]));
  line21.setY(static_cast<int>(point_1[1]));
  line22.setX(x02);
  line22.setY(y02);
  line31.setX(static_cast<int>(point_2[0]));
  line31.setY(static_cast<int>(point_2[1]));
  line32.setX(x02);
  line32.setY(y02);

  // main window update

  const auto *p = dynamic_cast<MainWindow *>(_par);

  // drawing counted values

  (p->getDrawField())
      ->init(x01, y01, r1, x02, y02, line21.getX(), line21.getY(),
             line22.getX(), line22.getY(), line31.getX(), line31.getY(),
             line32.getX(), line32.getY(), cb);
  (p->getDrawField())->update();
}