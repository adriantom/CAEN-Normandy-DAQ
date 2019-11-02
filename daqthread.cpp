/*
#include "daqthread.h"
#include <QtCore>
#include <iostream>
//#include "digitizer.cpp"
//#include "mainwindow.h"

using namespace std;

daqThread::daqThread()
{

}


void daqThread::run()
{
//    Data_Accquisition();
//    cout << "data acquisition" << endl;

    double liczba = 0.0;


    for(int i=0;liczba<=5;i++){

        QMutex mutex;
        mutex.lock();

           liczba += 0.01;
            cout << liczba << endl;

        mutex.unlock();


    }

    cout << "thread test" << endl;
}
*/
