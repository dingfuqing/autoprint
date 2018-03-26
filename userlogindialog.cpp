
#include <QDesktopWidget>
#include <QSqlQuery>
#include <QSqlDriver>

#include "userlogindialog.h"
#include "ui_userlogindialog.h"

#include "globe.h"
#include "systemmessagedialog.h"

extern GlobalMember m_GlobalMember;
UserLoginDialog::UserLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLoginDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("用户登录");
    this->setStyleSheet("#UserLoginDialog{background-color: rgb(255, 255, 255)} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
    {
        QSqlQuery query = databaseoperation.GetUserInfoByName("User", 5);

        QStringList userlist;
        userlist.clear();
        while(query.next())
        {
            userlist.append(query.value(0).toString());
        }
        ui->UserNamecomboBox->clear();
        ui->UserNamecomboBox->insertItems(0, userlist);
    }
}

UserLoginDialog::~UserLoginDialog()
{
    databaseoperation.User_DB.close();

    delete ui;
}

void UserLoginDialog::on_LoginpushButton_pressed()
{
    ui->LoginpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void UserLoginDialog::on_LoginpushButton_released()
{

    QSqlQuery query = databaseoperation.GetAllContentFromDataBase("User");

    QString username = "";
    QString password = "";
    int level = 0;

    while(query.next())
    {
        username = query.value(0).toString();
        password = query.value(1).toString();
        if((username == ui->UserNamecomboBox->currentText())&&(password == ui->PasswordlineEdit->text()))
        {
            level = query.value(2).toInt();
            m_GlobalMember.UserLevel = level;
            break;
        }
    }

    if(level > 0)
    {
        QDialog::close();
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("用户名或密码不正确，请重新输入！");
        m_SystemMessageDialog.setGeometry(this->x()+(this->width()-m_SystemMessageDialog.width())/2+4,this->y()+(this->height()-m_SystemMessageDialog.height())/2+30,m_SystemMessageDialog.width(),m_SystemMessageDialog.height());
        m_SystemMessageDialog.exec();
    }

    ui->LoginpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}
