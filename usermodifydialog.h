#ifndef USERMODIFYDIALOG_H
#define USERMODIFYDIALOG_H

#include <QDialog>
#include "databaseoperation.h"

namespace Ui {
    class UserModifyDialog;
}

class UserModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserModifyDialog(QWidget *parent = 0);
    ~UserModifyDialog();

private:
    Ui::UserModifyDialog *ui;
    DataBaseOperation databaseoperation;

private slots:
    void on_OKpushButton_released();
    void on_OKpushButton_pressed();
};

#endif // USERMODIFYDIALOG_H
