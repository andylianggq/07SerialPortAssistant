#include "kz_const.h"
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QDebug>

void qmsleep(const uint msec)
{
    QElapsedTimer time;
    time.start();
    while(time.elapsed()< msec)
    {
        QCoreApplication::processEvents();
    }
}
