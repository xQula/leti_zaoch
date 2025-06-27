// settingPanel.h
// This file is a header for "settingPanel.cc" file

#pragma once

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <string>

// ---------- SettingPanel ----------

class SettingPanel final : public QWidget {
  Q_OBJECT
  QWidget *_par;
  QGridLayout *grid;
  QLineEdit *bX1;
  QLineEdit *bY1;
  QLineEdit *bR1;
  QLineEdit *bX2;
  QLineEdit *bY2;
  QLineEdit *bR2{};
  QLineEdit *bShiftX{};
  QLineEdit *bShiftY{};
  QPushButton *bStart;

 public:
  explicit SettingPanel(QWidget *parent = nullptr);
  void check_and_start();
  static void ifFailed(const std::string &msg);
};