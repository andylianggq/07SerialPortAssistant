#ifndef SERIALTHREAD_WRITE_H
#define SERIALTHREAD_WRITE_H

#include <QThread>
#include <QTime>
#include <QMutex>
#include "qextserialport.h"
#include "package.h"

class SerialThread_Write : public QThread
{
    Q_OBJECT
public:
    enum threadType
    {
        writeData,
        readData
    };
    SerialThread_Write(/*Sys_Data *_sysdata,threadType _type,*/QextSerialPort *_port,QObject *parent = 0/*const QString &Path*/);
    ~SerialThread_Write();

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


    volatile bool stopped;


    void initVariable();


};

#endif // SERIALTHREAD_H
