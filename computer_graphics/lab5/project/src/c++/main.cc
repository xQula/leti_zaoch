#include <gui/mainWindow.h>

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow window;

  window.setWindowTitle("lab5");
  window.resize(700, 700);

  window.show();

  return QApplication::exec();
}