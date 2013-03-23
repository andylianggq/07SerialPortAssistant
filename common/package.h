#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include <stdio.h>
#include "kz_const.h"

QString _From_UTF8_2_GBK(const QByteArray &InputStr);
QString _From_GBK_2_UTF8(const QString &InputStr);

// 拆分收到的下位机命令
QStringList          split_String(QString    &str, bool *ok = false,const char &start_Key = BEGIN_MARK, const char &end_Key = END_MARK);
QList<QByteArray> split_ByteArray(QByteArray &str, bool *ok = false,const char &start_Key = BEGIN_MARK, const char &end_Key = END_MARK);

bool Detect_Pack(QByteArray &_Pack_Str, bool check_CRC = true, const char &start_Key = BEGIN_MARK, const char &end_Key = END_MARK);
bool Check_Crc(QByteArray str);
uint Get_Crc(char *Buffer, Byte BufLen);//CRC校验码生成
void Make_CRC(QString *_cmd);
void Make_CRC(QByteArray *_cmd);
void Make_Hex_CRC(QString *_cmd);
QByteArray String2Hex(QString &arg1);

//conversion between hex string and int.
//QString int_to_hexstr(qint32 _idata, qint8 _hexlen);
//qint32  hexstr_to_int(QString _hexstr);

////conversion between float and hexstring;
//QString float_to_hexstr(float _fdata);
//float   hexstr_to_float(QString _hexstr);

#endif // PACKAGE_H
