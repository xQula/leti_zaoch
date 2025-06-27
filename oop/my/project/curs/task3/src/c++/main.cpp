#include "QCoreApplication"
#include "department/manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    auto *manager = new department::Manager(nullptr);
    return QCoreApplication::exec();
}
