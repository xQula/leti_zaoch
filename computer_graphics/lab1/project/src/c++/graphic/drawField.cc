// drawField.cc
// This file is responsible for drawing lines and circles

// Line 1 -- up parallel (outside)
// Line 2 -- up crossing (inside)
// Line 3 -- down crossing (inside)
// Line 4 -- down parallel (outside)

#include <graphic/drawField.h>

// ---------- DrawField ----------

// constructor
DrawField::DrawField(QWidget *parent) : QWidget(parent) {
  // creating all the new objects
  circle_1 = nullptr;
  circle_2 = nullptr;
  tangent_2 = nullptr;
  tangent_3 = nullptr;
  semidiameter_1 = nullptr;
  semidiameter_2 = nullptr;

  // resizing and setting background
  resize(W, H);
  this->setStyleSheet(
      "background-color: rgb(255,255,255); margin:0px; border:1px solid rgb(0, "
      "0, 0); ");  // white
}

// ---------- ~DrawField ----------

// destructor
DrawField::~DrawField() {
  // destructing (deleting) all the objects
  delete circle_1;
  delete circle_2;
  delete tangent_2;
  delete tangent_3;
  delete semidiameter_1;
  delete semidiameter_2;
}

// ---------- paintEvent ----------

// drawing all of the composition
void DrawField::paintEvent(QPaintEvent *local_event) {
  Q_UNUSED(local_event);
  QPainter local_qpainter(this);  // creating QPainter
  drawLines(&local_qpainter);     // drawing lines with QPainter
}

// ---------- init ----------

// initializing cordinates, that we counted
void DrawField::init(
    const int circle_1_x, const int circle_1_y,
    const int r1,  // circle coodrinates (x/y center, semidiameter)
    const int circle_2_x, const int circle_2_y,  // dot coordinates (x/y)
    const int tangent_2_x_1, const int tangent_2_y_1, const int tangent_2_x_2,
    const int tangent_2_y_2,  // tangent 2 coordinates (x/y start, x/y end)
    const int tangent_3_x_1, const int tangent_3_y_1, const int tangent_3_x_2,
    const int tangent_3_y_2,     // tangent 3 coordinates (x/y start, x/y end)
    const sOriginPlane &offset)  // offset from left high corner
{
  // cleaning before making something -- we can input new parameters

  delete circle_1;
  delete circle_2;
  delete tangent_2;
  delete tangent_3;
  delete semidiameter_1;
  delete semidiameter_2;

  const sOriginPlane *local_offset = new sOriginPlane(W, H);

  circle_1 =
      new sCircle(circle_1_x, circle_1_y, r1,
                  *local_offset);  // center of the circle and its semidiameter
  circle_2 =
      new sPoint(circle_2_x, circle_2_y,
                 *local_offset);  // center of the circle and its semidiameter
  tangent_2 =
      new sLine(tangent_2_x_1, tangent_2_y_1, tangent_2_x_2, tangent_2_y_2,
                *local_offset);  // from first border point to second
  tangent_3 =
      new sLine(tangent_3_x_1, tangent_3_y_1, tangent_3_x_2, tangent_3_y_2,
                *local_offset);  // from first border point to second
  semidiameter_1 =
      new sLine(circle_1_x, circle_1_y, tangent_2_x_1, tangent_2_y_1,
                *local_offset);  // semidiameter from center to border point
  semidiameter_2 =
      new sLine(circle_1_x, circle_1_y, tangent_3_x_1, tangent_3_y_1,
                *local_offset);  // semidiameter from center to border point

  // setting coordinates axis and letters

  a = new sLine(0, -5000, 0, 5000, *local_offset);
  b = new sLine(-5000, 0, 5000, 0, *local_offset);

  x_arrow_1 = new sLine(W, 0, W - 10, -10, *local_offset);
  x_arrow_2 = new sLine(W, 0, W - 10, 10, *local_offset);
  x_letter_1 = new sLine(W, -15, W - 10, -25, *local_offset);
  x_letter_2 = new sLine(W - 10, -15, W, -25, *local_offset);
  y_arrow_1 = new sLine(0, H, -10, H - 10, *local_offset);
  y_arrow_2 = new sLine(0, H, 10, H - 10, *local_offset);
  y_letter_1 = new sLine(-20, H - 5, -25, H - 10, *local_offset);
  y_letter_2 = new sLine(-15, H - 10, -25, H, *local_offset);
}

// ---------- drawLines ----------

// drawing lines, that we have
void DrawField::drawLines(QPainter *local_qpainter) const {
  if (circle_1 != nullptr && circle_2 != nullptr && tangent_2 != nullptr &&
      tangent_3 != nullptr) {
    QColor color_1(0, 255, 0);      // green color setting for circles
    QPen pen_1(color_1); // pen setting
    pen_1.setWidth(3);
    local_qpainter->setPen(pen_1);  // pen setting for special object

    circle_1->sdraw(*local_qpainter);
    circle_2->sdraw(*local_qpainter);

    QColor color_2(255, 0, 255);      // purple color setting for lines
    QPen pen_2(color_2); // pen setting
    pen_2.setWidth(3);
    local_qpainter->setPen(pen_2);  // pen setting for special object

    tangent_2->sdraw(*local_qpainter);
    tangent_3->sdraw(*local_qpainter);

    QColor color_3(0, 0, 0);        // black color setting for semidiameter
    QPen pen_3(color_3);
    pen_3.setWidth(3);// pen setting
    local_qpainter->setPen(pen_3);  // pen setting for special object

    semidiameter_1->sdraw(*local_qpainter);
    semidiameter_2->sdraw(*local_qpainter);

    // drawing coordinate axis and letters

    a->sdraw(*local_qpainter);
    b->sdraw(*local_qpainter);
    x_arrow_1->sdraw(*local_qpainter);
    x_arrow_2->sdraw(*local_qpainter);
    x_letter_1->sdraw(*local_qpainter);
    x_letter_2->sdraw(*local_qpainter);
    y_arrow_1->sdraw(*local_qpainter);
    y_arrow_2->sdraw(*local_qpainter);
    y_letter_1->sdraw(*local_qpainter);
    y_letter_2->sdraw(*local_qpainter);
  }
}