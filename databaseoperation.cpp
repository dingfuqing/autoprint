#include <QApplication>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlDriver>
#include "databaseoperation.h"

DataBaseOperation::DataBaseOperation()
{
    /*
    Qt通过ODBC连接Oracle数据库
    ①在合适的位置添加头文件#include<QtSql>，在工程文件.pro中添加QtSql模块支持QT += sql
    ②在windows控制面板-管理工具-数据源中添加Oracle数据源(这里MyOracleSrc)，并设置为指定数据库
    注意：数据源名与数据库名是不同的，使用ODBC时，在程序中连接数据库时需要指明的是数据源名。至于数据源中是哪个数据库，是在添加数据源时指定的。
    ③新建数据库连接：
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");//新建数据库连接db
    db.setDatabaseName("tsqianyin");//设置数据源名
    db.setUserName("wy");
    db.setPassword("wyl");
    db.open();
   */

}

QString DataBaseOperation::GetApplicationDirPathString( QString  filedir, QString  filename )
{
    QString strPath = QApplication::applicationDirPath();
    if (strPath[0] == '/')
    {
        strPath = strPath +  "/" + filedir +  "/" + filename;
    }
    else
    {
        strPath = strPath + "\\" +  filedir + "\\" + filename;
    }
    return strPath;
}

/*
* 函数介绍：数据库连接函数
* 输入参数：QString  filedir 为数据库的存储目录，为动态目录
*         QString  filename 为数据库名称
* 输出参数：
* 返回值 ：
*/

bool DataBaseOperation::CreateConnection( QString  filedir,  QString  filename )
{
    /*
    Qt通过ODBC连接Oracle数据库
    ①在合适的位置添加头文件#include<QtSql>，在工程文件.pro中添加QtSql模块支持QT += sql
    ②在windows控制面板-管理工具-数据源中添加Oracle数据源(这里MyOracleSrc)，并设置为指定数据库
    注意：数据源名与数据库名是不同的，使用ODBC时，在程序中连接数据库时需要指明的是数据源名。至于数据源中是哪个数据库，是在添加数据源时指定的。
    ③新建数据库连接：
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");//新建数据库连接db
    db.setDatabaseName("tsqianyin");//设置数据源名
    db.setUserName("wy");
    db.setPassword("wyl");
    db.open();
   */

    QString strPath = GetApplicationDirPathString( filedir, filename );
    User_DB = QSqlDatabase::addDatabase("QSQLITE");//声明使用sqlite数据库
    User_DB.setDatabaseName( strPath );

    if(!User_DB.open()) // 打开数据库,连接数据库, 然后就可以使用了
    {
       return false;
    }
    return true;
}

QSqlQuery DataBaseOperation::GetAllContentFromDataBase( QString TableName )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

