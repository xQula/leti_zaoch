#include <QApplication>
#include <QIcon>

#include <gui/mainWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  
    MainWindow window;

    window.setWindowTitle("lab6");
    window.resize(700, 700);
    window.setWindowIcon(QIcon("./ico.png"));

    window.show();

    return app.exec();
}