#ifndef DATABASEOPERATION_H
#define DATABASEOPERATION_H

#include <QString>
#include <QSqlDatabase>

class DataBaseOperation
{
public:
    QSqlDatabase User_DB;

    DataBaseOperation();
    QString GetApplicationDirPathString( QString  filedir, QString  filename );
    bool CreateConnection( QString  filedir,  QString  filename );
    QSqlQuery GetAllContentFromDataBase( QString TableName );
    bool UpdateContentByName( QString TableName, QString barcode,
                              QString content, QString frequency, QString type );
    bool InsertContent( QString TableName, QString barcode,
                        QString content, QString frequency, QString type );
    bool DeleteContent( QString TableName, QString barcode );
    bool DeleteColorContent( QString TableName, QString colorindex );

    QSqlQuery GetInfoByType( QString TableName, QString barcode );    
    QSqlQuery GetColorInfoByType( QString TableName, QString colorindex );

    QSqlQuery GetBarCodeInfoByType( QString TableName, QString barcode );
    QSqlQuery GetLRSpaceInfoByType( QString TableName, QString barcode );
    QSqlQuery GetPrintColorInfoByType( QString TableName, QString colortype );

    bool UpdateInfoByBarCode( QString TableName, QString barcode,
                              QString marginlb, QString marginlw, QString marginrb,
                              QString marginrw);
    bool UpdateColorInfoByBarCode( QString TableName, QString index,
                                                 QString colortype, QString printcolor);

    bool InsertTypeInfo( QString TableName, QString barcode,
                         QString marginlb, QString marginlw, QString marginrb,
                         QString marginrw);
    bool InsertColorTypeInfo( QString TableName, QString colorindex,
                                            QString colortype, QString printcolor);

    QSqlQuery GetUserInfoByName( QString TableName, QString username );
    QSqlQuery GetUserInfoByName( QString TableName, QString username, QString password );
    QSqlQuery GetUserInfoByName( QString TableName, int levelmax );
    bool UpdateUserInfoByName( QString TableName, QString username,
                               QString password, QString level );
    bool AddUserInfo( QString TableName, QString username,
                      QString password, QString level );

    bool DeleteUser( QString TableName, QString username );
    QSqlQuery GetSysPara( QString TableName );
    bool UpdateSysParaByID( QString TableName, QString ID, QString value );
};

#endif // DATABASEOPERATION_H
