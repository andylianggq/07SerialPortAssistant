#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *code_utf = QTextCodec::codecForName("UTF-8");
    QTextCodec *code_gbk = QTextCodec::codecForName("GBK");
#ifdef Q_OS_WIN
    QTextCodec::setCodecForLocale(code_gbk);
    QTextCodec::setCodecForCStrings(code_gbk);
#else
    QTextCodec::setCodecForLocale(code_utf);
    QTextCodec::setCodecForCStrings(code_utf);
#endif
    QTextCodec::setCodecForTr(code_utf);

    MainWindow w;
    w.show();
    
    return a.exec();
}
