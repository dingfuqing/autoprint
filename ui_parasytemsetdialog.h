/********************************************************************************
** Form generated from reading UI file 'parasytemsetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARASYTEMSETDIALOG_H
#define UI_PARASYTEMSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParaSytemSetDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *MarginRBlineEdit;
    QLabel *label_8;
    QLineEdit *MarginLWlineEdit;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *MarginRWlineEdit;
    QLineEdit *MarginLBlineEdit;
    QWidget *widget;
    QFrame *frame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *UpdatepushButton;
    QPushButton *CancelpushButton;

    void setupUi(QDialog *ParaSytemSetDialog)
    {
        if (ParaSytemSetDialog->objectName().isEmpty())
            ParaSytemSetDialog->setObjectName(QStringLiteral("ParaSytemSetDialog"));
        ParaSytemSetDialog->resize(800, 600);
        ParaSytemSetDialog->setMinimumSize(QSize(800, 600));
        gridLayoutWidget = new QWidget(ParaSytemSetDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 180, 681, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(9);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        MarginRBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginRBlineEdit->setObjectName(QStringLiteral("MarginRBlineEdit"));
        MarginRBlineEdit->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(14);
        MarginRBlineEdit->setFont(font1);

        gridLayout->addWidget(MarginRBlineEdit, 0, 4, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        MarginLWlineEdit = new QLineEdit(gridLayoutWidget);
        MarginLWlineEdit->setObjectName(QStringLiteral("MarginLWlineEdit"));
        MarginLWlineEdit->setMinimumSize(QSize(0, 40));
        MarginLWlineEdit->setFont(font1);

        gridLayout->addWidget(MarginLWlineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        MarginRWlineEdit = new QLineEdit(gridLayoutWidget);
        MarginRWlineEdit->setObjectName(QStringLiteral("MarginRWlineEdit"));
        MarginRWlineEdit->setMinimumSize(QSize(0, 40));
        MarginRWlineEdit->setFont(font1);

        gridLayout->addWidget(MarginRWlineEdit, 1, 4, 1, 1);

        MarginLBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginLBlineEdit->setObjectName(QStringLiteral("MarginLBlineEdit"));
        MarginLBlineEdit->setMinimumSize(QSize(0, 40));
        MarginLBlineEdit->setFont(font1);

        gridLayout->addWidget(MarginLBlineEdit, 0, 1, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(widget, 0, 2, 1, 1);

        frame = new QFrame(ParaSytemSetDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(200, 470, 341, 81));
        frame->setFont(font1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 0, 321, 81));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        UpdatepushButton = new QPushButton(horizontalLayoutWidget_2);
        UpdatepushButton->setObjectName(QStringLiteral("UpdatepushButton"));
        UpdatepushButton->setMinimumSize(QSize(80, 40));
        UpdatepushButton->setFont(font1);

        horizontalLayout_2->addWidget(UpdatepushButton);

        CancelpushButton = new QPushButton(horizontalLayoutWidget_2);
        CancelpushButton->setObjectName(QStringLiteral("CancelpushButton"));
        CancelpushButton->setMinimumSize(QSize(80, 40));
        CancelpushButton->setFont(font1);

        horizontalLayout_2->addWidget(CancelpushButton);


        retranslateUi(ParaSytemSetDialog);

        QMetaObject::connectSlotsByName(ParaSytemSetDialog);
    } // setupUi

    void retranslateUi(QDialog *ParaSytemSetDialog)
    {
        ParaSytemSetDialog->setWindowTitle(QApplication::translate("ParaSytemSetDialog", "Dialog", nullptr));
        label_5->setText(QApplication::translate("ParaSytemSetDialog", "\345\267\246\344\276\247\351\273\221\345\242\250\346\216\247\345\210\266\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_8->setText(QApplication::translate("ParaSytemSetDialog", "\345\217\263\344\276\247\351\273\221\345\242\250\346\216\247\345\210\266\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ParaSytemSetDialog", "\345\217\263\344\276\247\347\231\275\345\242\250\346\216\247\345\210\266\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_6->setText(QApplication::translate("ParaSytemSetDialog", "\345\267\246\344\276\247\347\231\275\345\242\250\346\216\247\345\210\266\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        UpdatepushButton->setText(QApplication::translate("ParaSytemSetDialog", "\347\241\256\350\256\244", nullptr));
        CancelpushButton->setText(QApplication::translate("ParaSytemSetDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParaSytemSetDialog: public Ui_ParaSytemSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARASYTEMSETDIALOG_H
