#ifndef DEBUG_H_
#define DEBUG_H_
#define DEBUG_MSG
#include <QDebug>
#ifdef DEBUG_MSG
#define DPRINT(format, ...) {qDebug(format, ##__VA_ARGS__); qDebug("###FILE: %s ###LINE: %d  ###FUNC: %s", __FILE__, __LINE__, __FUNCTION__);}
#define DWHERE() \
        qDebug("###FILE: %s ###LINE: %d  ###FUNC: %s", \
        __FILE__, __LINE__, __FUNCTION__)
#else  //Not define DEBUG
#define DPRINT(format, ...)           //Empty
#define DWHERE()                      //Empty
#endif //DEBUG
#endif /* DEBUG_H_ */
