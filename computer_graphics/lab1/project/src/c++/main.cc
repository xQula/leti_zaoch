// main.cc
// This file is responsible main project

#include <graphic/mainWindow.h>

#include <QApplication>

// ---------- MAIN ----------

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow window;
  window.setWindowTitle("Laboratory work 1");
  window.resize(1000, 500);
  window.show();
  return QApplication::exec();
}