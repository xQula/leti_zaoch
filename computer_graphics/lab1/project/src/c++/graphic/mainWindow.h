// mainWindow.h
// This file is a header for "mainWindow.cc" file

#pragma once

#include <graphic/drawField.h>
#include <graphic/settingPanel.h>

// ---------- MainWindow ----------

class MainWindow final : public QWidget {
 public:
  explicit MainWindow(QWidget *parent = nullptr);
  [[nodiscard]] SettingPanel *getSettingPanel() const;
  [[nodiscard]] DrawField *getDrawField() const;

 private:
  SettingPanel *settingPanel;
  DrawField *drawField;
};