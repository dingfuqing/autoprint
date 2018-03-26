#ifndef USERDELETEDIALOG_H
#define USERDELETEDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

#include "databaseoperation.h"

namespace Ui {
    class UserDeleteDialog;
}

class UserDeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDeleteDialog(QWidget *parent = 0);
    ~UserDeleteDialog();
    void FillTypetableView();

private:
    Ui::UserDeleteDialog *ui;
    DataBaseOperation databaseoperation;
    QStandardItemModel * model;
    QStringList userlist;
    QStringList seluserlist;

private slots:
    void on_UsertableView_clicked(QModelIndex index);
    void on_pushButton_released();
    void on_pushButton_pressed();
};

#endif // USERDELETEDIALOG_H
