#include "systemmessagedialog.h"
#include "ui_systemmessagedialog.h"

SystemMessageDialog::SystemMessageDialog(QString MessageStr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemMessageDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("系统消息");
    this->setStyleSheet("#SystemMessageDialog{background-color: rgb(255, 255, 255)} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    ui->label->setText(MessageStr);
}

SystemMessageDialog::~SystemMessageDialog()
{
    delete ui;
}

void SystemMessageDialog::on_OKpushButton_pressed()
{
    ui->OKpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void SystemMessageDialog::on_OKpushButton_released()
{
    ui->OKpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}
