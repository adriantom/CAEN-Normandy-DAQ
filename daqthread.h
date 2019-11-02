#ifndef DAQTHREAD_H
#define DAQTHREAD_H
#include <QtCore>
#include <QMutex>


class daqThread : public QObject
{
    Q_OBJECT

public:
    daqThread();
    void requestAcquisition();
    void stopAcquisition();
//    daqThread();
//    void function6();
//    void function5();

private:
    bool haltFlag = false;
    QMutex inputMutex;
//    QMutex inputMutex2;

signals:
    void dataSheets();
    void acquisitionFinished();
    void acquisitionRequested();
//    void function1();
//    void function5();
//    void function3();

public slots:
    void startAcquisition(std::ofstream& file);
//    void function4();
};

#endif // DAQTHREAD_H
