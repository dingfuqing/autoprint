#include <QStandardItemModel>
#include <QDesktopWidget>
#include <QRect>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QTimer>
#include <QDateTime>

#include "colordatamanagedialog.h"
#include "ui_colordatamanagedialog.h"
#include "globe.h"
#include "confirmdialog.h"
#include "systemmessagedialog.h"

extern GlobalMember m_GlobalMember;
extern com_para_seting_all m_com_para_seting_all;

ColorDataManageDialog::ColorDataManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorDataManageDialog)
{
   ui->setupUi(this);

    this->setWindowTitle("数据管理");
    this->setStyleSheet("#frame{background-color: rgb(202, 206, 236);border-radius: 5px}"
                        "#ColorDataManageDialog{background-color: rgb(255, 255, 255)} QGroupBox{background-color: rgb(202, 206, 236);border-radius: 5px} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    model = NULL;

    typeindex = 0;
    showview = false;
    printcolor_index = 1;

    ui->TypelineEdit->installEventFilter(this);

    ui->TypetableView->hide();
    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
    {
        QString queryidstr = "";
        QString connectstr = ",";
        QString querycolorstr = "";
        QString queryfinalstr = "";
        int index = 0;

        QSqlQuery query = databaseoperation.GetAllContentFromDataBase("ColorIndex");
        m_GlobalMember.ColorIndexList.clear();
        m_GlobalMember.ColorCodeList.clear();
        while(query.next())
        {
            queryidstr = query.value(0).toString();
            querycolorstr = query.value(1).toString();

            if (querycolorstr.length()>=2)
            {
                m_GlobalMember.ColorCodeList.insert(index, querycolorstr);
                m_GlobalMember.ColorIndexList.insert(index, queryidstr);
                index = index + 1;
            }
        }
    }
    SetOperationOfLevel();
}

ColorDataManageDialog::~ColorDataManageDialog()
{
    databaseoperation.User_DB.close();

    if( model != NULL )
    {
        delete model;
        model = NULL;
    }
    delete ui;
}


void ColorDataManageDialog::SetOperationOfLevel()
{
    switch(m_GlobalMember.UserLevel)
    {
    case 2:
        ui->TypelineEdit->setEnabled(true);
        ui->QuerypushButton->setEnabled(true);
        ui->MarginLBlineEdit->setEnabled(false);

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

        ui->InsertpushButton->setEnabled(true);
        ui->UpdatepushButton->setEnabled(true);
        ui->DeletepushButton->setEnabled(true);

        break;
    }
}

bool ColorDataManageDialog::eventFilter(QObject *target, QEvent *event)
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

void ColorDataManageDialog::FillTypetableView()
{
    int m_col = 3;
    int m_row = 0;
    QString m_editstr;
    QString m_datastr;
    QString m_checkstr;
    QString m_combostr;
    QStringList m_datastrlist;

    if(m_GlobalMember.ColorCodeList.count()%3 == 0)
    {
        m_row = m_GlobalMember.ColorCodeList.count()/3;
    }
    else
    {
        m_row = m_GlobalMember.ColorCodeList.count()/3 + 1;
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

    m_editstr = ui->TypelineEdit->text();

    for( int row = 0; row < m_row; row++ )
    {
        for( int col = 0;col < m_col; col++ )
        {
            int m_record = (row*3+col);
            if( m_record < m_GlobalMember.ColorCodeList.count() )
            {
                m_combostr = m_GlobalMember.ColorIndexList[m_record] + "." +m_GlobalMember.ColorCodeList[m_record];
                m_item = new QStandardItem(m_combostr);
                m_checkstr = m_GlobalMember.ColorIndexList[m_record];
                if( m_checkstr == m_editstr )
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

void ColorDataManageDialog::on_TypetableView_clicked(QModelIndex index)
{
    QString m_editstr;
    QString m_datastr;

    if(index.row()*3+index.column() < m_GlobalMember.ColorCodeList.count())
    {
        typeindex = index.row()*3+index.column();

        m_editstr = m_GlobalMember.ColorIndexList.at(typeindex);
        ui->TypelineEdit->setText(m_editstr);
        ui->TypetableView->hide();

        m_datastr = m_GlobalMember.ColorCodeList.at(typeindex);
        ui->MarginLBlineEdit->setText(m_datastr);
        showview = false;
    }
}

void ColorDataManageDialog::ShowTypetableView()
{
    if(showview)
    {
        ui->TypetableView->show();
    }
}

void ColorDataManageDialog::on_QuerypushButton_pressed()
{
    ui->QuerypushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ColorDataManageDialog::on_QuerypushButton_released()
{
    QuerypushDataInfoHnadle();
    ui->QuerypushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void ColorDataManageDialog::on_InsertpushButton_pressed()
{
    ui->InsertpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ColorDataManageDialog::on_InsertpushButton_released()
{
    QString m_selectstr;
    QString m_colorindexstr;
    QString m_colorinfoxstr;
    QString m_comboinfoxstr;
    unsigned int m_count=0;

    m_colorindexstr = ui->TypelineEdit->text();
    m_colorinfoxstr = ui->MarginLBlineEdit->text();

    if((m_colorindexstr != "")&&(m_colorinfoxstr != ""))
    {
        m_GlobalMember.IsConfirmed = false;
        ConfirmDialog m_ConfirmDialog("确定要插入新数据吗？");
        m_ConfirmDialog.exec();

        if(m_GlobalMember.ColorCodeList.contains(m_comboinfoxstr))
        {
            ConfirmDialog m_ConfirmDialogindex("颜色名称不唯一，请修改颜色名称！");
            m_ConfirmDialogindex.exec();
        }
        else
        {
            if(m_GlobalMember.IsConfirmed)
            {
                m_selectstr = m_selectstr.setNum(printcolor_index);
                m_count = m_GlobalMember.ColorCodeList.count() + 1;
                m_colorindexstr = m_colorindexstr.setNum(m_count,10);

                m_GlobalMember.ColorCodeList.append(m_colorinfoxstr);
                m_GlobalMember.ColorIndexList.append(m_colorindexstr);

                databaseoperation.InsertColorTypeInfo("ColorIndex", m_colorindexstr,
                                                      m_colorinfoxstr,
                                                      m_selectstr);
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

void ColorDataManageDialog::on_UpdatepushButton_pressed()
{
    ui->UpdatepushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ColorDataManageDialog::on_UpdatepushButton_released()
{
    QString m_selectstr;
    QString m_colorindexstr;
    QString m_colorinfoxstr;
    QString m_comboinfoxstr;
    bool m_success;

    m_colorindexstr = ui->TypelineEdit->text();
    m_colorinfoxstr = ui->MarginLBlineEdit->text();

    if((m_colorindexstr != "")&&(m_colorinfoxstr != ""))
    {
        if(m_GlobalMember.ColorIndexList.contains(m_colorindexstr))
        {
            m_GlobalMember.IsConfirmed = false;
            ConfirmDialog m_ConfirmDialog("确定要更新该索引对应的颜色的信息吗？");
            m_ConfirmDialog.exec();
            if(m_GlobalMember.IsConfirmed)
            {
                typeindex = m_colorindexstr.toInt(&m_success,10);
                if ( typeindex>0 )
                {
                    m_GlobalMember.ColorCodeList.replace(typeindex-1, m_colorinfoxstr);

                    m_selectstr = m_selectstr.setNum(printcolor_index);
                    databaseoperation.UpdateColorInfoByBarCode("ColorIndex", m_colorindexstr,
                                                          m_colorinfoxstr,
                                                          m_selectstr);

                    m_GlobalMember.IsUpdate = true;
                }
            }
        }
        else
        {
            m_GlobalMember.IsConfirmed = false;
            ConfirmDialog m_ConfirmDialog("不存在该颜色索引，确定要插入新数据吗？");
            m_ConfirmDialog.exec();

            if(m_GlobalMember.ColorCodeList.contains(m_comboinfoxstr))
            {
                ConfirmDialog m_ConfirmDialogindex("颜色名称不唯一，请修改颜色名称！");
                m_ConfirmDialogindex.exec();
            }
            else
            {
                if(m_GlobalMember.IsConfirmed)
                {
                    m_GlobalMember.ColorCodeList.append(m_colorinfoxstr);
                    m_GlobalMember.ColorIndexList.append(m_colorindexstr);

                    typeindex = m_GlobalMember.ColorCodeList.count();
                    m_selectstr = m_selectstr.setNum(printcolor_index);
                    databaseoperation.InsertColorTypeInfo("ColorIndex", m_colorindexstr,
                                                          m_colorinfoxstr,
                                                          m_selectstr);
                }
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

void ColorDataManageDialog::on_DeletepushButton_pressed()
{
    ui->DeletepushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ColorDataManageDialog::on_DeletepushButton_released()
{
    QString m_colorindexstr;
    QString m_colorinfoxstr;
    QString m_comboinfoxstr;

    m_colorindexstr = ui->TypelineEdit->text();
    m_colorinfoxstr = ui->MarginLBlineEdit->text();
    m_comboinfoxstr = m_colorindexstr + ","+m_colorinfoxstr;

    if((m_colorindexstr != ""))
    {
        m_GlobalMember.IsConfirmed = false;
        ConfirmDialog m_ConfirmDialog("确定要删除该颜色的信息吗？");
        m_ConfirmDialog.exec();
        if(m_GlobalMember.IsConfirmed)
        {
            typeindex = m_GlobalMember.ColorIndexList.indexOf(m_colorindexstr);
            m_GlobalMember.ColorCodeList.removeAt(typeindex);
            m_GlobalMember.ColorIndexList.removeAt(typeindex);

            databaseoperation.DeleteColorContent("ColorIndex", m_colorindexstr);
            ui->TypelineEdit->clear();
            ui->MarginLBlineEdit->clear();

        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("没有要删除的颜色信息！");
        m_SystemMessageDialog.exec();
    }
    ui->DeletepushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void ColorDataManageDialog::QuerypushDataInfoHnadle()
{
    QString m_colorindexstr;

    m_colorindexstr = ui->TypelineEdit->text();
    if(m_colorindexstr != "")
    {
        QSqlQuery query = databaseoperation.GetColorInfoByType("ColorIndex", m_colorindexstr);

        while(query.next())
        {
            //ui->TypelineEdit->setText(query.value(0).toString());
            ui->MarginLBlineEdit->setText(query.value(1).toString());
            printcolor_index = query.value(2).toInt();
            ui->printcolor_comboBox->setCurrentIndex(printcolor_index);
        }
    }
    else
    {
        SystemMessageDialog m_SystemMessageDialog("请先选择颜色再查询！");
        m_SystemMessageDialog.exec();
    }

}

void ColorDataManageDialog::on_TypetableView_pressed(const QModelIndex &index)
{
    QString m_colorindexstr;

    typeindex = index.row()*3+index.column();
    m_colorindexstr = m_GlobalMember.ColorIndexList.at(typeindex);

    if( m_colorindexstr != "")
    {
        QSqlQuery query = databaseoperation.GetColorInfoByType("ColorIndex", m_colorindexstr);

        while(query.next())
        {
            ui->TypelineEdit->setText(query.value(0).toString());
            ui->MarginLBlineEdit->setText(query.value(1).toString());
            printcolor_index = query.value(2).toInt();
            ui->printcolor_comboBox->setCurrentIndex(printcolor_index);
       }
    }
}

void ColorDataManageDialog::on_printcolor_comboBox_currentIndexChanged(int index)
{
    printcolor_index = index;
}
