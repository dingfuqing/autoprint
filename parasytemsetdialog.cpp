#include "QtNetwork/QTcpSocket"
#include<QHostAddress>
#include<QMessageBox>

#include "parasytemsetdialog.h"
#include "ui_parasytemsetdialog.h"

#include "datamanagedialog.h"
#include "globe.h"

extern SysPara m_SysPara;

ParaSytemSetDialog::ParaSytemSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaSytemSetDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("#frame{background-color: rgb(202, 206, 236);border-radius: 5px}"
                        "#ParaSytemSetDialog{background-color: rgb(255, 255, 255)} QGroupBox{background-color: rgb(202, 206, 236);border-radius: 5px} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");


    m_SysPara.changeflag = 0;
    ui->MarginLBlineEdit->setText(m_SysPara.Ip_A);
    ui->MarginLWlineEdit->setText(m_SysPara.Ip_B);
    ui->MarginRBlineEdit->setText(m_SysPara.Ip_C);
    ui->MarginRWlineEdit->setText(m_SysPara.Ip_D);

}

ParaSytemSetDialog::~ParaSytemSetDialog()
{
    delete ui;
}

void ParaSytemSetDialog::on_UpdatepushButton_released()
{
    QHostAddress ip_test;
    QString m_Ip_A;
    QString m_Ip_B;
    QString m_Ip_C;
    QString m_Ip_D;


    if (!ip_test.setAddress(ui->MarginLBlineEdit->text()))
    {
        //QMessageBox::about(this, "提示", "错误 : 左侧黑墨控制器IP地址无效！\n请重新输入。");
        QMessageBox box(QMessageBox::Warning,"提示", "错误 : 左侧黑墨控制器IP地址无效！\n请重新输入。");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
        return;
    }
    else
    {
        m_Ip_A = ui->MarginLBlineEdit->text();
        if ( m_SysPara.Ip_A.compare(m_Ip_A) != 0 )
        {
            m_SysPara.Ip_A = m_Ip_A;
            m_SysPara.changeflag = 1;
        }
    }


    if (!ip_test.setAddress(ui->MarginLWlineEdit->text()))
    {
        //QMessageBox::about(this, "提示", "错误 : 左侧白墨控制器IP地址无效！\n请重新输入。");
        QMessageBox box(QMessageBox::Warning,"提示", "错误 : 左侧白墨控制器IP地址无效！\n请重新输入。");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
        return;
    }
    else
    {
         m_Ip_B = ui->MarginLWlineEdit->text();
         if ( m_SysPara.Ip_B.compare(m_Ip_B) != 0 )
         {
             m_SysPara.Ip_B = m_Ip_B;
             m_SysPara.changeflag = 1;
         }
    }


    if (!ip_test.setAddress(ui->MarginRBlineEdit->text()))
    {
        //QMessageBox::about(this, "提示", "错误 : 右侧黑墨控制器IP地址无效！\n请重新输入。");
        QMessageBox box(QMessageBox::Warning,"提示", "错误 : 右侧黑墨控制器IP地址无效！\n请重新输入。");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
        return;
    }
    else
    {
        m_Ip_C = ui->MarginRBlineEdit->text();
        if ( m_SysPara.Ip_C.compare(m_Ip_C) != 0 )
        {
            m_SysPara.Ip_C = m_Ip_C;
            m_SysPara.changeflag = 1;
        }
    }


    if (!ip_test.setAddress(ui->MarginRWlineEdit->text()))
    {
        //QMessageBox::about(this, "提示", "错误 : 右侧白墨控制器IP地址无效！\n请重新输入。");
        QMessageBox box(QMessageBox::Warning,"提示", "错误 : 右侧白墨控制器IP地址无效！\n请重新输入。");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
        return;
    }
    else
    {
        m_Ip_D = ui->MarginRWlineEdit->text();
        if ( m_SysPara.Ip_D.compare(m_Ip_D) != 0 )
        {
            m_SysPara.Ip_D = m_Ip_D;
            m_SysPara.changeflag = 1;
        }
    }

    QDialog::close();
}

void ParaSytemSetDialog::on_CancelpushButton_released()
{
    QDialog::close();
}

void ParaSytemSetDialog::on_UpdatepushButton_pressed()
{
    ui->UpdatepushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ParaSytemSetDialog::on_CancelpushButton_pressed()
{
    ui->CancelpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}
