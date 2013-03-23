#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QStringListModel>
#include <QStringList>

#include <QActionGroup>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QSettings>

#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QMovie>
#include <QPainter>
#include <QMenu>


#include "qextserialport.h"
#include "qextserialenumerator.h"
#include "serialthread.h"
#include "serialthread_write.h"
#include "editcommond.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

    void sig_SendData(const QString &arg);
    
private slots:

    void slt_sendDataNum(const qint64 &num);

    void slt_set_Counter2zero();

    void slt_SerialReceiveData(const QByteArray &arg);

    void slt_showPopMenu(const QPoint &pos);

    void slt_showPopMenu_Hex(const QPoint &pos);

    void slt_showPopMenu_Parse(const QPoint &pos);

    void on_action_Serial_Assistant_triggered();

    void on_action_NetWork_triggered();

    void on_comboBox_port_editTextChanged(const QString &arg1);

    void on_comboBox_baudRate_currentIndexChanged(int index);

    void on_comboBox_dataBits_currentIndexChanged(int index);

    void on_comboBox_parity_currentIndexChanged(int index);

    void on_comboBox_stopBits_currentIndexChanged(int index);

    void on_comboBox_timeout_valueChanged(int arg1);

    void on_comboBox_queryMode_currentIndexChanged(int index);

    void on_bt_openClose_clicked();

    void on_action_Clean_triggered();

    void on_action_Save_triggered();

    void on_action_HexShow_triggered(bool checked);

    void on_bt_send_clicked();

    void on_checkBox_continuousSend_toggled(bool checked);

    void on_sendEdit_textChanged();

    void on_pushButton_Edit_SendCommd_clicked();

    void on_checkBox_toggled(bool checked);

    void on_listView_Commond_doubleClicked(const QModelIndex &index);


private:
    Ui::MainWindow *ui;

    void closeEvent(QCloseEvent * e);

    // Status bar
    QGroupBox *gb_Counter;
    QPushButton *bt_Counter2Zero;
    QHBoxLayout *hblayout1;
    QLabel *lb_receive_Num;
    QLabel *lb_send_Num;

    QGroupBox *gb_SerialStatus;
    QHBoxLayout *hblayout2;
    QLabel *lb_serialStatus;




    void init_statusBar();
    void init_variant_Serial();
    void init_ui_Serial();

    void read_config();
    void write_config();
    void init_listViewSendCommond_Model();

    void update_Counter();
    QByteArray parseHexData(QByteArray &arg1);
//    QByteArray String2Hex(QString &arg1);


    QActionGroup *m_actionGroup;
    QextSerialPort *port;
    QString portName;
    PortSettings settings;
    SerialThread *m_serialThread_Read;
    SerialThread_Write *m_serialThread_Write;

    QStringListModel *m_sendCommd_Model;

    QStringList list;

    double m_receiveNum;
    double m_sendNum;
    bool isHexShow;
    bool isinit;
    QRect m_serialConfig_rec;

    QMovie *m1;
    QMovie *m2;
    union _Data{
       qint16 w;
       struct {
         char high,low;
       } b;
    }m_data;

};

#endif // MAINWINDOW_H
