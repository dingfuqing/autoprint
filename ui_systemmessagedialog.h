/********************************************************************************
** Form generated from reading UI file 'systemmessagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMESSAGEDIALOG_H
#define UI_SYSTEMMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SystemMessageDialog
{
public:
    QPushButton *OKpushButton;
    QLabel *label;

    void setupUi(QDialog *SystemMessageDialog)
    {
        if (SystemMessageDialog->objectName().isEmpty())
            SystemMessageDialog->setObjectName(QStringLiteral("SystemMessageDialog"));
        SystemMessageDialog->resize(400, 300);
        OKpushButton = new QPushButton(SystemMessageDialog);
        OKpushButton->setObjectName(QStringLiteral("OKpushButton"));
        OKpushButton->setGeometry(QRect(150, 230, 100, 40));
        QFont font;
        font.setPointSize(14);
        OKpushButton->setFont(font);
        label = new QLabel(SystemMessageDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 321, 161));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(SystemMessageDialog);
        QObject::connect(OKpushButton, SIGNAL(clicked()), SystemMessageDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(SystemMessageDialog);
    } // setupUi

    void retranslateUi(QDialog *SystemMessageDialog)
    {
        SystemMessageDialog->setWindowTitle(QApplication::translate("SystemMessageDialog", "Dialog", nullptr));
        OKpushButton->setText(QApplication::translate("SystemMessageDialog", "\347\241\256\345\256\232", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SystemMessageDialog: public Ui_SystemMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMESSAGEDIALOG_H
