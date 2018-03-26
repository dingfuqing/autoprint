/********************************************************************************
** Form generated from reading UI file 'userdeletedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDELETEDIALOG_H
#define UI_USERDELETEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_UserDeleteDialog
{
public:
    QTableView *UsertableView;
    QPushButton *pushButton;

    void setupUi(QDialog *UserDeleteDialog)
    {
        if (UserDeleteDialog->objectName().isEmpty())
            UserDeleteDialog->setObjectName(QStringLiteral("UserDeleteDialog"));
        UserDeleteDialog->resize(800, 600);
        UsertableView = new QTableView(UserDeleteDialog);
        UsertableView->setObjectName(QStringLiteral("UsertableView"));
        UsertableView->setGeometry(QRect(59, 50, 683, 390));
        QFont font;
        font.setPointSize(14);
        UsertableView->setFont(font);
        pushButton = new QPushButton(UserDeleteDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 490, 121, 41));
        pushButton->setFont(font);

        retranslateUi(UserDeleteDialog);

        QMetaObject::connectSlotsByName(UserDeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDeleteDialog)
    {
        UserDeleteDialog->setWindowTitle(QApplication::translate("UserDeleteDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("UserDeleteDialog", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDeleteDialog: public Ui_UserDeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDELETEDIALOG_H
