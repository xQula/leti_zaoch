#include "QCoreApplication"
#include "port/port.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    auto *port = new port::Port(nullptr);
    return QCoreApplication::exec();
}
