/********************************************************************************
** Form generated from reading UI file 'userlogindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGINDIALOG_H
#define UI_USERLOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserLoginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *PasswordlineEdit;
    QPushButton *LoginpushButton;
    QComboBox *UserNamecomboBox;

    void setupUi(QDialog *UserLoginDialog)
    {
        if (UserLoginDialog->objectName().isEmpty())
            UserLoginDialog->setObjectName(QStringLiteral("UserLoginDialog"));
        UserLoginDialog->resize(400, 300);
        label = new QLabel(UserLoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 60, 80, 30));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(UserLoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 140, 80, 30));
        label_2->setFont(font);
        PasswordlineEdit = new QLineEdit(UserLoginDialog);
        PasswordlineEdit->setObjectName(QStringLiteral("PasswordlineEdit"));
        PasswordlineEdit->setGeometry(QRect(160, 140, 181, 30));
        PasswordlineEdit->setFont(font);
        PasswordlineEdit->setEchoMode(QLineEdit::Password);
        LoginpushButton = new QPushButton(UserLoginDialog);
        LoginpushButton->setObjectName(QStringLiteral("LoginpushButton"));
        LoginpushButton->setGeometry(QRect(140, 230, 121, 40));
        LoginpushButton->setFont(font);
        UserNamecomboBox = new QComboBox(UserLoginDialog);
        UserNamecomboBox->setObjectName(QStringLiteral("UserNamecomboBox"));
        UserNamecomboBox->setGeometry(QRect(160, 60, 181, 31));
        UserNamecomboBox->setFont(font);
        UserNamecomboBox->setEditable(true);

        retranslateUi(UserLoginDialog);

        QMetaObject::connectSlotsByName(UserLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *UserLoginDialog)
    {
        UserLoginDialog->setWindowTitle(QApplication::translate("UserLoginDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("UserLoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("UserLoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        LoginpushButton->setText(QApplication::translate("UserLoginDialog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserLoginDialog: public Ui_UserLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGINDIALOG_H
