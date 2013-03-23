#include "editcommond.h"
#include "ui_editcommond.h"

#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QDebug>
#include <QCloseEvent>

EditCommond::EditCommond(QStringListModel *model_p, QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent),
    ui(new Ui::EditCommond),m_listModel(NULL)
{
    ui->setupUi(this);
    setWindowFlags(f);
    setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);
    //    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setWindowModality(Qt::WindowModal);
    m_listModel = model_p;

    init_tableView_List();
}

EditCommond::~EditCommond()
{
    delete ui;
}

void EditCommond::closeEvent(QCloseEvent *e)
{
    write_listString2File();
    e->accept();
}

void EditCommond::init_tableView_List()
{
    if(m_listModel == NULL)
        return;
    QListView *view = ui->listView_Commond_List;
    view->setModel(m_listModel);
}

void EditCommond::on_listView_Commond_List_clicked(const QModelIndex &index)
{


}

// 双击选择编辑的命令
void EditCommond::on_listView_Commond_List_doubleClicked(const QModelIndex &index)
{
    if(m_listModel == NULL)
        return;
    QStringList list = m_listModel->stringList();
    int row = index.row();
    if(row >= 0)
    {
        QString str = list.at(row).trimmed();

        if((str.startsWith("&")) || (str.startsWith("//")))
            ui->lineEdit_Commond_Str->setText(str);
        else if(str.startsWith("26"))
            ui->lineEdit_Commond_HexStr->setText(str);


//        ui->lineEdit_Commond_Str->setText(str);
    }
}

// Add commond

void EditCommond::on_pushButton_Add_clicked()
{
    if(m_listModel == NULL)
        return;
    QString str = ui->lineEdit_Commond_Str->text().trimmed();
    QString str_Hex = ui->lineEdit_Commond_HexStr->text().trimmed();

    QStringList list = m_listModel->stringList();
    if(!str.trimmed().isEmpty())
        list.append(str);

    if(!str_Hex.trimmed().isEmpty())
        list.append(str_Hex);

    m_listModel->setStringList(list);
}

// Insert commond

void EditCommond::on_pushButton_Insert_clicked()
{
    if(m_listModel == NULL)
        return;
    int index =  ui->listView_Commond_List->currentIndex().row();
    if(index < 0)
        return;
    QString str = ui->lineEdit_Commond_Str->text().trimmed();
    QString str_Hex = ui->lineEdit_Commond_HexStr->text().trimmed();
    QStringList list = m_listModel->stringList();

    if(!str_Hex.trimmed().isEmpty())
        list.insert(index,str_Hex);
    if(!str.trimmed().isEmpty())
        list.insert(index,str);

    m_listModel->setStringList(list);

}

// Delete commond

void EditCommond::on_pushButton_Delete_clicked()
{
    if(m_listModel == NULL)
        return;
    int index =  ui->listView_Commond_List->currentIndex().row();
    if(index < 0)
        return;
    QStringList list = m_listModel->stringList();
    list.removeAt(index);
    m_listModel->setStringList(list);


}

// Delete All commond

void EditCommond::on_pushButton_Delete_All_clicked()
{
    if(m_listModel == NULL)
        return;

    int rec = QMessageBox::question(this,tr("Delete All..."),tr("Are you sure Delete All Commond String?"),QMessageBox::YesAll | QMessageBox::No,QMessageBox::No);
    if(rec == QMessageBox::YesAll)
    {
        QStringList list = m_listModel->stringList();
        list.clear();
        m_listModel->setStringList(list);
    }
}


void EditCommond::write_listString2File()
{
    if(m_listModel == NULL)
        return;

    QStringList list = m_listModel->stringList();
    //    QString cmd_str;
    //    foreach(QString str,list)
    //    {
    //        cmd_str.append(str);
    //        cmd_str.append('@');
    //    }

    QString path = QDir::toNativeSeparators(QDir::currentPath().append(QDir::separator()).append("conf.ini"));
    qDebug() << "path" <<  path;
    QSettings cfg(path,QSettings::IniFormat);
    cfg.beginGroup("serialCommand");
    //    cfg.setValue("cmd_str",cmd_str);
    cfg.setValue("cmd_str",list);
    cfg.endGroup();
}

