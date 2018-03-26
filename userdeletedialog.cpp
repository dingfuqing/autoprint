#include <QSqlQuery>
#include <QSqlDriver>

#include "userdeletedialog.h"
#include "ui_userdeletedialog.h"
#include "confirmdialog.h"
#include "systemmessagedialog.h"
#include "globe.h"

extern GlobalMember m_GlobalMember;

UserDeleteDialog::UserDeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDeleteDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("删除用户");
    this->setStyleSheet("#UserDeleteDialog{background-color: rgb(255, 255, 255)} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    model = NULL;
    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
    {
        QSqlQuery query = databaseoperation.GetUserInfoByName("User", m_GlobalMember.UserLevel);

        userlist.clear();
        while(query.next())
        {
            userlist.append(query.value(0).toString());
        }
    }
    FillTypetableView();
}

UserDeleteDialog::~UserDeleteDialog()
{
    databaseoperation.User_DB.close();

    if( model != NULL )
    {
        delete model;
        model = NULL;
    }
    delete ui;
}

void UserDeleteDialog::FillTypetableView()
{
    int m_col = 3;
    int m_row = 0;
    if(userlist.count()%3 == 0)
    {
        m_row = userlist.count()/3;
    }
    else
    {
        m_row = userlist.count()/3 + 1;
    }

    QStandardItem * m_item = NULL;

    if( model != NULL )
    {
        delete model;
        model = NULL;
    }
    model = new QStandardItemModel();
    model->setColumnCount(m_col);
    model->setRowCount(m_row);

    for( int row = 0; row < m_row; row++ )
    {
        for( int col = 0;col < m_col; col++ )
        {
            int m_record = (row*3+col);
            if( m_record < userlist.count() )
            {
                m_item = new QStandardItem(userlist[m_record]);

                if(seluserlist.contains(userlist[m_record]))
                {
                    m_item->setCheckState( Qt::Checked );
                }

                if( ( ( col % 2 == 0 ) && ( row % 2 != 0 ) ) || ( ( col % 2 != 0 ) && ( row % 2 == 0 ) ) )
                {
                    m_item->setBackground( QColor(255, 255, 255) );
                }
                else
                {
                    m_item->setBackground( QColor(220, 221, 223) );
                }

                model->setItem(row, col, m_item);
            }
            else
            {
                col = m_col;
                row = m_row;
            }
        }
    }
    ui->UsertableView->setModel(model);

    ui->UsertableView->verticalHeader()->hide();
    ui->UsertableView->horizontalHeader()->hide();

    int m_RowHeight = 40;
    int m_ColumnWidth = 227;

    for( int i = 0; i < m_col; i++ )
    {
        ui->UsertableView->setColumnWidth(i,m_ColumnWidth);
    }

    for( int i = 0; i < m_row; i++ )
    {
        ui->UsertableView->setRowHeight(i,m_RowHeight);
    }
}

void UserDeleteDialog::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void UserDeleteDialog::on_pushButton_released()
{
    if(seluserlist.count() > 0)
    {
        m_GlobalMember.IsConfirmed = false;
        ConfirmDialog m_ConfirmDialog("确定要删除选定的用户吗？");
        m_ConfirmDialog.exec();
        if(m_GlobalMember.IsConfirmed)
        {
            for(int i = 0; i < seluserlist.count(); i++)
            {
                QString seluser = seluserlist.at(i);
                userlist.removeOne(seluser);
                databaseoperation.DeleteUser("User", seluser);
            }
            seluserlist.clear();
            FillTypetableView();
        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("没有选择要删除的用户！");
        m_SystemMessageDialog.exec();
    }
    ui->pushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void UserDeleteDialog::on_UsertableView_clicked(QModelIndex index)
{
    int listindex = index.row()*3+index.column();
    QString seluser = userlist.at(listindex);
    if(seluserlist.contains(seluser))
    {
        seluserlist.removeOne(seluser);
    }
    else
    {
        seluserlist.append(seluser);
    }
    FillTypetableView();
}
