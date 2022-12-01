#include "upandaway.h"

#include <QApplication>
////Wie mache ich im Designer die sachen richtig?
/// Wie mache ich die typeid fehlermeldungen weg?
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UpAndAway w;
    w.show();
    return a.exec();
}
