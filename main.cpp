#include "main_controller.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_controller m;
    m.show();
    return QCoreApplication::exec();
}
