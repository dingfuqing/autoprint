
#include <QSqlQuery>
#include <QSqlDriver>

#include "useradddialog.h"
#include "ui_useradddialog.h"

#include "globe.h"
#include "confirmdialog.h"
#include "systemmessagedialog.h"

extern GlobalMember m_GlobalMember;

UserAddDialog::UserAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAddDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("新增用户");
    this->setStyleSheet("#UserAddDialog{background-color: rgb(255, 255, 255)} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

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

UserAddDialog::~UserAddDialog()
{
    databaseoperation.User_DB.close();

    delete ui;
}

void UserAddDialog::on_OKpushButton_pressed()
{
    ui->OKpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void UserAddDialog::on_OKpushButton_released()
{
    if((ui->UserNamelineEdit->text() == "")||
       (ui->PasswdlineEdit->text() == "")||
       (ui->ConfirmPasswdlineEdit->text() == "")||
       (ui->levelcomboBox->currentIndex() == 0))
    {
        SystemMessageDialog m_SystemMessageDialog("各输入框不能为空！");
        m_SystemMessageDialog.exec();
    }
    else
    {
        if(ui->PasswdlineEdit->text() != ui->ConfirmPasswdlineEdit->text())
        {
            SystemMessageDialog m_SystemMessageDialog("两次输入的密码不一致，请重新输入！");
            m_SystemMessageDialog.exec();
            ui->PasswdlineEdit->clear();
            ui->ConfirmPasswdlineEdit->clear();
        }
        else
        {
            QSqlQuery query = databaseoperation.GetUserInfoByName("User", ui->UserNamelineEdit->text());
            if(query.next())
            {
                SystemMessageDialog m_SystemMessageDialog("该用户名已经存在，请重新输入其他用户名！");
                m_SystemMessageDialog.exec();
            }
            else
            {
                m_GlobalMember.IsConfirmed = false;
                ConfirmDialog m_ConfirmDialog("确定要新建用户吗？");
                m_ConfirmDialog.exec();
                if(m_GlobalMember.IsConfirmed)
                {
                    databaseoperation.AddUserInfo("User", ui->UserNamelineEdit->text(), ui->PasswdlineEdit->text(), ui->levelcomboBox->currentText());
                }
            }
        }
    }
    ui->OKpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}
