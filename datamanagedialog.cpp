#include <QStandardItemModel>

#include <QDesktopWidget>
#include <QRect>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QTimer>
#include <QDateTime>

#include "datamanagedialog.h"
#include "ui_datamanagedialog.h"
#include "globe.h"
#include "confirmdialog.h"
#include "systemmessagedialog.h"

extern GlobalMember m_GlobalMember;
extern com_para_seting_all m_com_para_seting_all;
DataManageDialog::DataManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataManageDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("数据管理");
    this->setStyleSheet("#frame{background-color: rgb(202, 206, 236);border-radius: 5px}"
                        "#DataManageDialog{background-color: rgb(255, 255, 255)} QGroupBox{background-color: rgb(202, 206, 236);border-radius: 5px} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    model = NULL;

    typeindex = 0;
    showview = false;
    ui->TypelineEdit->installEventFilter(this);

    ui->TypetableView->hide();

    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))//QString  filedir,  QString  filename
    {
        ;
    }

    SetOperationOfLevel();

    ui->MarginLBlineEdit->setValidator(new QIntValidator(0, 1000000, this));
    ui->MarginLWlineEdit->setValidator(new QIntValidator(0, 1000000, this));
    ui->MarginRBlineEdit->setValidator(new QIntValidator(0, 1000000, this));
    ui->MarginRWlineEdit->setValidator(new QIntValidator(0, 1000000, this));

}

DataManageDialog::~DataManageDialog()
{
    databaseoperation.User_DB.close();

    if( model != NULL )
    {
        delete model;
        model = NULL;
    }
    delete ui;
}

void DataManageDialog::SetOperationOfLevel()
{
    switch(m_GlobalMember.UserLevel)
    {
    case 2:
        ui->TypelineEdit->setEnabled(true);
        ui->QuerypushButton->setEnabled(true);
        ui->MarginLBlineEdit->setEnabled(false);
        ui->MarginLWlineEdit->setEnabled(false);
        ui->MarginRBlineEdit->setEnabled(false);
        ui->MarginRWlineEdit->setEnabled(false);

        ui->InsertpushButton->setEnabled(false);
        ui->UpdatepushButton->setEnabled(true);
        ui->DeletepushButton->setEnabled(false);
        break;
    case 3:
    case 4:
    case 5:
        ui->TypelineEdit->setEnabled(true);
        ui->QuerypushButton->setEnabled(true);
        ui->MarginLBlineEdit->setEnabled(true);
        ui->MarginLWlineEdit->setEnabled(true);
        ui->MarginRBlineEdit->setEnabled(true);
        ui->MarginRWlineEdit->setEnabled(true);

        ui->InsertpushButton->setEnabled(true);
        ui->UpdatepushButton->setEnabled(true);
        ui->DeletepushButton->setEnabled(true);

        break;
    }
}

bool DataManageDialog::eventFilter(QObject *target, QEvent *event)
{
    if ( target == ui->TypelineEdit )
    {
        if ( event->type() == QEvent::MouseButtonDblClick )
        {
            showview = false;
            ui->TypetableView->hide();
            ui->TypelineEdit->setFocus();
            ui->TypelineEdit->selectAll();
        }
        else if ( event->type() == QEvent::MouseButtonPress )
        {
            if(!showview)
            {
                ui->TypetableView->setGeometry(50, 130, 700, 400);

                FillTypetableView();
                showview = true;
                QTimer::singleShot(300, this, SLOT(ShowTypetableView()));
            }
            else
            {
                showview = false;
                ui->TypetableView->hide();
            }
        }
    }
    return QWidget::eventFilter(target, event);
}

