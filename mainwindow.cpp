#include "QtNetwork/QTcpSocket"
#include<QHostAddress>
#include<QMessageBox>

#include <QDesktopWidget>
#include <QTextCodec>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QStandardPaths>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userlogindialog.h"
#include "usermodifydialog.h"
#include "useradddialog.h"
#include "userdeletedialog.h"
#include "datamanagedialog.h"
#include "colordatamanagedialog.h"
#include "parasytemsetdialog.h"
#include "rfidlogdialog.h"
#include "globe.h"

extern GlobalMember m_GlobalMember;
extern SysPara m_SysPara;
extern log_authcard m_log_authcard;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();
    UserLoginDialog m_UserLoginDialog;
    m_UserLoginDialog.setGeometry((clientRect.width()-m_UserLoginDialog.width())/2,(clientRect.height()-m_UserLoginDialog.height())/2,m_UserLoginDialog.width(),m_UserLoginDialog.height());
    m_UserLoginDialog.exec();
    //m_GlobalMember.UserLevel = 5;

    this->setWindowTitle("青岛一汽生产线喷印系统控制软件");
    this->setStyleSheet(   "#menuBar{background-color: rgb(222, 222, 222)} "
                           "#planframe{background-color: rgb(202, 206, 236);border-radius: 5px}"
                           "#MainWindow{background-color: rgb(255, 255, 255)} QGroupBox{background-color: rgb(202, 206, 236);border-radius: 5px} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");




    showview = false;
    model= NULL;
    m_Timer = NULL;
    typeindex = 0;
    select_color_num = 0;

    VaiableName_a = "100";
    VaiableName_b = "101";
    VaiableName_c = "102";
    VaiableName_d = "103";
    InstAllName = "1";
    SelectPath = "\\";

    socket_sendstartdata = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n<request>";
    socket_senddata = "<setStarted instName=\""+InstAllName+ "\" msgName=\"\\ALERIS\">1</setStarted>";
    socket_sendenddata = "</request>";

    m_GlobalMember.IsUpdate = false;
    m_GlobalMember.plantypelist.clear();
    m_GlobalMember.plancontentlist.clear();

    m_GlobalMember.BarCodeList.clear();
    m_GlobalMember.ContentList.clear();
    m_GlobalMember.FrequencyList.clear();
    m_GlobalMember.TypeList.clear();
    m_GlobalMember.MarginList.clear();

    m_SysPara.changeflag = 0;
    start_printflag = 0;
    ui->PrintInfoButton->setText("停止打印");

    m_SysPara.ipAfirstconectFlag = 0;
    m_SysPara.ipBfirstconectFlag = 0;
    m_SysPara.ipCfirstconectFlag = 0;
    m_SysPara.ipDfirstconectFlag = 0;

    m_log_authcard.log_number = 0;

    checkcodestr = "C180301B0528";
    ui->lineEdit->setText(checkcodestr);
    codebaselength = checkcodestr.length();

    InitLogAuthSetingData();

    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))//QString  filedir,  QString  filename
    {
           QString querystr = "";
           int i_data = 0;
           int index = 0;

           QSqlQuery query = databaseoperation.GetAllContentFromDataBase("PrintContent");

           while(query.next())
           {
               i_data = query.value(2).toInt();
               for(index = 0; (m_GlobalMember.FrequencyList.count() != 0)&&(index < m_GlobalMember.FrequencyList.count()); index++)
               {
                   if(i_data > m_GlobalMember.FrequencyList.at(index))
                   {
                       break;
                   }
               }
               m_GlobalMember.FrequencyList.insert(index, i_data);
               querystr = query.value(0).toString();
               m_GlobalMember.BarCodeList.insert(index, querystr);
               querystr = query.value(1).toString();
               m_GlobalMember.ContentList.insert(index, querystr);
               i_data = query.value(3).toInt();
               m_GlobalMember.TypeList.insert(index, i_data);
           }

           query = databaseoperation.GetSysPara("SysPara");

           QList<QString> SysParaList;
           SysParaList.clear();
           while(query.next())
           {
               SysParaList.append(query.value(2).toString());
           }
           m_SysPara.FlushTimer = SysParaList[0].toInt();
           m_SysPara.PrintMode = SysParaList[1].toInt();

           m_SysPara.Ip_A = SysParaList[2];
           m_SysPara.Ip_B = SysParaList[3];
           m_SysPara.Ip_C = SysParaList[4];
           m_SysPara.Ip_D = SysParaList[5];
    }

    auto_socket_a  =  new QTcpSocket(this);
    server_ip_a =  m_SysPara.Ip_A;
    server_port_a = 10001;
    auto_socket_a->connectToHost(server_ip_a, server_port_a,QTcpSocket::ReadWrite);
    connect(this->auto_socket_a,SIGNAL(connected()),this,SLOT(autoAconnected()));
    connect(auto_socket_a,SIGNAL(disconnected()),this,SLOT(hasnotconnectedA()));//如果断开连接
    connect(auto_socket_a,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(erroA()));//显示错误


    auto_socket_b  =  new QTcpSocket(this);
    server_ip_b =  m_SysPara.Ip_B;
    server_port_b = 10001;
    auto_socket_b->connectToHost(server_ip_b, server_port_b,QTcpSocket::ReadWrite);
    connect(this->auto_socket_b,SIGNAL(connected()),this,SLOT(autoBconnected()));
    connect(auto_socket_b,SIGNAL(disconnected()),this,SLOT(hasnotconnectedB()));//如果断开连接
    connect(auto_socket_b,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(erroB()));//显示错误


    auto_socket_c  =  new QTcpSocket(this);
    server_ip_c =  m_SysPara.Ip_C;
    server_port_c = 10001;
    auto_socket_c->connectToHost(server_ip_c, server_port_c,QTcpSocket::ReadWrite);
    connect(this->auto_socket_c,SIGNAL(connected()),this,SLOT(autoCconnected()));
    connect(auto_socket_c,SIGNAL(disconnected()),this,SLOT(hasnotconnectedC()));//如果断开连接
    connect(auto_socket_c,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(erroC()));//显示错误

    auto_socket_d  =  new QTcpSocket(this);
    server_ip_d =  m_SysPara.Ip_D;
    server_port_d = 10001;
    auto_socket_d->connectToHost(server_ip_d, server_port_d,QTcpSocket::ReadWrite);
    connect(this->auto_socket_d,SIGNAL(connected()),this,SLOT(autoDconnected()));
    connect(auto_socket_d,SIGNAL(disconnected()),this,SLOT(hasnotconnectedD()));//如果断开连接
    connect(auto_socket_d,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(erroD()));//显示错误

    aixLabel = new QLabel;
    timeLabel = new QLabel;
    aixLabel->setMinimumWidth(650);
    aixLabel->setText(tr(""));
    ui->statusBar->addWidget(aixLabel);
    //ui->statusBar->showMessage("aixLabel",3000);//3s后关闭

    //ui->TypelineEdit->installEventFilter(this);
    ui->lineEdit->installEventFilter(this);
    ui->TypetableView->hide();
    HandleTimer();
    ui->ColorSelect_comboBox->setCurrentIndex(m_SysPara.PrintMode);
    ui->ClearNoz_comboBox->setCurrentIndex(m_SysPara.FlushTimer);

    connect(ui->Userlogaction, SIGNAL(triggered()), this, SLOT(userlog()));
    connect(ui->Modifyaction, SIGNAL(triggered()), this, SLOT(usermodify()));
    connect(ui->Useraddaction, SIGNAL(triggered()), this, SLOT(useradd()));
    connect(ui->Deleteaction, SIGNAL(triggered()), this, SLOT(userdelete()));
    connect(ui->Exitaction, SIGNAL(triggered()), this, SLOT(userexit()));
    connect(ui->Datamanger, SIGNAL(triggered()), this, SLOT(datamanage()));

    connect(ui->Colormanger, SIGNAL(triggered()), this, SLOT(colordatamanage()));

    connect(ui->logfileinfo, SIGNAL(triggered()), this, SLOT(showlogfile()));
    connect(ui->setsysetm, SIGNAL(triggered()), this, SLOT(sysparaset()));

    UserLevelControlHandle();    
}

