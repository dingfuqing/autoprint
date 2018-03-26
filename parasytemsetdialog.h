#ifndef PARASYTEMSETDIALOG_H
#define PARASYTEMSETDIALOG_H

#include <QDialog>

namespace Ui {
class ParaSytemSetDialog;
}

class ParaSytemSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParaSytemSetDialog(QWidget *parent = 0);
    ~ParaSytemSetDialog();

private slots:
    void on_UpdatepushButton_released();

    void on_CancelpushButton_released();

    void on_UpdatepushButton_pressed();

    void on_CancelpushButton_pressed();

private:
    Ui::ParaSytemSetDialog *ui;
};

#endif // PARASYTEMSETDIALOG_H
