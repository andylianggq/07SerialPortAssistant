#ifndef EDITCOMMOND_H
#define EDITCOMMOND_H

#include <QWidget>
#include <QStringListModel>
#include "package.h"

namespace Ui {
class EditCommond;
}

class EditCommond : public QWidget
{
    Q_OBJECT
    
public:
    explicit EditCommond(QStringListModel *model_p,QWidget *parent = 0,Qt::WindowFlags f = 0);
    ~EditCommond();
    
private slots:
    void on_listView_Commond_List_clicked(const QModelIndex &index);

    void on_listView_Commond_List_doubleClicked(const QModelIndex &index);

    void on_pushButton_Add_clicked();

    void on_pushButton_Insert_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_Delete_All_clicked();

    void on_pushButton_checkSum_clicked();

    void on_doubleSpinBox_DecimalNum_valueChanged(double arg1);

    void on_lineEdit_Commond_Str_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_Append_clicked();

    void on_lineEdit_Dec_textChanged(const QString &arg1);

    void on_pushButton_checkSum_Hex_clicked();

private:
    Ui::EditCommond *ui;
    QStringListModel *m_listModel;

    void closeEvent(QCloseEvent *e);

    void init_tableView_List();
    void write_listString2File();

    QByteArray bary ;

    union _Data{
       qint16 w;
       struct {
         char high,low;
       } b;
    }m_data;
};

#endif // EDITCOMMOND_H