// 计算明码的 crc 值
void EditCommond::on_pushButton_checkSum_clicked()
{
    QString str = ui->lineEdit_Commond_Str->text().trimmed();
    if(str.startsWith("//"))
        return;
    if(str.endsWith('$'))
    {
        int len = str.size();
        str = str.left(len-3);
    }
    Make_CRC(&str);
    ui->lineEdit_Commond_Str->setText(str);
}

// 计算16进制字符串 crc 值
void EditCommond::on_pushButton_checkSum_Hex_clicked()
{

    QString hexStr = ui->lineEdit_Commond_HexStr->text().trimmed();
    if(hexStr.startsWith("//"))
        return;
    if(hexStr.endsWith("24"))
    {
        hexStr = hexStr.trimmed();
        int len = hexStr.size();
        hexStr = hexStr.left(len - 8);
        hexStr = hexStr.trimmed();
        len = hexStr.size();
    }

    Make_Hex_CRC(&hexStr);
    ui->lineEdit_Commond_HexStr->setText(hexStr);

}

// float 数值改变
void EditCommond::on_doubleSpinBox_DecimalNum_valueChanged(double arg1)
{
    if(arg1 >= 0)
    {
        //        bary.clear();
        //        m_data.w = arg1 *10;
        int v = arg1 *10;
        QString str = QString("%1").arg(v,4,16,QLatin1Char('0')).toUpper();
        QString str2;
        while(str.size()>0)
        {
            str2.append(str.left(2));
            str2.append(' ');
            str = str.right(str.size()-2);
        }
        ui->lineEdit_HexadecimalNum->setText(str2);

        //        bary.setNum(m_data.w,16);

        //        bary.append(m_data.b.low);
        //        bary.append(m_data.b.high);
        //        ui->lineEdit_Hex->setText(bary);

    }
}


// 明码命令字符串改变
void EditCommond::on_lineEdit_Commond_Str_textChanged(const QString &arg1)
{
    if(arg1.startsWith("//"))
        return;
    QByteArray bAry1 = arg1.trimmed().toAscii();
    QString str;
    foreach(char ch ,bAry1)
    {
        str.append(QString::number(ch,16));
        str.append(' ');
    }
    ui->lineEdit_Commond_HexStr->setText(str);
}


// 添加16进制数到命令字符串

void EditCommond::on_pushButton_clicked()
{
    QString str_Data = ui->lineEdit_HexadecimalNum->text().trimmed();
    QString str = ui->lineEdit_Commond_HexStr->text().trimmed();
    if(str_Data.trimmed().isEmpty())
        return;

    if(str.endsWith("24"))
        return;
    str.append(' ');
    str.append(str_Data);
    ui->lineEdit_Commond_HexStr->setText(str);
}


// 添加命令字符
void EditCommond::on_pushButton_Append_clicked()
{

    QString str = ui->lineEdit_Commond_HexStr->text().trimmed();
    QString str_Data = ui->lineEdit_Hex->text().trimmed();

    if(str_Data.trimmed().isEmpty())
        return;

    if(str.endsWith("24"))
        return;

    str.append(' ');
    str.append(str_Data);
    ui->lineEdit_Commond_HexStr->setText(str.toUpper());


}

// 当个字符改变
void EditCommond::on_lineEdit_Dec_textChanged(const QString &arg1)
{
    QByteArray bAry = arg1.trimmed().toAscii();
    QString str;
    foreach(char ch ,bAry)
    {
        str.append(QString::number(ch,16));
        str.append(' ');
    }
    ui->lineEdit_Hex->setText(str.toUpper());
}

