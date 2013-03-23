#include "Registry_Read.h"

QString getRegKeyValue(HKEY key, LPCTSTR property)
{
    DWORD size = 0;
    DWORD type;
    RegQueryValueEx(key, property, NULL, NULL, NULL, & size);
    BYTE* buff = new BYTE[size];
    QString result;
    if( RegQueryValueEx(key, property, NULL, &type, buff, & size) == ERROR_SUCCESS )
        result = ATCHARToQString(buff);
    RegCloseKey(key);
    delete [] buff;
    return result;
}



QString WGetKey(QString SubKey, QString ValueName)
{

    HKEY RootKey = HKEY_LOCAL_MACHINE;
    HKEY mKey;
    bool open_ok = false;
    QString _SubKey, _ValueName;
    _SubKey = SubKey;
    _ValueName = ValueName;

    //TCHAR *AA = (TCHAR*)AQStringToTCHAR(_SubKey);
    LONG lResult = RegOpenKeyEx(RootKey,AQStringToTCHAR(_SubKey),0,KEY_READ,&mKey);

    switch(lResult)
    {
        case ERROR_SUCCESS: //ok
            open_ok = true;
            break;
        default: //an error code from windows
            open_ok = false;
            break;
    }
    if(open_ok)  //the key is opened, now read it.
    {
        QString abc = getRegKeyValue(mKey,AQStringToTCHAR(_ValueName));//TEXT("\\Device\\VSerial0"));
        //qDebug()<< abc;
        RegCloseKey(mKey);
        return abc;
    }
    return "";
}





