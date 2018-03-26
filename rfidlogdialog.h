#ifndef RFIDLOGDIALOG_H
#define RFIDLOGDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

#include "globe.h"
//#include "userglobe.h"

namespace Ui {
    class RfidlogDialog;
}

class RfidlogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RfidlogDialog(QWidget *parent = 0);
    ~RfidlogDialog();

    void InitLogAuthcardSetingData();
    void InitAuthCardlogDialog();
    void ChangeAuthCardLogDataTolist();

    int memlogmax;
    int m_rowcount;

private slots:
    void on_AuthBackButton_released();

    void on_AuthLeftendButton_released();

    void on_AuthLeftButton_released();

    void on_AuthRightButton_released();

    void on_AuthRightendButton_released();

    void on_AuthSaveButton_released();

    void on_AuthBackButton_pressed();

    void on_AuthSaveButton_pressed();

private:
    Ui::RfidlogDialog *ui;

    QStringList MessageList;
    QStandardItemModel * logmodel;
    QStandardItem * m_logitem;

    int LogTotalTablePages;
    int LogCurTablePages;

    int FirstCardTablePages;

    bool ShowInkLogData;
};

#endif // RFIDLOGDIALOG_H
