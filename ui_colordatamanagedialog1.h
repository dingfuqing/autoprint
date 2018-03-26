/********************************************************************************
** Form generated from reading UI file 'colordatamanagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORDATAMANAGEDIALOG_H
#define UI_COLORDATAMANAGEDIALOG_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorDataManageDialog
{
public:
    QPushButton *QuerypushButton;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *InsertpushButton;
    QPushButton *UpdatepushButton;
    QPushButton *DeletepushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *MarginLBlineEdit;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *MarginRBlineEdit;
    QWidget *widget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *TypelineEdit;
    QLabel *label;
    QTableView *TypetableView;

    void setupUi(QDialog *ColorDataManageDialog)
    {
        if (ColorDataManageDialog->objectName().isEmpty())
            ColorDataManageDialog->setObjectName(QStringLiteral("ColorDataManageDialog"));
        ColorDataManageDialog->resize(800, 600);
        QuerypushButton = new QPushButton(ColorDataManageDialog);
        QuerypushButton->setObjectName(QStringLiteral("QuerypushButton"));
        QuerypushButton->setGeometry(QRect(630, 55, 141, 40));
        QuerypushButton->setMinimumSize(QSize(80, 40));
        QFont font;
        font.setPointSize(14);
        QuerypushButton->setFont(font);
        frame = new QFrame(ColorDataManageDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(200, 480, 411, 81));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 391, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        InsertpushButton = new QPushButton(horizontalLayoutWidget);
        InsertpushButton->setObjectName(QStringLiteral("InsertpushButton"));
        InsertpushButton->setMinimumSize(QSize(80, 40));
        InsertpushButton->setFont(font);

        horizontalLayout->addWidget(InsertpushButton);

        UpdatepushButton = new QPushButton(horizontalLayoutWidget);
        UpdatepushButton->setObjectName(QStringLiteral("UpdatepushButton"));
        UpdatepushButton->setMinimumSize(QSize(80, 40));
        UpdatepushButton->setFont(font);

        horizontalLayout->addWidget(UpdatepushButton);

        DeletepushButton = new QPushButton(horizontalLayoutWidget);
        DeletepushButton->setObjectName(QStringLiteral("DeletepushButton"));
        DeletepushButton->setMinimumSize(QSize(80, 40));
        DeletepushButton->setFont(font);

        horizontalLayout->addWidget(DeletepushButton);

        gridLayoutWidget = new QWidget(ColorDataManageDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 190, 741, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MarginLBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginLBlineEdit->setObjectName(QStringLiteral("MarginLBlineEdit"));
        MarginLBlineEdit->setMinimumSize(QSize(0, 40));
        MarginLBlineEdit->setFont(font);

        gridLayout->addWidget(MarginLBlineEdit, 0, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(105, 0));
        QFont font1;
        font1.setPointSize(9);
        label_8->setFont(font1);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(105, 0));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        MarginRBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginRBlineEdit->setObjectName(QStringLiteral("MarginRBlineEdit"));
        MarginRBlineEdit->setMinimumSize(QSize(0, 40));
        MarginRBlineEdit->setFont(font);

        gridLayout->addWidget(MarginRBlineEdit, 0, 4, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(widget, 0, 2, 1, 1);

        gridLayoutWidget_2 = new QWidget(ColorDataManageDialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 49, 331, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        TypelineEdit = new QLineEdit(gridLayoutWidget_2);
        TypelineEdit->setObjectName(QStringLiteral("TypelineEdit"));
        TypelineEdit->setMinimumSize(QSize(0, 40));
        TypelineEdit->setFont(font);

        gridLayout_2->addWidget(TypelineEdit, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(105, 0));
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        TypetableView = new QTableView(ColorDataManageDialog);
        TypetableView->setObjectName(QStringLiteral("TypetableView"));
        TypetableView->setGeometry(QRect(390, 60, 16, 21));
        QWidget::setTabOrder(TypelineEdit, DeletepushButton);
        QWidget::setTabOrder(DeletepushButton, InsertpushButton);
        QWidget::setTabOrder(InsertpushButton, UpdatepushButton);
        QWidget::setTabOrder(UpdatepushButton, QuerypushButton);

        retranslateUi(ColorDataManageDialog);

        QMetaObject::connectSlotsByName(ColorDataManageDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorDataManageDialog)
    {
        ColorDataManageDialog->setWindowTitle(QApplication::translate("ColorDataManageDialog", "Dialog", nullptr));
        QuerypushButton->setText(QApplication::translate("ColorDataManageDialog", "\346\237\245\350\257\242", nullptr));
        InsertpushButton->setText(QApplication::translate("ColorDataManageDialog", "\346\267\273\345\212\240", nullptr));
        UpdatepushButton->setText(QApplication::translate("ColorDataManageDialog", "\344\277\256\346\224\271", nullptr));
        DeletepushButton->setText(QApplication::translate("ColorDataManageDialog", "\345\210\240\351\231\244", nullptr));
        label_8->setText(QApplication::translate("ColorDataManageDialog", "\351\273\221\347\231\275\351\200\211\346\213\251\357\274\232", nullptr));
        label_5->setText(QApplication::translate("ColorDataManageDialog", "\345\226\267\346\274\206\351\242\234\350\211\262\357\274\232", nullptr));
        label->setText(QApplication::translate("ColorDataManageDialog", "\347\264\242\345\274\225\351\242\234\350\211\262\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorDataManageDialog: public Ui_ColorDataManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDATAMANAGEDIALOG_H
