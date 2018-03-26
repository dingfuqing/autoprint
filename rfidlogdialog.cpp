
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QTimer>
#include <QDateTime>


#include "rfidlogdialog.h"
#include "ui_rfidlogdialog.h"

#include "globe.h"
extern log_authcard m_log_authcard;

RfidlogDialog::RfidlogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RfidlogDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("#InkDataListButton{background-color: rgb(124, 136, 211);color: rgb(255, 255, 255)} "
                        "#Loglabel{color: rgb(255, 255, 255)} "
                        "#ThinDataListButton{background-color: rgb(124, 136, 211);color: rgb(255, 255, 255)} "

                        "#frame{background-color: rgb(202, 206, 236);border-radius: 5px} "
                        "#AuthclearButton{background-color: rgb(120, 116, 213)} "
                        "#AuthSaveButton{background-color: rgb(120, 116, 213)} "
                        "#AuthBackButton{background-color: rgb(120, 116, 213)} "
                        "#frame{background-color: rgb(202, 206, 236);border-radius: 5px} "

                        "#Authframe{background-color: rgb(91, 80, 234)} "
                        "#AuthRightButton{background-color: rgb(124, 136, 211);color: rgb(255, 255, 255)} "
                        "#AuthLeftButton{background-color: rgb(124, 136, 211);color: rgb(255, 255, 255)} "
                        "#AuthLeftendButton{background-color: rgb(124, 136, 211);color: rgb(255, 255, 255)} "
                        "#AuthRightendButton{background-color: rgb(124, 136, 211);color: rgb(255, 255, 255)} "
                        "#tablegroupBox{background-color: rgb(202, 206, 236);border-radius: 5px} "
                        "#IninklogDialog{background-color: rgb(255, 255, 255)} QPushButton{border-radius: 5px} ");

    MessageList.clear();
    logmodel = NULL;
    m_logitem = NULL;
    m_rowcount = 12;

    ShowInkLogData = true;

    LogTotalTablePages = 0;
    LogCurTablePages = 0;

    FirstCardTablePages = 0;
    InitAuthCardlogDialog();
}

RfidlogDialog::~RfidlogDialog()
{

    if( logmodel != NULL )
    {
        delete logmodel;
        logmodel = NULL;
    }

    MessageList.clear();


    delete ui;
}

void RfidlogDialog::on_AuthBackButton_released()
{
    QDialog::close();
}

void RfidlogDialog::InitLogAuthcardSetingData()
{
    memlogmax = 1000;

    for (int i = 0 ;i < memlogmax; i++)
    {
        m_log_authcard.log_id[i] = i;
        //m_log_authcard.log_office[i]="";
    }
}

void RfidlogDialog::ChangeAuthCardLogDataTolist()
{
    unsigned int i = 0;
    QString m_datastr = "";

    if( m_log_authcard.log_number > 0 )
    {
        LogTotalTablePages = (unsigned int )((m_log_authcard.log_number-1)  / m_rowcount);

        if ( FirstCardTablePages == 0 )
        {
            LogCurTablePages = LogTotalTablePages;
        }
        FirstCardTablePages = 1;

    }

    MessageList.clear();
    for ( i = 0; i< m_log_authcard.log_number ;i++)
    {
        m_datastr = m_datastr.setNum(  m_log_authcard.log_id[i]);
        MessageList.append(m_datastr);
        MessageList.append(m_log_authcard.log_office[i]);
    }

}

