/********************************************************************************
** Form generated from reading UI file 'useradddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERADDDIALOG_H
#define UI_USERADDDIALOG_H

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

class Ui_UserAddDialog
{
public:
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *ConfirmPasswdlineEdit;
    QLineEdit *PasswdlineEdit;
    QLabel *label_3;
    QLineEdit *UserNamelineEdit;
    QLabel *label_5;
    QPushButton *OKpushButton;
    QComboBox *levelcomboBox;

    void setupUi(QDialog *UserAddDialog)
    {
        if (UserAddDialog->objectName().isEmpty())
            UserAddDialog->setObjectName(QStringLiteral("UserAddDialog"));
        UserAddDialog->resize(800, 600);
        QFont font;
        font.setPointSize(9);
        UserAddDialog->setFont(font);
        label_2 = new QLabel(UserAddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 180, 171, 30));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_4 = new QLabel(UserAddDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 100, 171, 30));
        label_4->setFont(font1);
        ConfirmPasswdlineEdit = new QLineEdit(UserAddDialog);
        ConfirmPasswdlineEdit->setObjectName(QStringLiteral("ConfirmPasswdlineEdit"));
        ConfirmPasswdlineEdit->setGeometry(QRect(400, 260, 190, 30));
        ConfirmPasswdlineEdit->setFont(font1);
        ConfirmPasswdlineEdit->setEchoMode(QLineEdit::Password);
        PasswdlineEdit = new QLineEdit(UserAddDialog);
        PasswdlineEdit->setObjectName(QStringLiteral("PasswdlineEdit"));
        PasswdlineEdit->setGeometry(QRect(400, 180, 190, 30));
        PasswdlineEdit->setFont(font1);
        PasswdlineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(UserAddDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 260, 171, 30));
        label_3->setFont(font1);
        UserNamelineEdit = new QLineEdit(UserAddDialog);
        UserNamelineEdit->setObjectName(QStringLiteral("UserNamelineEdit"));
        UserNamelineEdit->setGeometry(QRect(400, 100, 190, 30));
        UserNamelineEdit->setFont(font1);
        label_5 = new QLabel(UserAddDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 340, 171, 30));
        label_5->setFont(font1);
        OKpushButton = new QPushButton(UserAddDialog);
        OKpushButton->setObjectName(QStringLiteral("OKpushButton"));
        OKpushButton->setGeometry(QRect(340, 470, 121, 41));
        OKpushButton->setFont(font1);
        levelcomboBox = new QComboBox(UserAddDialog);
        levelcomboBox->setObjectName(QStringLiteral("levelcomboBox"));
        levelcomboBox->setGeometry(QRect(400, 340, 190, 30));
        levelcomboBox->setFont(font1);
        QWidget::setTabOrder(UserNamelineEdit, PasswdlineEdit);
        QWidget::setTabOrder(PasswdlineEdit, ConfirmPasswdlineEdit);
        QWidget::setTabOrder(ConfirmPasswdlineEdit, levelcomboBox);
        QWidget::setTabOrder(levelcomboBox, OKpushButton);

        retranslateUi(UserAddDialog);

        QMetaObject::connectSlotsByName(UserAddDialog);
    } // setupUi

    void retranslateUi(QDialog *UserAddDialog)
    {
        UserAddDialog->setWindowTitle(QApplication::translate("UserAddDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("UserAddDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("UserAddDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("UserAddDialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QApplication::translate("UserAddDialog", "\347\224\250\346\210\267\347\255\211\347\272\247\357\274\232", nullptr));
        OKpushButton->setText(QApplication::translate("UserAddDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserAddDialog: public Ui_UserAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERADDDIALOG_H
