#ifndef USERLOGINDIALOG_H
#define USERLOGINDIALOG_H

#include <QDialog>
#include "databaseoperation.h"

namespace Ui {
    class UserLoginDialog;
}

class UserLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserLoginDialog(QWidget *parent = 0);
    ~UserLoginDialog();

private:
    Ui::UserLoginDialog *ui;
    DataBaseOperation databaseoperation;

private slots:
    void on_LoginpushButton_released();
    void on_LoginpushButton_pressed();
};

#endif // USERLOGINDIALOG_H
