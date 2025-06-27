// main window class -- cpp file

#include <gui/drawField.h>
#include <gui/mainWindow.h>

#include <QGridLayout>
#include <QMainWindow>

MainWindow::MainWindow(const double x1, const double y1, const double z1,
                       const double x2, const double y2, const double z2,
                       const double x3, const double y3, const double z3,
                       const double x4, const double y4, const double z4,
                       QWidget *parent)
    : QWidget(parent) {
  // https://stackoverflow.com/questions/25450598/qlayout-attempting-to-add-qlayout-to-qwidget-which-already-has-a-layout
  // https://ravesli.com/uroki-po-qt5/
  // http://knzsoft.ru/qt-bgr-ls1/
  // ./labX -style=motif
  // ./labX -style=windows
  // ./labX -style=platinum
  auto *grid = new QGridLayout(this);

  // settingPanel = new SettingPanel(this);
  drawField =
      new DrawField(this, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);

  // grid->addWidget(settingPanel, 0, 0);
  grid->addWidget(drawField, 0, 0);

  // grid->setRowStretch(1, 100);

  setLayout(grid);
}

/*SettingPanel* MainWindow::getSettingPanel()
{
    return settingPanel;
}*/

DrawField *MainWindow::getDrawField() const { return drawField; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  drawField->keyPressEventFU(event);
}