void MainWindow::hasnotconnectedA()
{
    QString logdatastr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " 断开连接！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " 断开连接！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::erroA()
{       
    QString logdatastr;
    QString errostring;

    errostring = auto_socket_d->errorString();//此处为错误打印
    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " " + errostring + " 连接错误！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " " + errostring + " 连接错误！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::DatafromcsvTotablePrint()
{
    QString m_alldatainfo;
    QString m_linedatainfo;
    QString m_linedatatype;
    unsigned int m_recordnum = 0;
    unsigned int i = 0;

    QString m_pathstr;
    QStringList m_alldatainfolist;
    QStringList m_pathinfolist;
    QStringList m_lineinfolist;
    QStringList m_linecombolist;

    m_pathinfolist = QStandardPaths::standardLocations(QStandardPaths::DataLocation);
    m_pathstr = m_pathinfolist.at(2);
    QFile autoinfofile(m_pathstr + "/auto.csv");
    if(autoinfofile.open(QIODevice::ReadOnly))
    {
        m_alldatainfo = autoinfofile.readAll();
        m_alldatainfolist=m_alldatainfo.split("\r\n");
        m_recordnum = m_alldatainfolist.count();

        m_linecombolist.clear();
        for (i=0; i<m_recordnum; i++)
        {
            m_linedatainfo = m_alldatainfolist.at(i);
            if (m_linedatainfo.length()>0)
            {
                m_lineinfolist = m_linedatainfo.split(",");
                m_linedatatype = m_lineinfolist.at(2);
                if (m_linedatatype.length()>0)
                {
                    m_linecombolist.append(m_linedatatype);
                }
            }
        }

    }
    m_linecombolist.sort();
    m_linecombolist.removeDuplicates();
    autoinfofile.close();

}

void MainWindow::DatafromcsvTotableType()
{
    QFile autoinfofile("auto.csv");
    if(autoinfofile.open(QIODevice::ReadOnly))
    {

    }
    autoinfofile.close();
}

void MainWindow::DatafromcsvTotable()
{
    DatafromcsvTotablePrint();
    DatafromcsvTotableType();
}


void MainWindow::hasnotconnectedB()
{
    QString logdatastr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " 断开连接！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " 断开连接！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::erroB()
{
    QString logdatastr;
    QString errostring;

    errostring = auto_socket_d->errorString();//此处为错误打印
    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " " + errostring + " 连接错误！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " " + errostring + " 连接错误！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::hasnotconnectedC()
{
    QString logdatastr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " 断开连接！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " 断开连接！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::erroC()
{
    QString logdatastr;
    QString errostring;

    errostring = auto_socket_d->errorString();//此处为错误打印
    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " " + errostring + " 连接错误！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " " + errostring + " 连接错误！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::hasnotconnectedD()
{
    QString logdatastr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " 断开连接！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " 断开连接！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

void MainWindow::erroD()
{
    QString logdatastr;
    QString errostring;

    errostring = auto_socket_d->errorString();//此处为错误打印
    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " " + errostring + " 连接错误！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " " + errostring + " 连接错误！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;
}

MainWindow::~MainWindow()
{
    delete ui;

    if (auto_socket_a != NULL)
    {
        auto_socket_a->close();
        delete auto_socket_a;
        auto_socket_a = NULL;
    }

    if (auto_socket_b != NULL)
    {
        auto_socket_b->close();
        delete auto_socket_b;
        auto_socket_b = NULL;
    }

    if (auto_socket_c != NULL)
    {
        auto_socket_c->close();
        delete auto_socket_c;
        auto_socket_c = NULL;
    }

    if (auto_socket_b != NULL)
    {
        auto_socket_d->close();
        delete auto_socket_d;
        auto_socket_d = NULL;
    }

    if( model != NULL )
    {
        delete model;
        model = NULL;
    }


    if( m_Timer != NULL )
    {
        if(m_Timer->isActive())
        {
            m_Timer->stop();
        }
        delete m_Timer;
        m_Timer = NULL;
    }

    databaseoperation.User_DB.close();

}

void MainWindow::Delay_MSec_Suspend(unsigned int msec)
{
    QTime _Timer = QTime::currentTime();

    QTime _NowTimer;
    do{
              _NowTimer=QTime::currentTime();
    }while (_Timer.msecsTo(_NowTimer)<=msec);

}

void MainWindow::UserLevelControlHandle()
{

   if(m_GlobalMember.UserLevel<4)
   {
       ui->TypelineEdit->setEnabled(false);
       ui->DatalineEdit->setEnabled(false);
       ui->MarginLBlineEdit->setEnabled(false);
       ui->MarginLWlineEdit->setEnabled(false);
       ui->MarginRBlineEdit->setEnabled(false);
       ui->MarginRWlineEdit->setEnabled(false);

       ui->ColorSelect_comboBox->setEnabled(false);
       ui->ClearNoz_comboBox->setEnabled(false);
       ui->SelectFile_comboBox->setEnabled(false);
   }
   else
   {
       ui->TypelineEdit->setEnabled(true);
       ui->DatalineEdit->setEnabled(true);
       ui->MarginLBlineEdit->setEnabled(true);
       ui->MarginLWlineEdit->setEnabled(true);
       ui->MarginRBlineEdit->setEnabled(true);
       ui->MarginRWlineEdit->setEnabled(true);

       ui->ColorSelect_comboBox->setEnabled(true);
       ui->ClearNoz_comboBox->setEnabled(true);
       ui->SelectFile_comboBox->setEnabled(true);
   }
}

void MainWindow::HandleTimer()
{
    m_Timer = new QTimer( this );
    m_Timer->setSingleShot( false );
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(ProcessTimeThing()));

    m_Timer->start(1000);
}

void MainWindow::ProcessTimeThing()
{
    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    //aixLabel->setText("当前的消息信息："+currtimestr);
    //ui->statusBar->addWidget(aixLabel);

    timeLabel->setText(currtimestr);
    ui->statusBar->addWidget(timeLabel);
}

void MainWindow::autoAconnected()
{
    QString logdatastr;
    QByteArray sendmsg;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_a + " 连接成功！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_a + " 连接成功！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    connect(this->auto_socket_a,SIGNAL(readyRead()),this,SLOT(HandleAutoReadAMessages()));
    sendmsg = socket_sendstartdata.toLatin1();
    SendMessageToMachineSign(1, sendmsg);
}

void MainWindow::autoBconnected()
{
    QString logdatastr;
    QByteArray sendmsg;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_b + " 连接成功！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_b + " 连接成功！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    connect(this->auto_socket_b,SIGNAL(readyRead()),this,SLOT(HandleAutoReadBMessages()));
    sendmsg = socket_sendstartdata.toLatin1();
    SendMessageToMachineSign(2, sendmsg);
}


void MainWindow::autoCconnected()
{
    QString logdatastr;
    QByteArray sendmsg;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_c + " 连接成功！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_c + " 连接成功！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    connect(this->auto_socket_c,SIGNAL(readyRead()),this,SLOT(HandleAutoReadCMessages()));
    sendmsg = socket_sendstartdata.toLatin1();
    SendMessageToMachineSign(3, sendmsg);
}


void MainWindow::autoDconnected()
{
    QString logdatastr;
    QByteArray sendmsg;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");
    aixLabel->setText("当前的消息信息："+ server_ip_c + " 连接成功！" + currtimestr);
    ui->statusBar->addWidget(aixLabel);

    logdatastr = "控制器 " + server_ip_d + " 连接成功！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    connect(this->auto_socket_d,SIGNAL(readyRead()),this,SLOT(HandleAutoReadDMessages()));

    sendmsg = socket_sendstartdata.toLatin1();
    SendMessageToMachineSign(4, sendmsg);

}

void MainWindow::InitLogAuthSetingData()
{
    unsigned int m_memlogmax = 1000;

    for (int i = 0 ;i < m_memlogmax; i++)
    {
        m_log_authcard.log_id[i] = i;
        m_log_authcard.log_office[i]="";
    }
}

void MainWindow::SendAutoReadMessages(unsigned int type, QByteArray msg)
{
    QString logdatastr;
    QString receivestr;
    QString rebackstra;
    QString getVaiablestr;


    QString  m_year = 0;
    QString  m_month = 0;
    QString  m_day = 0;

    QString  m_hour = 0;
    QString  m_minute = 0;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    m_year = m_currenttime.toString("yyyy");
    m_month = m_currenttime.toString("MM");
    m_day = m_currenttime.toString("dd");
    m_hour = m_currenttime.toString("hh");
    m_minute = m_currenttime.toString("mm");

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    receivestr = codec->toUnicode(msg);

    logdatastr = "控制器发送的信息 " + receivestr + " " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    rebackstra = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    if (receivestr.contains(rebackstra))
    {
        getVaiablestr = "<getVariable  name=\""+ VaiableName_a + "\" \/>";
        SendMessageToMachineSign(type,getVaiablestr);
    }

    rebackstra = "<getVariable ok=\"1\">";
    if (receivestr.contains(rebackstra))
    {
        getVaiablestr = "<listVariables instName=\""+ InstAllName +"\" />";
        SendMessageToMachineSign(type,getVaiablestr);
    }

    rebackstra = "</name></listVariables>";
    if (receivestr.contains(rebackstra))
    {
        getVaiablestr = "<listMessages instName=\""+ InstAllName +"\" />";
        SendMessageToMachineSign(type,getVaiablestr);
    }

    rebackstra = "</name></listMessages>";
    if (receivestr.contains(rebackstra))
    {
        getVaiablestr = "<setClock  year=\"" + m_year + "\" month=\""+ m_month +  "\" day=\""+ m_day + "\" hour=\""+ m_hour + "\" minute=\""+ m_minute + "\" />";
        SendMessageToMachineSign(type,getVaiablestr);
    }

    rebackstra = "<setClock ok=\"1\"/>";
    if (receivestr.contains(rebackstra))
    {
        getVaiablestr = "<setClock  year=\"" + m_year + "\" month=\""+ m_month +  "\" day=\""+ m_day + "\" hour=\""+ m_hour + "\" minute=\""+ m_minute + "\" />";
        //SendMessageToMachineSign(type,getVaiablestr);
    }
}

void MainWindow::HandleAutoReadAMessages()
{
    QByteArray msg;
    msg = auto_socket_a->readAll();

    SendAutoReadMessages(1, msg);
}

void MainWindow::HandleAutoReadBMessages()
{
   QByteArray msg;
   msg = auto_socket_b->readAll();
   SendAutoReadMessages(2, msg);
}

void MainWindow::HandleAutoReadCMessages()
{
   QByteArray msg;
   msg = auto_socket_c->readAll();
   SendAutoReadMessages(3, msg);
}

void MainWindow::HandleAutoReadDMessages()
{
   QByteArray msg;
   msg = auto_socket_d->readAll();
   SendAutoReadMessages(4, msg);
}


void MainWindow::userlog()
{
    UserLoginDialog m_UserLoginDialog;
    m_UserLoginDialog.setGeometry(this->x()+(this->width()-m_UserLoginDialog.width())/2,this->y()+(this->height()-m_UserLoginDialog.height())/2,m_UserLoginDialog.width(),m_UserLoginDialog.height());
    m_UserLoginDialog.exec();

    UserLevelControlHandle();
    /*
    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
    {
        ;
    }
    SetOperationOfLevel();
    */
}

void MainWindow::usermodify()
{
    if(m_GlobalMember.UserLevel >=4 )
    {
        UserModifyDialog m_UserModifyDialog;
        m_UserModifyDialog.setGeometry(this->x()+(this->width()-m_UserModifyDialog.width())/2+4,this->y()+(this->height()-m_UserModifyDialog.height())/2+30,m_UserModifyDialog.width(),m_UserModifyDialog.height());
        m_UserModifyDialog.exec();
        /*
        if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
        {
            ;
        }
        */
    }
}

void MainWindow::useradd()
{
    if(m_GlobalMember.UserLevel >=4 )
    {
        UserAddDialog m_UserAddDialog;
        m_UserAddDialog.setGeometry(this->x()+(this->width()-m_UserAddDialog.width())/2+4,this->y()+(this->height()-m_UserAddDialog.height())/2+30,m_UserAddDialog.width(),m_UserAddDialog.height());
        m_UserAddDialog.exec();
        /*
        if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
        {
            ;
        }
        */
    }
}

void MainWindow::userdelete()
{
    if(m_GlobalMember.UserLevel >=4 )
    {
        UserDeleteDialog m_UserDeleteDialog;
        m_UserDeleteDialog.setGeometry(this->x()+(this->width()-m_UserDeleteDialog.width())/2+4,this->y()+(this->height()-m_UserDeleteDialog.height())/2+30,m_UserDeleteDialog.width(),m_UserDeleteDialog.height());
        m_UserDeleteDialog.exec();
        /*
        if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
        {
            ;
        }
        */
    }
}

void MainWindow::userexit()
{
    if ( m_GlobalMember.UserLevel >= 4 )
    {
        m_GlobalMember.UserLevel = 0;
        QApplication* app;
        app->quit();
        //app->exit(0);
    }
}

void MainWindow::datamanage()
{

    if(m_GlobalMember.UserLevel >=4 )
    {
        DataManageDialog m_DataManageDialog;
        m_DataManageDialog.setGeometry(this->x()+(this->width()-m_DataManageDialog.width())/2+4,this->y()+(this->height()-m_DataManageDialog.height())/2+30,m_DataManageDialog.width(),m_DataManageDialog.height());
        m_DataManageDialog.exec();

        if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
        {
            ;
        }
        if (m_GlobalMember.IsUpdate)
        {
            UpdateDataofIndex(typeindex);
            m_GlobalMember.IsUpdate = false;
        }
    }
}

void MainWindow::colordatamanage()
{

    if(m_GlobalMember.UserLevel >=4 )
    {
        ColorDataManageDialog m_ColorDataManageDialog;
        m_ColorDataManageDialog.setGeometry(this->x()+(this->width()-m_ColorDataManageDialog.width())/2+4,this->y()+(this->height()-m_ColorDataManageDialog.height())/2+30,m_ColorDataManageDialog.width(),m_ColorDataManageDialog.height());
        m_ColorDataManageDialog.exec();

        if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
        {
            ;
        }
        if (m_GlobalMember.IsUpdate)
        {
            //UpdateDataofIndex(typeindex);
            m_GlobalMember.IsUpdate = false;
        }
    }
}

void MainWindow::showlogfile()
{

    if(m_GlobalMember.UserLevel >=4 )
    {
        RfidlogDialog m_RfidlogDialog;
        m_RfidlogDialog.setGeometry(this->x()+(this->width()-m_RfidlogDialog.width())/2+4,this->y()+(this->height()-m_RfidlogDialog.height())/2+30,m_RfidlogDialog.width(),m_RfidlogDialog.height());
        m_RfidlogDialog.exec();
    }

}
void MainWindow::sysparaset()
{
    if(m_GlobalMember.UserLevel >=4 )
    {
        QString m_valuedata;

        ParaSytemSetDialog m_ParaSytemSetDialog;
        m_ParaSytemSetDialog.setGeometry(this->x()+(this->width()-m_ParaSytemSetDialog.width())/2+4,this->y()+(this->height()-m_ParaSytemSetDialog.height())/2+30,m_ParaSytemSetDialog.width(),m_ParaSytemSetDialog.height());
        m_ParaSytemSetDialog.exec();

        if(m_SysPara.changeflag == 1)
        {
            m_valuedata = m_SysPara.Ip_A;
            databaseoperation.UpdateSysParaByID("SysPara", "3", m_valuedata);
            m_valuedata = m_SysPara.Ip_B;
            databaseoperation.UpdateSysParaByID("SysPara", "4", m_valuedata);
            m_valuedata = m_SysPara.Ip_C;
            databaseoperation.UpdateSysParaByID("SysPara", "5", m_valuedata);
            m_valuedata = m_SysPara.Ip_D;
            databaseoperation.UpdateSysParaByID("SysPara", "6", m_valuedata);

            //QMessageBox::about(this, "提示", "连接控制器的IP地址发生变动请关闭应用程序。\n然后在重新再打开程序！");
            QMessageBox box(QMessageBox::Warning,"提示", "连接控制器的IP地址发生变动请关闭应用程序。\n然后在重新再打开程序！");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
    }
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if ( target == ui->TypelineEdit )
    {
        if(m_GlobalMember.UserLevel >= 4)
        {
            if ( event->type() == QEvent::MouseButtonPress )
            {
                if(showview)
                {
                    showview = false;
                    ui->TypetableView->hide();
                }
                else
                {
                    showview = true;
                    ui->TypetableView->show();
                    ui->TypetableView->setGeometry(50, 120, 700, 370);

                    FillTypetableView();
                }
            }
        }

    }
    if ( target == ui->lineEdit )
    {
        if(m_GlobalMember.UserLevel >= 4)
        {
            if ( event->type() == QEvent::MouseButtonPress )
            {
               ;
            }
        }

    }
    return QWidget::eventFilter(target, event);
}



void MainWindow::SendMessageToMachine(QString SendMessage)
{
    //Delay_MSec_Suspend(200);
    if (select_color_num == 0 )//黑色
    {
        auto_socket_a->write(SendMessage.toLatin1());
        //auto_socket_c->write(SendMessage.toLatin1());
    }
    else
    {
        //auto_socket_b->write(SendMessage.toLatin1());
        //auto_socket_d->write(SendMessage.toLatin1());
    }
    //Delay_MSec_Suspend(300);
}

void MainWindow::SendMessageToMachineSign(unsigned int type, QString SendMessage)
{
   //Delay_MSec_Suspend(200);
   switch( type )
   {
    case 1:
      auto_socket_a->write(SendMessage.toLatin1());
      break;
   case 2:
      auto_socket_b->write(SendMessage.toLatin1());
      break;
   case 3:
      auto_socket_c->write(SendMessage.toLatin1());
      break;
   case 4:
      auto_socket_d->write(SendMessage.toLatin1());
      break;
   default:
       auto_socket_a->write(SendMessage.toLatin1());
       auto_socket_b->write(SendMessage.toLatin1());
       auto_socket_c->write(SendMessage.toLatin1());
       auto_socket_d->write(SendMessage.toLatin1());
      break;
   }
   Delay_MSec_Suspend(20);
}

void MainWindow::FillTypetableView()
{
    m_GlobalMember.BarCodeList.clear();
    m_GlobalMember.ContentList.clear();
    m_GlobalMember.FrequencyList.clear();
    m_GlobalMember.TypeList.clear();
    QString querystr = "";
    int i_data = 0;
    int index = 0;
    int count = 0;

    if(databaseoperation.CreateConnection("DataBase", "CCAuto.s3db"))
    {
        QSqlQuery query = databaseoperation.GetAllContentFromDataBase("PrintContent");
        while(query.next())
        {
            i_data = query.value(2).toInt();
            count = m_GlobalMember.FrequencyList.count();
            for(index = 0; (count != 0)&&(index < count ); index++)
            {
                if(i_data > m_GlobalMember.FrequencyList.at(index))
                {
                    break;
                }
            }
            m_GlobalMember.FrequencyList.insert(index, i_data);
            querystr = query.value(0).toString();
            m_GlobalMember.BarCodeList.insert(index, querystr);
            querystr = query.value(1).toString();
            m_GlobalMember.ContentList.insert(index, querystr);
            i_data = query.value(3).toInt();
            m_GlobalMember.TypeList.insert(index, i_data);
        }
    }

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

void MainWindow::UpdateDataofIndex(unsigned int typeindex)
{
    QString m_messagestr;

    ui->TypelineEdit->setText(m_GlobalMember.BarCodeList.at(typeindex));

    m_messagestr = m_GlobalMember.ContentList.at(typeindex);
    ui->DatalineEdit->setText(m_messagestr);
    m_GlobalMember.FrequencyList[typeindex]++;
    QString frequency = "";
    frequency.setNum(m_GlobalMember.FrequencyList[typeindex]);
    QString type = "";
    type.setNum(m_GlobalMember.TypeList[typeindex]);
    databaseoperation.UpdateContentByName("PrintContent", m_GlobalMember.BarCodeList.at(typeindex),
                                          m_GlobalMember.ContentList.at(typeindex), frequency, type);

    QSqlQuery query = databaseoperation.GetInfoByType("TypeInfo", ui->TypelineEdit->text());

    while(query.next())
    {
        ui->MarginLBlineEdit->setText(query.value(1).toString());
        ui->MarginLWlineEdit->setText(query.value(2).toString());
        ui->MarginRBlineEdit->setText(query.value(3).toString());
        ui->MarginRWlineEdit->setText(query.value(4).toString());
    }
    combomessage = m_messagestr.split(" ");
    ComboSendMessagesetVariable();
}

void MainWindow::on_TypetableView_clicked(const QModelIndex &index)
{
    if(index.row()*3+index.column() < m_GlobalMember.BarCodeList.count())
       {
           ui->TypetableView->hide();
           showview = false;
           typeindex = index.row()*3+index.column();
           UpdateDataofIndex(typeindex);
       }
}

void MainWindow::on_ColorSelect_comboBox_currentIndexChanged(int index)
{
    QString  m_valuedata;

    m_SysPara.PrintMode = index;
    select_color_num = index;

    m_valuedata = m_valuedata.setNum(m_SysPara.PrintMode);
    databaseoperation.UpdateSysParaByID("SysPara", "2", m_valuedata);
}

void MainWindow::on_ClearNoz_comboBox_currentIndexChanged(int index)
{
    m_SysPara.FlushTimer = index;
    QString  m_valuedata;

    m_valuedata = m_valuedata.setNum(m_SysPara.FlushTimer);
    databaseoperation.UpdateSysParaByID("SysPara", "1", m_valuedata);
}

void MainWindow::on_ClearButton_released()
{
    QString logdatastr;
    QString aixLabelstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    ui->ClearButton->setStyleSheet("background-color: rgb(120, 116, 213);");

    logdatastr = "开始预喷 " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：开始预喷 " + currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);


    DatafromcsvTotable();
}


void MainWindow::on_PrintInfoButton_released()
{
    QString logdatastr;
    QString aixLabelstr;
    QString flagstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    ui->PrintInfoButton->setStyleSheet("background-color: rgb(120, 116, 213);");

    if (start_printflag == 0)
    {
        SelectFilecomboBoxCurrent();
        start_printflag = 1;
        ui->PrintInfoButton->setText("开始打印");
    }
    else
    {
        start_printflag = 0;
        ui->PrintInfoButton->setText("停止打印");
    }
    logdatastr = "开始打印 " + server_ip_a + " 连接成功！" + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：开始打印 " + currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    socket_senddata = "<select instName=\"" + InstAllName + "\" msgName=\"" + SelectPath + "ALERIS\" />";

    flagstr = flagstr.setNum(start_printflag);
    socket_senddata = "<setStarted instName=\"" + InstAllName + "\">"+ flagstr+ "</setStarted>";
    SendMessageToMachineSign(0, socket_senddata);
}

void MainWindow::SelectFilecomboBoxCurrent()
{
    QString logdatastr;
    QString aixLabelstr;
    QString selectstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    selectstr = ui->SelectFile_comboBox->currentText();
    logdatastr = "选择文件 " + selectstr + " " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：选择文件 " + selectstr + " " +currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    socket_senddata = "<select instName=\"" + InstAllName + "\" msgName=\"" + SelectPath + selectstr + "\"\ />";
    SendMessageToMachineSign(0, socket_senddata);
}

void MainWindow::on_SelectFile_comboBox_currentIndexChanged(int index)
{
    unsigned int m_index;
    m_index = index;
    SelectFilecomboBoxCurrent();
}

void MainWindow::on_MarginLBlineEdit_textChanged(const QString &arg1)
{
    QString logdatastr;
    QString aixLabelstr;
    QString selectstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    selectstr = ui->MarginLBlineEdit->text();
    logdatastr = "边距设置LB " + selectstr + " " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：边距设置LB " + selectstr + " " +currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    socket_senddata = "<setMarkerMargin instName=\"" + InstAllName + "\">" + selectstr + "</setMarkerMargin>";
    SendMessageToMachineSign(1, socket_senddata);
}

void MainWindow::on_MarginLWlineEdit_textChanged(const QString &arg1)
{
    QString logdatastr;
    QString aixLabelstr;
    QString selectstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    selectstr = ui->MarginLWlineEdit->text();
    logdatastr = "边距设置LW " + selectstr + " " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：边距设置LW " + selectstr + " " +currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    socket_senddata = "<setMarkerMargin instName=\"" + InstAllName + "\">" + selectstr + "</setMarkerMargin>";
    SendMessageToMachineSign(2, socket_senddata);
}

void MainWindow::on_MarginRBlineEdit_textChanged(const QString &arg1)
{
    QString logdatastr;
    QString aixLabelstr;
    QString selectstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    selectstr = ui->MarginRBlineEdit->text();
    logdatastr = "边距设置RB " + selectstr + " " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：边距设置RB " + selectstr + " " +currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    socket_senddata = "<setMarkerMargin instName=\"" + InstAllName + "\">" + selectstr + "</setMarkerMargin>";
    SendMessageToMachineSign(3, socket_senddata);
}

void MainWindow::on_MarginRWlineEdit_textChanged(const QString &arg1)
{
    QString logdatastr;
    QString aixLabelstr;
    QString selectstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    selectstr = ui->MarginRWlineEdit->text();
    logdatastr = "边距设置RW " + selectstr + " " + currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：边距设置RW " + selectstr + " " +currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    socket_senddata = "<setMarkerMargin instName=\"" + InstAllName + "\">" + selectstr + "</setMarkerMargin>";
    SendMessageToMachineSign(4, socket_senddata);
}


void MainWindow::on_SendDataButton_pressed()
{
   ui->SendDataButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void MainWindow::ComboSendMessagesetVariable()
{
    QString combostr_a;
    QString combostr_b;
    QString combostr_c;
    QString combostr_d;
    unsigned int m_count = 0;

    m_count = combomessage.count();
    if (m_count > 0 )
    {
        combostr_a = "<setVariable name=\"" + VaiableName_a + "\">"+ combomessage.at(0) + "</setVariable>";
        SendMessageToMachine(combostr_a);
        if (m_count > 1)
        {
             combostr_b = "<setVariable name=\"" + VaiableName_b + "\">"+ combomessage.at(1) + "</setVariable>";
             SendMessageToMachine(combostr_b);
             if (m_count > 2)
             {
                 combostr_c = "<setVariable name=\"" + VaiableName_c + "\">"+ combomessage.at(2) + "</setVariable>";
                 SendMessageToMachine(combostr_c);
                 if (m_count > 3)
                 {
                     combostr_d = "<setVariable name=\"" + VaiableName_d + "\">"+ combomessage.at(3) + "</setVariable>";
                     SendMessageToMachine(combostr_d);
                 }
             }
        }
    }
}

void MainWindow::PrepareSendDataInfohandle()
{
    QString m_messagestr;
    QStringList m_messagestrlist;

    m_messagestr = ui->DatalineEdit->text();
    m_messagestrlist = m_messagestr.split(" ");

    combomessage.clear();
    combomessage.append(m_messagestrlist[1]);
    combomessage.append(m_messagestrlist[4]);

    ComboSendMessagesetVariable();
}

void MainWindow::on_SendDataButton_released()
{

    QString logdatastr;
    QString aixLabelstr;

    QDateTime m_currenttime = QDateTime::currentDateTime();
    currtimestr = m_currenttime.toString("yyyy-MM-dd hh:mm:ss");

    ui->SendDataButton->setStyleSheet("background-color: rgb(120, 116, 213);");

    logdatastr = "发送数据 "+ currtimestr;
    m_log_authcard.log_office[m_log_authcard.log_number] = logdatastr;
    m_log_authcard.log_number = m_log_authcard.log_number +1;

    aixLabelstr = "当前的消息信息：发送数据 " + currtimestr;
    aixLabel->setText(aixLabelstr);
    ui->statusBar->addWidget(aixLabel);

    PrepareSendDataInfohandle();
}

void MainWindow::on_PrintInfoButton_pressed()
{
    ui->PrintInfoButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void MainWindow::on_ClearButton_pressed()
{
     ui->ClearButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString m_jssstr;
    QString m_cxmstr;
    QString m_colorstr;
    QString m_zongzhistr;
    QString m_qianyinstr;
    QString m_hxgstr;

    QString m_printstrA = "总质量";
    QString m_printstrB = " 栏板高";
    QString m_printstrC = "Kg";
    QString m_printstrD = " ";
    QString m_printcombostr;

    QString m_LBstr;
    QString m_LWstr;
    QString m_RBstr;
    QString m_RWstr;



    unsigned int m_countnum = 0;
    checkcodestr = ui->lineEdit->text();
    m_countnum = checkcodestr.length();

    if ( m_countnum >= codebaselength)
    {
        QSqlQuery queryA = databaseoperation.GetBarCodeInfoByType("CheckCode", checkcodestr);
        while(queryA.next())
        {
            m_jssstr = queryA.value(1).toString();
            m_cxmstr = queryA.value(2).toString();
            m_colorstr = queryA.value(3).toString();
            m_zongzhistr = queryA.value(4).toString();
            m_qianyinstr = queryA.value(5).toString();
            m_hxgstr = queryA.value(6).toString();
        }

        if (!m_cxmstr.isEmpty())
        {
           m_cxmstr = "CC1021PA05";//测试用
           QSqlQuery queryB = databaseoperation.GetLRSpaceInfoByType("TypeInfo", m_cxmstr);
           while(queryB.next())
           {
               m_LBstr = queryB.value(1).toString();
               m_LWstr = queryB.value(2).toString();
               m_RBstr = queryB.value(3).toString();
               m_RWstr = queryB.value(4).toString();
           }
        }
        if (!m_colorstr.isEmpty())
        {
            QSqlQuery queryC = databaseoperation.GetPrintColorInfoByType("ColorIndex", m_colorstr);
            while(queryC.next())
            {
                select_color_num = queryC.value(2).toInt();
            }
        }

        ui->TypelineEdit->setText(m_cxmstr);

        m_printcombostr = m_printstrA + m_printstrD + m_zongzhistr + m_printstrD + m_printstrC;
        if (m_hxgstr.length() > 0)
        {
             m_printcombostr = m_printcombostr + m_printstrD + m_printstrB + m_printstrD + m_hxgstr;
        }
        ui->DatalineEdit->setText(m_printcombostr);

        ui->MarginLBlineEdit->setText(m_LBstr);
        ui->MarginLWlineEdit->setText(m_LWstr);
        ui->MarginRBlineEdit->setText(m_RBstr);
        ui->MarginRWlineEdit->setText(m_RWstr);
        ui->ColorSelect_comboBox->setCurrentIndex(select_color_num);

    }
}
