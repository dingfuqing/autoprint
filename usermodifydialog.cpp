#include <QSqlQuery>
#include <QSqlDriver>

#include "usermodifydialog.h"
#include "ui_usermodifydialog.h"
#include "globe.h"
#include "confirmdialog.h"
#include "systemmessagedialog.h"

extern GlobalMember m_GlobalMember;

UserModifyDialog::UserModifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserModifyDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("修改用户信息");
    this->setStyleSheet("#UserModifyDialog{background-color: rgb(255, 255, 255)} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    QStringList levellist;
    levellist.clear();
    levellist.append("");
    for(int i = 1; (i < m_GlobalMember.UserLevel)&&(i < 5); i++)
    {
        QString istr = "";
        istr.setNum(i);
        levellist.append(istr);
    }
    ui->levelcomboBox->insertItems(0, levellist);
    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
    {
        ;
    }
}

UserModifyDialog::~UserModifyDialog()
{
    databaseoperation.User_DB.close();

    delete ui;
}

void UserModifyDialog::on_OKpushButton_pressed()
{
    ui->OKpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void UserModifyDialog::on_OKpushButton_released()
{
    if((ui->UserNamelineEdit->text() == "")||
       (ui->OldPasswdlineEdit->text() == "")||
       (ui->NewPasswdlineEdit->text() == "")||
       (ui->ConfirmPasswdlineEdit->text() == "")||
       (ui->levelcomboBox->currentIndex() == 0))
    {
        SystemMessageDialog m_SystemMessageDialog("各输入框不能为空！");
        m_SystemMessageDialog.exec();
    }
    else
    {
        QSqlQuery query = databaseoperation.GetUserInfoByName("User", ui->UserNamelineEdit->text(), ui->OldPasswdlineEdit->text());
        if(!query.next())
        {
            SystemMessageDialog m_SystemMessageDialog("用户名或旧密码输入错误，请重新输入！");
            m_SystemMessageDialog.exec();
        }
        else
        {
            if(ui->NewPasswdlineEdit->text() != ui->ConfirmPasswdlineEdit->text())
            {
                SystemMessageDialog m_SystemMessageDialog("两次输入的新密码不一致，请重新输入！");
                m_SystemMessageDialog.exec();
            }
            else
            {
                m_GlobalMember.IsConfirmed = false;
                ConfirmDialog m_ConfirmDialog("确定要修改该用户信息吗？");
                m_ConfirmDialog.exec();
                if(m_GlobalMember.IsConfirmed)
                {
                    databaseoperation.UpdateUserInfoByName("User", ui->UserNamelineEdit->text(), ui->NewPasswdlineEdit->text(), ui->levelcomboBox->currentText());
                }
            }
        }

    }
    ui->OKpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}
