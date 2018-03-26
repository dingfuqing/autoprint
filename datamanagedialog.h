#ifndef DATAMANAGEDIALOG_H
#define DATAMANAGEDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "databaseoperation.h"

namespace Ui {
    class DataManageDialog;
}

class DataManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataManageDialog(QWidget *parent = 0);
    ~DataManageDialog();


    void FillTypetableView();
    void QuerypushDataInfoHnadle();

    bool eventFilter(QObject *target, QEvent *event);
    void SetOperationOfLevel();
    QString GetSGSendData(QString str, QString index);

private:
    Ui::DataManageDialog *ui;

    DataBaseOperation databaseoperation;
    QStandardItemModel * model;
    bool showview;
    int typeindex;

private slots:

    void on_DeletepushButton_released();
    void on_DeletepushButton_pressed();
    void on_UpdatepushButton_released();
    void on_UpdatepushButton_pressed();
    void on_InsertpushButton_released();
    void on_InsertpushButton_pressed();
    void on_QuerypushButton_released();
    void on_QuerypushButton_pressed();
    void ShowTypetableView();

    void on_TypetableView_clicked(QModelIndex index);
    void on_TypetableView_pressed(const QModelIndex &index);
};

#endif // DATAMANAGEDIALOG_H
