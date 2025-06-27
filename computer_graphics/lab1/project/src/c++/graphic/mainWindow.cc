// mainWindow.cc
// This file is responsible for constructing main window

#include <graphic/drawField.h>
#include <graphic/mainWindow.h>
#include <graphic/settingPanel.h>

// ---------- MainWindow ----------

// constructor
MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  // https://stackoverflow.com/questions/25450598/qlayout-attempting-to-add-qlayout-to-qwidget-which-already-has-a-layout
  auto* grid = new QGridLayout(this);

  drawField = new DrawField(this);
  settingPanel = new SettingPanel(this);

  grid->addWidget(drawField, 0, 0);
  grid->addWidget(settingPanel, 0, 1);

  grid->setColumnStretch(0, 100);

  setLayout(grid);
}

// ---------- getSettingPanel ----------

// returning (getting) the current setting panel pointer
SettingPanel* MainWindow::getSettingPanel() const { return settingPanel; }

// ---------- getDrawField ----------

// returning (getting) the current draw field pointer
DrawField* MainWindow::getDrawField() const { return drawField; }