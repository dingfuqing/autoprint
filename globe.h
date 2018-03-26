#ifndef GLOBE_H
#define GLOBE_H

#include <QString>
#include <QMetaType>


struct GlobalMember
{
    int UserLevel;
    QStringList SendAllContentList;
    QStringList sgstrlist;
    QList<int> sgwidthlist;
    QStringList sendsgstrlist;
    int sgcount;
    int smcount;
    QStringList BarCodeList;
    QStringList ColorCodeList;
    QStringList ColorIndexList;
    QStringList ContentList;
    QList<int> FrequencyList;
    QList<int> TypeList;
    QList<int> MarginList;
    int ReceivePrint;
    bool IsConfirmed;
    bool IsPrint;
    bool IsSended;
    bool IsUpdate;

    QStringList sendstrlist;
    QList<int> sendstrlen;

    QStringList plantypelist;
    QStringList plancontentlist;
};

struct SysPara
{
    int FlushTimer;
    int PrintMode;

    QString Ip_A;
    QString Ip_B;
    QString Ip_C;
    QString Ip_D;

    int changeflag;

    int ipAfirstconectFlag;
    int ipBfirstconectFlag;
    int ipCfirstconectFlag;
    int ipDfirstconectFlag;
};

struct com_para_seting
{
    unsigned int com_id;
    unsigned int com_index;
    unsigned int com_in_curvalue;
    unsigned int com_in_initvalue;
    unsigned int com_in_max;
    unsigned int com_in_min;
    char com_itemname[16];

};

struct com_para_seting_all
{
    struct com_para_seting com_port[7];
    struct com_para_seting com_rate[7];
    struct com_para_seting com_check[7];
    struct com_para_seting Flow_Ctrl[7];

};

struct log_authcard
{
    unsigned int log_id[1000];
    QString log_office[1000];
    unsigned int log_number;
};

struct ComNetWork_LocalVar
{
    unsigned int comport;
    unsigned int comrate;
    unsigned int comcheck;
    unsigned int FlowCtrl;
};

struct DataBaseConnPara
{
    QString IPAddrStr;
    QString DataBaseNameStr;
    QString ConnPortStr;
    QString UserNameStr;
    QString PasswordStr;
    QString SqlStr;
    bool IsChanged;
};

#endif // GLOBE_H