bool DataBaseOperation::UpdateContentByName( QString TableName, QString barcode,
                                             QString content, QString frequency, QString type )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString updateCommand = "update ";
        updateCommand += TableName;
        updateCommand += " set Content = '";
        updateCommand += content;
        updateCommand += "', Frequency = ";
        updateCommand += frequency;
        updateCommand += ", Type = ";
        updateCommand += type;
        updateCommand += " where BarCode = '";
        updateCommand += barcode;
        updateCommand += "'";

        if(!query.exec(updateCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::InsertContent( QString TableName, QString barcode,
                                       QString content, QString frequency, QString type )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "insert into ";
        insertCommand += TableName;
        insertCommand += "(BarCode, Content, Frequency, Type) values('";
        insertCommand += barcode;
        insertCommand += "', '";
        insertCommand += content;
        insertCommand += "', ";
        insertCommand += frequency;
        insertCommand += "', ";
        insertCommand += type;
        insertCommand += ")";

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::DeleteContent( QString TableName, QString barcode )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "delete from ";
        insertCommand += TableName;
        insertCommand += " where BarCode='";
        insertCommand += barcode;
        insertCommand += "'";

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::DeleteColorContent( QString TableName, QString colorindex )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "delete from ";
        insertCommand += TableName;
        insertCommand += " where colorindex=";
        insertCommand += colorindex;

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

QSqlQuery DataBaseOperation::GetInfoByType( QString TableName, QString barcode )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where BarCode = '";
        selectcommand += barcode;
        selectcommand += "'";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

QSqlQuery DataBaseOperation::GetBarCodeInfoByType( QString TableName, QString barcode )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where JSS = '";
        selectcommand += barcode;
        selectcommand += "'";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

QSqlQuery DataBaseOperation::GetLRSpaceInfoByType( QString TableName, QString barcode )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where BarCode = '";
        selectcommand += barcode;
        selectcommand += "'";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

QSqlQuery DataBaseOperation::GetPrintColorInfoByType( QString TableName, QString colortype )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where colortype = '";
        selectcommand += colortype;
        selectcommand += "'";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}


QSqlQuery DataBaseOperation::GetColorInfoByType( QString TableName, QString colorindex )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where colorindex = ";
        selectcommand += colorindex;


        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

bool DataBaseOperation::UpdateInfoByBarCode( QString TableName, QString barcode,
                                             QString marginlb, QString marginlw, QString marginrb,QString marginrw)
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString updateCommand = "update ";
        updateCommand += TableName;
        updateCommand += " set MarginLB = ";
        updateCommand += marginlb;
        updateCommand += ", MarginLW = ";
        updateCommand += marginlw;
        updateCommand += ", MarginRB = ";
        updateCommand += marginrb;
        updateCommand += ", MarginRW = ";
        updateCommand += marginrw;

        updateCommand += " where BarCode = '";
        updateCommand += barcode;
        updateCommand += "'";

        if(!query.exec(updateCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::UpdateColorInfoByBarCode( QString TableName, QString index,
                                             QString colortype, QString printcolor)
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString updateCommand = "update ";
        updateCommand += TableName;
        updateCommand += " set colortype = '";
        updateCommand += colortype;
        updateCommand += "'";
        updateCommand += ", printcolor = ";
        updateCommand += printcolor;

        updateCommand += " where colorindex = ";
        updateCommand += index;

        if(!query.exec(updateCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::InsertTypeInfo( QString TableName, QString barcode,
                                        QString marginlb, QString marginlw, QString marginrb,QString marginrw)
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "insert into ";
        insertCommand += TableName;
        insertCommand += "(BarCode, MarginLB, MarginLW, MarginRB, MarginRW, PosLZ, PosRZ) values('";
        insertCommand += barcode;
        insertCommand += "', ";
        insertCommand += marginlb;
        insertCommand += ", ";
        insertCommand += marginlw;
        insertCommand += ", ";
        insertCommand += marginrb;
        insertCommand += ", ";
        insertCommand += marginrw;
        insertCommand += ")";

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::InsertColorTypeInfo( QString TableName, QString colorindex,
                                        QString colortype, QString printcolor)
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "insert into ";
        insertCommand += TableName;
        insertCommand += "(colorindex, colortype, printcolor) values(";
        insertCommand += colorindex;
        insertCommand += ", '";
        insertCommand += colortype;
        insertCommand += "', ";
        insertCommand += printcolor;
        insertCommand += ")";

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

QSqlQuery DataBaseOperation::GetUserInfoByName( QString TableName, QString username )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where UserName = '";
        selectcommand += username;
        selectcommand += "'";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

QSqlQuery DataBaseOperation::GetUserInfoByName( QString TableName, QString username, QString password )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where UserName = '";
        selectcommand += username;
        selectcommand += "'";
        selectcommand += " and Password = '";
        selectcommand += password;
        selectcommand += "'";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

QSqlQuery DataBaseOperation::GetUserInfoByName( QString TableName, int levelmax )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " where Level < ";
        QString tempstr = "";
        tempstr.setNum(levelmax);
        selectcommand += tempstr;

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

bool DataBaseOperation::UpdateUserInfoByName( QString TableName, QString username,
                                             QString password, QString level )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString updateCommand = "update ";
        updateCommand += TableName;
        updateCommand += " set Password = '";
        updateCommand += password;
        updateCommand += "', Level = ";
        updateCommand += level;
        updateCommand += " where UserName = '";
        updateCommand += username;
        updateCommand += "'";

        if(!query.exec(updateCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::AddUserInfo( QString TableName, QString username,
                                       QString password, QString level )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "insert into ";
        insertCommand += TableName;
        insertCommand += "(UserName, Password, Level) values('";
        insertCommand += username;
        insertCommand += "', '";
        insertCommand += password;
        insertCommand += "', ";
        insertCommand += level;
        insertCommand += ")";

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

bool DataBaseOperation::DeleteUser( QString TableName, QString username )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString insertCommand = "delete from ";
        insertCommand += TableName;
        insertCommand += " where UserName='";
        insertCommand += username;
        insertCommand += "'";

        if(!query.exec(insertCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}

QSqlQuery DataBaseOperation::GetSysPara( QString TableName )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString selectcommand = "select * from ";
        selectcommand += TableName;
        selectcommand += " order by ID asc";

        if(!query.exec(selectcommand))
        {
        }
        User_DB.commit();
    }
    return query;
}

bool DataBaseOperation::UpdateSysParaByID( QString TableName, QString ID, QString value )
{
    QSqlQuery query(User_DB);

    if(User_DB.driver()->hasFeature(QSqlDriver::Transactions))
    {
        User_DB.transaction();

        QString updateCommand = "update ";
        updateCommand += TableName;
        updateCommand += " set ParaValue = ";
        updateCommand += "'";
        updateCommand += value;
        updateCommand += "'";
        updateCommand += " where ID = ";
        updateCommand += ID;

        if(!query.exec(updateCommand))
        {
            return false;
        }
        User_DB.commit();
    }
    return true;
}
