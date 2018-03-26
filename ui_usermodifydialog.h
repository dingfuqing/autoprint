/********************************************************************************
** Form generated from reading UI file 'usermodifydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMODIFYDIALOG_H
#define UI_USERMODIFYDIALOG_H

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

class Ui_UserModifyDialog
{
public:
    QLabel *label;
    QLineEdit *OldPasswdlineEdit;
    QLineEdit *NewPasswdlineEdit;
    QLabel *label_2;
    QLineEdit *ConfirmPasswdlineEdit;
    QLabel *label_3;
    QPushButton *OKpushButton;
    QLineEdit *UserNamelineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *levelcomboBox;

    void setupUi(QDialog *UserModifyDialog)
    {
        if (UserModifyDialog->objectName().isEmpty())
            UserModifyDialog->setObjectName(QStringLiteral("UserModifyDialog"));
        UserModifyDialog->resize(800, 600);
        label = new QLabel(UserModifyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 170, 171, 30));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        OldPasswdlineEdit = new QLineEdit(UserModifyDialog);
        OldPasswdlineEdit->setObjectName(QStringLiteral("OldPasswdlineEdit"));
        OldPasswdlineEdit->setGeometry(QRect(400, 170, 190, 30));
        OldPasswdlineEdit->setFont(font);
        OldPasswdlineEdit->setEchoMode(QLineEdit::Password);
        NewPasswdlineEdit = new QLineEdit(UserModifyDialog);
        NewPasswdlineEdit->setObjectName(QStringLiteral("NewPasswdlineEdit"));
        NewPasswdlineEdit->setGeometry(QRect(400, 230, 190, 30));
        NewPasswdlineEdit->setFont(font);
        NewPasswdlineEdit->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(UserModifyDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 230, 171, 30));
        label_2->setFont(font);
        ConfirmPasswdlineEdit = new QLineEdit(UserModifyDialog);
        ConfirmPasswdlineEdit->setObjectName(QStringLiteral("ConfirmPasswdlineEdit"));
        ConfirmPasswdlineEdit->setGeometry(QRect(400, 290, 190, 30));
        ConfirmPasswdlineEdit->setFont(font);
        ConfirmPasswdlineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(UserModifyDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 290, 171, 30));
        label_3->setFont(font);
        OKpushButton = new QPushButton(UserModifyDialog);
        OKpushButton->setObjectName(QStringLiteral("OKpushButton"));
        OKpushButton->setGeometry(QRect(340, 480, 121, 41));
        OKpushButton->setFont(font);
        UserNamelineEdit = new QLineEdit(UserModifyDialog);
        UserNamelineEdit->setObjectName(QStringLiteral("UserNamelineEdit"));
        UserNamelineEdit->setGeometry(QRect(400, 110, 190, 30));
        UserNamelineEdit->setFont(font);
        label_4 = new QLabel(UserModifyDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 110, 171, 30));
        label_4->setFont(font);
        label_5 = new QLabel(UserModifyDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 350, 171, 30));
        label_5->setFont(font);
        levelcomboBox = new QComboBox(UserModifyDialog);
        levelcomboBox->setObjectName(QStringLiteral("levelcomboBox"));
        levelcomboBox->setGeometry(QRect(400, 350, 190, 30));
        levelcomboBox->setFont(font);
        QWidget::setTabOrder(UserNamelineEdit, OldPasswdlineEdit);
        QWidget::setTabOrder(OldPasswdlineEdit, NewPasswdlineEdit);
        QWidget::setTabOrder(NewPasswdlineEdit, ConfirmPasswdlineEdit);
        QWidget::setTabOrder(ConfirmPasswdlineEdit, levelcomboBox);
        QWidget::setTabOrder(levelcomboBox, OKpushButton);

        retranslateUi(UserModifyDialog);

        QMetaObject::connectSlotsByName(UserModifyDialog);
    } // setupUi

    void retranslateUi(QDialog *UserModifyDialog)
    {
        UserModifyDialog->setWindowTitle(QApplication::translate("UserModifyDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("UserModifyDialog", "\350\257\267\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QApplication::translate("UserModifyDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("UserModifyDialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        OKpushButton->setText(QApplication::translate("UserModifyDialog", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QApplication::translate("UserModifyDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("UserModifyDialog", "\347\224\250\346\210\267\347\255\211\347\272\247\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserModifyDialog: public Ui_UserModifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMODIFYDIALOG_H
