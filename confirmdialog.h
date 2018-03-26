#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
    class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QString MessageStr, QWidget *parent = 0);
    ~ConfirmDialog();

private:
    Ui::ConfirmDialog *ui;

private slots:
    void on_CancelpushButton_released();
    void on_CancelpushButton_pressed();
    void on_OKpushButton_released();
    void on_OKpushButton_pressed();
};

#endif // CONFIRMDIALOG_H
