#include "upandaway.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UpAndAway w;
    w.show();
    return a.exec();
}
