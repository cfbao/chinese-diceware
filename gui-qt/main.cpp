#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft YaHei",11));
    QLocale::setDefault(QLocale::Chinese);
    MainWindow w;
    w.show();
    return a.exec();
}
