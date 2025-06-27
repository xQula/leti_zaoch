// main window class

#pragma once

#include <gui/drawField.h>

#include <QLineEdit>
#include <QMainWindow>

class MainWindow final : public QWidget {
  Q_OBJECT

 public:
  MainWindow(double x1, double y1, double z1, double x2, double y2, double z2,
             double x3, double y3, double z3, double x4, double y4, double z4,
             QWidget *parent = nullptr);

  [[nodiscard]] DrawField *getDrawField() const;

 private:
  DrawField *drawField;

 protected:
  void keyPressEvent(QKeyEvent *event) override;
};