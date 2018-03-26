#ifndef USERADDDIALOG_H
#define USERADDDIALOG_H

#include <QDialog>
#include "databaseoperation.h"

namespace Ui {
    class UserAddDialog;
}

class UserAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserAddDialog(QWidget *parent = 0);
    ~UserAddDialog();

private:
    Ui::UserAddDialog *ui;
    DataBaseOperation databaseoperation;

private slots:
    void on_OKpushButton_released();
    void on_OKpushButton_pressed();
};

#endif // USERADDDIALOG_H
