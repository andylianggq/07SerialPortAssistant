#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QTime>
#include <QMutex>
#include "qextserialport.h"
#include "package.h"

class SerialThread : public QThread
{
    Q_OBJECT
public:
    enum threadType
    {
        writeData,
        readData
    };
    SerialThread(/*Sys_Data *_sysdata,threadType _type,*/QextSerialPort *_port,QObject *parent = 0/*const QString &Path*/);
    ~SerialThread();

    void stop();

    volatile bool isWrire;
    volatile bool continuesSend;
    uint msc;
    QByteArray sendStr;


signals:
    void dataReceived(const QByteArray &dataReceived);
    void sig_sendNum(const qint64 &num);

protected:
    void run();
private:
    QMutex mutex;
    threadType type;
    QextSerialPort *port; // serial port
//    QTime timeout;
//    QTime pauseTime;
//    QTime feedDogInterval;

    volatile bool stopped;


    void initVariable();
//    void debugMsg(const QByteArray &msg,const qint8 &flag = 0);
//    uint writeStringToSerialPort(const QByteArray &str);

};

#endif // SERIALTHREAD_H
