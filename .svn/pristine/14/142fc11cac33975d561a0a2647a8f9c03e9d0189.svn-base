#include "serialthread.h"
//#include "kz_const.h"
#include "debug.h"

#include <QTextCodec>


SerialThread::SerialThread(/*Sys_Data *_sysdata,threadType _type,*/QextSerialPort *_port,QObject *parent/*const QString &path*/)
    :QThread(parent),port(_port)/*,type(_type)*/
{
    moveToThread(this);
    initVariable();
    qDebug() << "threadType is :" << type;
}

SerialThread::~SerialThread()
{
    if(this->isRunning())
    {
        DPRINT("stop serial thread!");
        stop();
        wait();
    }
    DPRINT("--> Destructor SerialThread ");
}
void SerialThread::initVariable()
{
    stopped = false;
    isWrire = false;
    continuesSend = false;
    msc = 0;
}

void SerialThread::stop()
{
    DPRINT("--> stop serialthread!");
    stopped = true;
}


void SerialThread::run()
{
    DWHERE();
    while(!stopped)
    {
        msleep(100);
        /*读取串口数据*/
        if(port->isOpen())
        {
            //            if (type)
            //            {
            QByteArray readByte;
            qint64 readNum = 0;
            while((readNum = port->bytesAvailable()) >= 1)
            {
                msleep(50);
                mutex.lock();
                readNum = port->bytesAvailable();
                readByte = port->read(readNum);
                //                readByte = port->readAll();
//                QByteArray readStr;

//                foreach(uchar ch, readByte)
//                {
//                    ch = ch & 0xFF;
//                    if(ch >= 0/* && (ch != 13) && (ch != 10) && (ch != 32)*/)
//                    {
//                        readStr.append(ch);
//                    }
//                }

//                emit dataReceived(readStr);
                emit dataReceived(readByte);
                mutex.unlock();
                //                readByte = readByte.simplified();
                qDebug() << readByte;
                //                qDebug()<< "uft8_gbK :" << _From_UTF8_2_GBK(readByte);

                // 读完数据后等待10 毫秒
                //                if(readByte.endsWith('$'))
                //                {

                readNum = 0;
                readByte.clear();
                //                }


            }
            //            }
            //            else //*  ==我是读数据和写数据的分割线================================================*/
            //            {
            //                if(isWrire)
            //                {
            //                    if(!sendStr.isEmpty())
            //                    {
            //                        //                    int sendNum = writeStringToSerialPort(sendStr);
            //                        mutex.lock();
            //                        port->write(sendStr);
            //                        qint64 sendNum =  sendStr.size();
            //                        qDebug() << "sendNum" << sendNum;
            //                        emit sig_sendNum(sendNum);
            //                        mutex.unlock();
            //                    }
            //                    if(continuesSend)
            //                    {
            //                        msleep(msc);
            //                    }
            //                    else
            //                    {
            //                        isWrire = false;
            //                        sendStr.clear();
            //                        msc = 0;
            //                    }
            //                }
            //            }
        }
    }
}

//uint SerialThread::writeStringToSerialPort(const QByteArray &str)
//{
//    //QByteArray str = _str.trimmed().toAscii();
//    uint writeNum = 0;
//    if(str.size()<=0)
//        return writeNum;
//    for(int i=0;i<str.size();i++)
//    {
//        while(!port->putChar(str[i]))
//        {
//            qDebug() << "putChar -> " << i << str[i];
//            writeNum += 1;
//        }
//        //msleep(1);
//        writeNum += 1;
//    }
//    return writeNum;
//}

//void SerialThread::debugMsg(const QString &msg, const qint8 &flag)
//{
//    if(flag == isReadData)
//    {
////        qDebug() << "\r\n\r\n--------------------------------------------------> BEGIN";
//        qDebug() << "read  ->" << msg;
//    }
//    else if(flag == isWriteData)
//    {
//        if(taskInfo->cur_task_sequences.waitType == sendCmdWait)
//            qDebug() << "write ->" << " Com Msg " << msg;
//        else if(taskInfo->cur_task_sequences.waitType == sendArkWait)
//            qDebug() << "write ->" << " Ark Msg " << msg;
//        else
//            qDebug() << "write ->" << msg;
//    }
//    else
//    {
//        qDebug() << msg;
//    }
//}

//void SerialThread::debugMsg(const QByteArray &msg, const qint8 &flag)
//{
//    //    if(flag == isReadData)
//    //    {
//    //        //        qDebug() << "\r\n\r\n--------------------------------------------------> BEGIN";
//    //        qDebug() << "read: ->\t" << msg;
//    //    }
//    //    else if(flag == isWriteData)
//    //    {
//    //        //        if(taskInfo->cur_task_sequences.waitType == sendCmdWait)
//    //        //            qDebug() << "write: ->\t" << " Com Msg " << msg;
//    //        //        else if(taskInfo->cur_task_sequences.waitType == sendArkWait)
//    //        //            qDebug() << "write: ->\t" << " Ark Msg " << msg;
//    //        //        else
//    //        qDebug() << "write: ->\t" << msg;
//    //    }
//    //    else
//    //    {
//    //        qDebug() << msg;
//    //    }
//}
