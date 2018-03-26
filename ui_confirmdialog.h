/********************************************************************************
** Form generated from reading UI file 'confirmdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDIALOG_H
#define UI_CONFIRMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDialog
{
public:
    QLabel *label;
    QPushButton *OKpushButton;
    QPushButton *CancelpushButton;

    void setupUi(QDialog *ConfirmDialog)
    {
        if (ConfirmDialog->objectName().isEmpty())
            ConfirmDialog->setObjectName(QStringLiteral("ConfirmDialog"));
        ConfirmDialog->resize(400, 300);
        label = new QLabel(ConfirmDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 321, 161));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        OKpushButton = new QPushButton(ConfirmDialog);
        OKpushButton->setObjectName(QStringLiteral("OKpushButton"));
        OKpushButton->setGeometry(QRect(80, 230, 100, 40));
        OKpushButton->setFont(font);
        CancelpushButton = new QPushButton(ConfirmDialog);
        CancelpushButton->setObjectName(QStringLiteral("CancelpushButton"));
        CancelpushButton->setGeometry(QRect(220, 230, 100, 40));
        CancelpushButton->setFont(font);

        retranslateUi(ConfirmDialog);
        QObject::connect(OKpushButton, SIGNAL(clicked()), ConfirmDialog, SLOT(close()));
        QObject::connect(CancelpushButton, SIGNAL(clicked()), ConfirmDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ConfirmDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDialog)
    {
        ConfirmDialog->setWindowTitle(QApplication::translate("ConfirmDialog", "Dialog", nullptr));
        label->setText(QString());
        OKpushButton->setText(QApplication::translate("ConfirmDialog", "\347\241\256\345\256\232", nullptr));
        CancelpushButton->setText(QApplication::translate("ConfirmDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDialog: public Ui_ConfirmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDIALOG_H
