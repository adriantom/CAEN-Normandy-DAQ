#include "mainwindow.h"
#include <QApplication>
//#include "daqthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CAEN Normandy DAQ");
    w.show();

    QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(closing()));

    return a.exec();
}
