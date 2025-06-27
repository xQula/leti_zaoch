// drawField.h
// This file is a header for "drawField.cc" file

#pragma once

#include <shapes/sCircle.h>
#include <shapes/sLine.h>
#include <shapes/sOriginPlane.h>

#include <QWidget>

// ---------- DrawField ----------

class DrawField final : public QWidget {
 public:
  explicit DrawField(QWidget *parent = nullptr);  // constructor
  ~DrawField() override;                          // destructor
  void init(int circle_1_x, int circle_1_y,
            int r1,  // circle coodrinates (x/y center, semidiameter)
            int circle_2_x, int circle_2_y,  // dot coordinates (x/y center)
            int tangent_2_x_1, int tangent_2_y_1, int tangent_2_x_2,
            int tangent_2_y_2,  // tangent 2 coordinates (x/y start, x/y end)
            int tangent_3_x_1, int tangent_3_y_1, int tangent_3_x_2,
            int tangent_3_y_2,  // tangent 3 coordinates (x/y start, x/y end)
            const sOriginPlane &offset);  // offset from left high corner

 private:
  const int W = 300;      // 300 basic
  const int H = 350;      // 350 basic
  sCircle *circle_1;      // circle
  sPoint *circle_2;       // point
  sLine *tangent_1{};     // tangent line 1
  sLine *tangent_2;       // tangent line 2
  sLine *tangent_3;       // tangent line 3
  sLine *tangent_4{};     // tangent line 4
  sLine *semidiameter_1;  // semidiameter (rus. radius) 1
  sLine *semidiameter_2;  // semidiameter (rus. radius) 1
  sLine *a{};             // y-axis
  sLine *b{};             // x-asix
  sLine *x_arrow_1{};     // x-arrow part 1
  sLine *x_arrow_2{};     // x-arrow part 2
  sLine *x_letter_1{};    // x-letter part 1
  sLine *x_letter_2{};    // x-letter part 2
  sLine *y_arrow_1{};     // y-arrow part 1
  sLine *y_arrow_2{};     // y-arrow part 2
  sLine *y_letter_1{};    // y-letter part 1
  sLine *y_letter_2{};    // y-letter part 2
 protected:
  void paintEvent(
      QPaintEvent *local_event) override;  // draw event with local event
  void drawLines(
      QPainter *local_qpainter) const;  // draw lines with local painter
};