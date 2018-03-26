#ifndef SYSTEMMESSAGEDIALOG_H
#define SYSTEMMESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
    class SystemMessageDialog;
}

class SystemMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SystemMessageDialog(QString messageStr, QWidget *parent = 0);
    ~SystemMessageDialog();

private:
    Ui::SystemMessageDialog *ui;

private slots:
    void on_OKpushButton_released();
    void on_OKpushButton_pressed();
};

#endif // SYSTEMMESSAGEDIALOG_H
