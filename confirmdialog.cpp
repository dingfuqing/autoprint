#include "confirmdialog.h"
#include "ui_confirmdialog.h"
#include "globe.h"

extern GlobalMember m_GlobalMember;
ConfirmDialog::ConfirmDialog(QString MessageStr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("系统消息");
    this->setStyleSheet("#ConfirmDialog{background-color: rgb(255, 255, 255)} QPushButton{background-color: rgb(120, 116, 213);border-radius: 5px} ");

    ui->label->setText(MessageStr);
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}

void ConfirmDialog::on_OKpushButton_pressed()
{
    ui->OKpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ConfirmDialog::on_OKpushButton_released()
{
    m_GlobalMember.IsConfirmed = true;
    ui->OKpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}

void ConfirmDialog::on_CancelpushButton_pressed()
{
    ui->CancelpushButton->setStyleSheet("background-color: rgb(110, 96, 113);");
}

void ConfirmDialog::on_CancelpushButton_released()
{
    ui->CancelpushButton->setStyleSheet("background-color: rgb(120, 116, 213);");
}
