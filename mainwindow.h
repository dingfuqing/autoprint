#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtNetwork/QTcpSocket"
#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QTimer>
#include "databaseoperation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    DataBaseOperation databaseoperation;
    void HandleTimer();

    void UserLevelControlHandle();
    void UpdateDataofIndex(unsigned int typeindex);
    void FillTypetableView();
    void SelectFilecomboBoxCurrent();
    void Delay_MSec_Suspend(unsigned int msec);

    void SendAutoReadMessages(unsigned int type, QByteArray msg);
    void InitLogAuthSetingData();

    void ComboSendMessagesetVariable();
    void SendMessageToMachine(QString SendMessage);
    void SendMessageToMachineSign(unsigned int type, QString SendMessage);

    bool eventFilter(QObject *target, QEvent *event);

    void DatafromcsvTotablePrint();
    void DatafromcsvTotableType();
    void DatafromcsvTotable();

    void PrepareSendDataInfohandle();

    QTcpSocket  *auto_socket_a;
    QTcpSocket  *auto_socket_b;
    QTcpSocket  *auto_socket_c;
    QTcpSocket  *auto_socket_d;

    QString server_ip_a;
    QString server_ip_b;
    QString server_ip_c;
    QString server_ip_d;

    QString checkcodestr;
    unsigned int codebaselength;

    QString currtimestr;
    QString socket_sendstartdata;
    QString socket_senddata;
    QString socket_sendenddata;

    QString VaiableName_a;
    QString VaiableName_b;
    QString VaiableName_c;
    QString VaiableName_d;
    QString InstAllName;
    QString SelectPath;

    QStringList combomessage;
    unsigned int start_printflag;

    unsigned int server_port_a;
    unsigned int server_port_b;
    unsigned int server_port_c;
    unsigned int server_port_d;
    unsigned int select_color_num;

    QLabel *timeLabel;
    QLabel *aixLabel;

    bool showview;
    unsigned int typeindex;

    QStandardItemModel *model;
    QTimer *m_Timer;

private:
    Ui::MainWindow *ui;
private slots:

    virtual void autoAconnected();
    virtual void autoBconnected();
    virtual void autoCconnected();
    virtual void autoDconnected();

    virtual void HandleAutoReadAMessages();
    virtual void HandleAutoReadBMessages();
    virtual void HandleAutoReadCMessages();
    virtual void HandleAutoReadDMessages();

    virtual void hasnotconnectedA();
    virtual void erroA();
    virtual void hasnotconnectedB();
    virtual void erroB();
    virtual void hasnotconnectedC();
    virtual void erroC();
    virtual void hasnotconnectedD();
    virtual void erroD();

    virtual void userlog();
    virtual void usermodify();
    virtual void useradd();
    virtual void userdelete();
    virtual void userexit();
    virtual void datamanage();
    virtual void colordatamanage();
    virtual void showlogfile();

    virtual void sysparaset();
    virtual void ProcessTimeThing();

    void on_SendDataButton_pressed();
    void on_PrintInfoButton_released();
    void on_ClearButton_released();
    void on_TypetableView_clicked(const QModelIndex &index);

    void on_ColorSelect_comboBox_currentIndexChanged(int index);
    void on_ClearNoz_comboBox_currentIndexChanged(int index);
    void on_SelectFile_comboBox_currentIndexChanged(int index);
    void on_MarginLBlineEdit_textChanged(const QString &arg1);
    void on_MarginLWlineEdit_textChanged(const QString &arg1);
    void on_MarginRBlineEdit_textChanged(const QString &arg1);
    void on_MarginRWlineEdit_textChanged(const QString &arg1);
    void on_SendDataButton_released();
    void on_PrintInfoButton_pressed();
    void on_ClearButton_pressed();
    void on_lineEdit_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