void DataManageDialog::FillTypetableView()
{
    int m_col = 3;
    int m_row = 0;
    if(m_GlobalMember.BarCodeList.count()%3 == 0)
    {
        m_row = m_GlobalMember.BarCodeList.count()/3;
    }
    else
    {
        m_row = m_GlobalMember.BarCodeList.count()/3 + 1;
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
            if( m_record < m_GlobalMember.BarCodeList.count() )
            {
                m_item = new QStandardItem(m_GlobalMember.BarCodeList[m_record]);

                if(m_GlobalMember.BarCodeList[m_record] == ui->TypelineEdit->text())
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
    ui->TypetableView->setModel(model);

    ui->TypetableView->verticalHeader()->hide();
    ui->TypetableView->horizontalHeader()->hide();

    int m_RowHeight = 40;
    int m_ColumnWidth = 227;

    for( int i = 0; i < m_col; i++ )
    {
        ui->TypetableView->setColumnWidth(i,m_ColumnWidth);
    }

    for( int i = 0; i < m_row; i++ )
    {
        ui->TypetableView->setRowHeight(i,m_RowHeight);
    }
}

void DataManageDialog::on_TypetableView_clicked(QModelIndex index)
{
    if(index.row()*3+index.column() < m_GlobalMember.BarCodeList.count())
    {
        typeindex = index.row()*3+index.column();
        ui->TypelineEdit->setText(m_GlobalMember.BarCodeList.at(typeindex));
        ui->TypetableView->hide();
        showview = false;
    }
}

void DataManageDialog::ShowTypetableView()
{
    if(showview)
    {
        ui->TypetableView->show();
    }
}

void DataManageDialog::on_QuerypushButton_pressed()
{
    ui->QuerypushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void DataManageDialog::on_QuerypushButton_released()
{
    QuerypushDataInfoHnadle();
    ui->QuerypushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void DataManageDialog::on_InsertpushButton_pressed()
{
    ui->InsertpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void DataManageDialog::on_InsertpushButton_released()
{
    if((ui->TypelineEdit->text() != "")&&
       (ui->MarginLBlineEdit->text() != "")&&
       (ui->MarginLWlineEdit->text() != "")&&
       (ui->MarginRBlineEdit->text() != "")&&
       (ui->MarginRWlineEdit->text() != "")
    )
    {
        if(m_GlobalMember.BarCodeList.contains(ui->TypelineEdit->text()))
        {
            m_GlobalMember.IsConfirmed = false;
            ConfirmDialog m_ConfirmDialog("该车型已经存在，是否要更新！");
            m_ConfirmDialog.exec();
            if(m_GlobalMember.IsConfirmed)
            {
                typeindex = m_GlobalMember.BarCodeList.indexOf(ui->TypelineEdit->text());
                m_GlobalMember.BarCodeList.replace(typeindex, ui->TypelineEdit->text());
                databaseoperation.UpdateInfoByBarCode("TypeInfo", ui->TypelineEdit->text(),
                                                      ui->MarginLBlineEdit->text(),
                                                      ui->MarginLWlineEdit->text(),
                                                      ui->MarginRBlineEdit->text(),
                                                      ui->MarginRWlineEdit->text());
            }
        }
        else
        {
            m_GlobalMember.IsConfirmed = false;
            ConfirmDialog m_ConfirmDialog("确定要插入新数据吗？");
            m_ConfirmDialog.exec();
            if(m_GlobalMember.IsConfirmed)
            {
                m_GlobalMember.BarCodeList.append(ui->TypelineEdit->text());

                typeindex = m_GlobalMember.BarCodeList.count();
                databaseoperation.InsertTypeInfo("TypeInfo", ui->TypelineEdit->text(),
                                                      ui->MarginLBlineEdit->text(),
                                                      ui->MarginLWlineEdit->text(),
                                                      ui->MarginRBlineEdit->text(),
                                                      ui->MarginRWlineEdit->text());
            }
        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("各输入框不能为空！");
        m_SystemMessageDialog.exec();
    }
    ui->InsertpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void DataManageDialog::on_UpdatepushButton_pressed()
{
    ui->UpdatepushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void DataManageDialog::on_UpdatepushButton_released()
{
    if((ui->TypelineEdit->text() != "")&&
       (ui->MarginLBlineEdit->text() != "")&&
       (ui->MarginLWlineEdit->text() != "")&&
       (ui->MarginRBlineEdit->text() != "")&&
       (ui->MarginRWlineEdit->text() != "")
       )
    {
        if(m_GlobalMember.BarCodeList.contains(ui->TypelineEdit->text()))
        {
            m_GlobalMember.IsConfirmed = false;
            ConfirmDialog m_ConfirmDialog("确定要更新该车型的信息吗？");
            m_ConfirmDialog.exec();
            if(m_GlobalMember.IsConfirmed)
            {
                typeindex = m_GlobalMember.BarCodeList.indexOf(ui->TypelineEdit->text());
                m_GlobalMember.BarCodeList.replace(typeindex, ui->TypelineEdit->text());

                databaseoperation.UpdateInfoByBarCode("TypeInfo", ui->TypelineEdit->text(),
                                                      ui->MarginLBlineEdit->text(),
                                                      ui->MarginLWlineEdit->text(),
                                                      ui->MarginRBlineEdit->text(),
                                                      ui->MarginRWlineEdit->text());

                m_GlobalMember.IsUpdate = true;
            }
        }
        else
        {
            m_GlobalMember.IsConfirmed = false;
            ConfirmDialog m_ConfirmDialog("不存在该车型， 确定要插入新数据吗？");
            m_ConfirmDialog.exec();
            if(m_GlobalMember.IsConfirmed)
            {
                m_GlobalMember.BarCodeList.append(ui->TypelineEdit->text());

                typeindex = m_GlobalMember.BarCodeList.count();
                databaseoperation.InsertTypeInfo("TypeInfo", ui->TypelineEdit->text(),
                                                      ui->MarginLBlineEdit->text(),
                                                      ui->MarginLWlineEdit->text(),
                                                      ui->MarginRBlineEdit->text(),
                                                      ui->MarginRWlineEdit->text());
            }
        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("各输入框不能为空！");
        m_SystemMessageDialog.exec();
    }
    ui->UpdatepushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void DataManageDialog::on_DeletepushButton_pressed()
{
    ui->DeletepushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void DataManageDialog::on_DeletepushButton_released()
{
    if((ui->TypelineEdit->text() != ""))
    {
        m_GlobalMember.IsConfirmed = false;
        ConfirmDialog m_ConfirmDialog("确定要删除该车型的信息吗？");
        m_ConfirmDialog.exec();
        if(m_GlobalMember.IsConfirmed)
        {
            typeindex = m_GlobalMember.BarCodeList.indexOf(ui->TypelineEdit->text());
            m_GlobalMember.BarCodeList.removeAt(typeindex);
            m_GlobalMember.ContentList.removeAt(typeindex);
            databaseoperation.DeleteContent("PrintContent", ui->TypelineEdit->text());
            databaseoperation.DeleteContent("TypeInfo", ui->TypelineEdit->text());
            ui->TypelineEdit->clear();
            ui->MarginLBlineEdit->clear();
            ui->MarginLWlineEdit->clear();
            ui->MarginRBlineEdit->clear();
            ui->MarginRWlineEdit->clear();
        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("没有要删除的车型信息！");
        m_SystemMessageDialog.exec();
    }
    ui->DeletepushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void DataManageDialog::QuerypushDataInfoHnadle()
{
    if(ui->TypelineEdit->text() != "")
    {
        QSqlQuery query = databaseoperation.GetInfoByType("TypeInfo", ui->TypelineEdit->text());

        while(query.next())
        {
            ui->MarginLBlineEdit->setText(query.value(1).toString());
            ui->MarginLWlineEdit->setText(query.value(2).toString());
            ui->MarginRBlineEdit->setText(query.value(3).toString());
            ui->MarginRWlineEdit->setText(query.value(4).toString());
        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("请先选择车型再查询！");
        m_SystemMessageDialog.exec();
    }

}

void DataManageDialog::on_TypetableView_pressed(const QModelIndex &index)
{

    typeindex = index.row()*3+index.column();
    if(m_GlobalMember.BarCodeList.at(typeindex) != "")
    {
        QSqlQuery query = databaseoperation.GetInfoByType("TypeInfo", ui->TypelineEdit->text());

        while(query.next())
        {
            ui->MarginLBlineEdit->setText(query.value(1).toString());
            ui->MarginLWlineEdit->setText(query.value(2).toString());
            ui->MarginRBlineEdit->setText(query.value(3).toString());
            ui->MarginRWlineEdit->setText(query.value(4).toString());
        }
    }
}
