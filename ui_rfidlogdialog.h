/********************************************************************************
** Form generated from reading UI file 'rfidlogdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RFIDLOGDIALOG_H
#define UI_RFIDLOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RfidlogDialog
{
public:
    QGroupBox *tablegroupBox;
    QTableView *AuthRecordtableView;
    QPushButton *AuthRightendButton;
    QPushButton *AuthLeftendButton;
    QPushButton *AuthLeftButton;
    QPushButton *AuthRightButton;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *AuthSaveButton;
    QPushButton *AuthBackButton;

    void setupUi(QDialog *RfidlogDialog)
    {
        if (RfidlogDialog->objectName().isEmpty())
            RfidlogDialog->setObjectName(QStringLiteral("RfidlogDialog"));
        RfidlogDialog->resize(800, 600);
        RfidlogDialog->setMinimumSize(QSize(800, 600));
        tablegroupBox = new QGroupBox(RfidlogDialog);
        tablegroupBox->setObjectName(QStringLiteral("tablegroupBox"));
        tablegroupBox->setGeometry(QRect(20, 10, 761, 511));
        AuthRecordtableView = new QTableView(tablegroupBox);
        AuthRecordtableView->setObjectName(QStringLiteral("AuthRecordtableView"));
        AuthRecordtableView->setGeometry(QRect(10, 10, 741, 441));
        AuthRecordtableView->setMaximumSize(QSize(16777215, 16777215));
        AuthRightendButton = new QPushButton(tablegroupBox);
        AuthRightendButton->setObjectName(QStringLiteral("AuthRightendButton"));
        AuthRightendButton->setGeometry(QRect(610, 460, 123, 45));
        AuthLeftendButton = new QPushButton(tablegroupBox);
        AuthLeftendButton->setObjectName(QStringLiteral("AuthLeftendButton"));
        AuthLeftendButton->setGeometry(QRect(20, 460, 123, 45));
        AuthLeftButton = new QPushButton(tablegroupBox);
        AuthLeftButton->setObjectName(QStringLiteral("AuthLeftButton"));
        AuthLeftButton->setGeometry(QRect(160, 460, 120, 45));
        AuthRightButton = new QPushButton(tablegroupBox);
        AuthRightButton->setObjectName(QStringLiteral("AuthRightButton"));
        AuthRightButton->setGeometry(QRect(480, 460, 120, 45));
        frame = new QFrame(RfidlogDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(260, 530, 291, 61));
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 271, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        AuthSaveButton = new QPushButton(horizontalLayoutWidget);
        AuthSaveButton->setObjectName(QStringLiteral("AuthSaveButton"));
        AuthSaveButton->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(14);
        AuthSaveButton->setFont(font);

        horizontalLayout->addWidget(AuthSaveButton);

        AuthBackButton = new QPushButton(horizontalLayoutWidget);
        AuthBackButton->setObjectName(QStringLiteral("AuthBackButton"));
        AuthBackButton->setMinimumSize(QSize(0, 40));
        AuthBackButton->setFont(font);

        horizontalLayout->addWidget(AuthBackButton);


        retranslateUi(RfidlogDialog);

        QMetaObject::connectSlotsByName(RfidlogDialog);
    } // setupUi

    void retranslateUi(QDialog *RfidlogDialog)
    {
        RfidlogDialog->setWindowTitle(QApplication::translate("RfidlogDialog", "\346\227\245\345\277\227\346\226\207\344\273\266", nullptr));
        tablegroupBox->setTitle(QString());
        AuthRightendButton->setText(QApplication::translate("RfidlogDialog", ">>", nullptr));
        AuthLeftendButton->setText(QApplication::translate("RfidlogDialog", "<<", nullptr));
        AuthLeftButton->setText(QApplication::translate("RfidlogDialog", "<", nullptr));
        AuthRightButton->setText(QApplication::translate("RfidlogDialog", ">", nullptr));
        AuthSaveButton->setText(QApplication::translate("RfidlogDialog", "\344\277\235\345\255\230", nullptr));
        AuthBackButton->setText(QApplication::translate("RfidlogDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RfidlogDialog: public Ui_RfidlogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RFIDLOGDIALOG_H
