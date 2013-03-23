#ifndef REGISTRY_READ_H
#define REGISTRY_READ_H
#include <QString>
#include "Windows.h"
#include <QDebug>

#ifdef UNICODE
    #define AQStringToTCHAR(x)     (wchar_t*) x.utf16()
    #define APQStringToTCHAR(x)    (wchar_t*) x->utf16()
    #define ATCHARToQString(x)     QString::fromUtf16((ushort*)(x))
    #define ATCHARToQStringN(x,y)  QString::fromUtf16((ushort*)(x),(y))
#else
    #define AQStringToTCHAR(x)     x.toLocal8Bit().constData()
    #define APQStringToTCHAR(x)    x->toLocal8Bit().constData()
    #define ATCHARToQString(x)     QString::fromLocal8Bit((char*)(x))
    #define ATCHARToQStringN(x,y)  QString::fromLocal8Bit((char*)(x),(y))
#endif /*UNICODE*/


QString WGetKey(QString SubKey, QString ValueName);
#endif // REGISTRY_READ_H