void RfidlogDialog::InitAuthCardlogDialog()
{
    int m_colmax = 2;

    ChangeAuthCardLogDataTolist();

    int ListRows = MessageList.count()/m_colmax;
    if( logmodel != NULL )
    {
        delete logmodel;
        logmodel = NULL;
    }
    logmodel = new QStandardItemModel();
    logmodel->setColumnCount(m_colmax);    //列
    logmodel->setRowCount(m_rowcount);    //行

    QFont font;
    //font.setFamily("simhei");
    font.setPointSize(12);
    font.setBold(false);
    font.setWeight(50);
    ui->AuthRecordtableView->horizontalHeader()->setFont(font);

    logmodel->setHeaderData(0,Qt::Horizontal, tr("序号"));
    logmodel->setHeaderData(1,Qt::Horizontal, tr("内容"));

    if ( ListRows > 0 )
    {
        for( int i = LogCurTablePages * m_rowcount; ( ( i < LogCurTablePages * m_rowcount + m_rowcount ) && ( i < ListRows ) ); i++ )
        {
            for( int j = 0; j < m_colmax; j++ )
            {
            QString ID_Str;
            ID_Str.setNum(i + 1);
            if( j == 0 )
            {
                m_logitem = new QStandardItem(ID_Str);

                if( i % 2 == 0 )
                {
                    m_logitem->setBackground(QColor(255, 255, 255));
                }
                else
                {
                    m_logitem->setBackground(QColor(220, 221, 223));
                }

                logmodel->setItem(i%m_rowcount,j, m_logitem);
                logmodel->setData(logmodel->index(i%m_rowcount,j), Qt::AlignCenter, Qt::TextAlignmentRole);
            }
            else
            {
                m_logitem = new QStandardItem(MessageList[i*m_colmax+j]);

                if( i % 2 == 0 )
                {
                    m_logitem->setBackground(QColor(255, 255, 255));
                }
                else
                {
                    m_logitem->setBackground(QColor(220, 221, 223));
                }

                logmodel->setItem(i%m_rowcount,j, m_logitem);
                logmodel->setData(logmodel->index(i%m_rowcount,j), Qt::AlignCenter, Qt::TextAlignmentRole);
            }
        }
       }
    }

    ui->AuthRecordtableView->verticalHeader()->hide();

    ui->AuthRecordtableView->setModel(logmodel);

    ui->AuthRecordtableView->setColumnWidth(0, 80);
    ui->AuthRecordtableView->setColumnWidth(1, 660);

    for( int i = 0; i < m_rowcount; i++ )
    {
        ui->AuthRecordtableView->setRowHeight(i, 32);
    }
}


void RfidlogDialog::on_AuthLeftendButton_released()
{
    LogCurTablePages = 0;
    InitAuthCardlogDialog();
}

void RfidlogDialog::on_AuthLeftButton_released()
{
    if( LogCurTablePages > 0 )
    {
        LogCurTablePages--;
    }
    InitAuthCardlogDialog();
}
void RfidlogDialog::on_AuthRightButton_released()
{
    if( LogCurTablePages + 1 <= LogTotalTablePages )
    {
        LogCurTablePages++;
    }
    InitAuthCardlogDialog();
}

void RfidlogDialog::on_AuthRightendButton_released()
{
    ui->AuthRightendButton->setStyleSheet("background-color: rgb(120, 116, 213);");
    if(LogTotalTablePages > 0)
    {
        LogCurTablePages = LogTotalTablePages;
        InitAuthCardlogDialog();
    }
}

void RfidlogDialog::on_AuthSaveButton_released()
{
    QString contentstr;
    QString m_filename;
    QString m_allfilename;
    QString m_pathname;
    unsigned int i = 0;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    m_filename = m_currenttime.toString("yyyy-MM-dd-hh-mm");

    ui->AuthSaveButton->setStyleSheet("background-color: rgb(120, 116, 213);");

    contentstr.clear();
    for ( i = 0; i< m_log_authcard.log_number ;i++)
    {
        contentstr = contentstr + m_log_authcard.log_office[i];
        contentstr = contentstr + "\r\n";
    }


    QDir dir;
    m_pathname=dir.currentPath();
    m_allfilename = m_pathname+"/" + m_filename +".txt";
    QFile file(m_allfilename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (contentstr.length() > 0)
    {
        QTextStream in(&file);
        in.setCodec("utf-8");
        in << contentstr;
        file.flush();
    }
    file.close();
    //QDialog::close();
}

void RfidlogDialog::on_AuthBackButton_pressed()
{
    ui->AuthBackButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void RfidlogDialog::on_AuthSaveButton_pressed()
{
    ui->AuthSaveButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}
