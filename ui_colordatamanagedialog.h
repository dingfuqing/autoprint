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
#include <QtWidgets/QComboBox>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *MarginLBlineEdit;
    QWidget *widget;
    QComboBox *printcolor_comboBox;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *InsertpushButton;
    QPushButton *UpdatepushButton;
    QPushButton *DeletepushButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *TypelineEdit;
    QLabel *label;
    QPushButton *QuerypushButton;
    QTableView *TypetableView;

    void setupUi(QDialog *ColorDataManageDialog)
    {
        if (ColorDataManageDialog->objectName().isEmpty())
            ColorDataManageDialog->setObjectName(QStringLiteral("ColorDataManageDialog"));
        ColorDataManageDialog->resize(676, 585);
        gridLayoutWidget = new QWidget(ColorDataManageDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 220, 611, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setPointSize(9);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        MarginLBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginLBlineEdit->setObjectName(QStringLiteral("MarginLBlineEdit"));
        MarginLBlineEdit->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(14);
        MarginLBlineEdit->setFont(font1);

        gridLayout->addWidget(MarginLBlineEdit, 0, 1, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(widget, 0, 2, 1, 1);

        printcolor_comboBox = new QComboBox(gridLayoutWidget);
        printcolor_comboBox->addItem(QString());
        printcolor_comboBox->addItem(QString());
        printcolor_comboBox->setObjectName(QStringLiteral("printcolor_comboBox"));
        printcolor_comboBox->setMinimumSize(QSize(80, 40));

        gridLayout->addWidget(printcolor_comboBox, 0, 4, 1, 1);

        frame = new QFrame(ColorDataManageDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(130, 470, 401, 81));
        frame->setFont(font1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 381, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        InsertpushButton = new QPushButton(horizontalLayoutWidget);
        InsertpushButton->setObjectName(QStringLiteral("InsertpushButton"));
        InsertpushButton->setMinimumSize(QSize(80, 40));
        InsertpushButton->setFont(font1);

        horizontalLayout->addWidget(InsertpushButton);

        UpdatepushButton = new QPushButton(horizontalLayoutWidget);
        UpdatepushButton->setObjectName(QStringLiteral("UpdatepushButton"));
        UpdatepushButton->setMinimumSize(QSize(80, 40));
        UpdatepushButton->setFont(font1);

        horizontalLayout->addWidget(UpdatepushButton);

        DeletepushButton = new QPushButton(horizontalLayoutWidget);
        DeletepushButton->setObjectName(QStringLiteral("DeletepushButton"));
        DeletepushButton->setMinimumSize(QSize(80, 40));
        DeletepushButton->setFont(font1);

        horizontalLayout->addWidget(DeletepushButton);

        gridLayoutWidget_2 = new QWidget(ColorDataManageDialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 70, 341, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        TypelineEdit = new QLineEdit(gridLayoutWidget_2);
        TypelineEdit->setObjectName(QStringLiteral("TypelineEdit"));
        TypelineEdit->setMinimumSize(QSize(0, 40));
        TypelineEdit->setFont(font1);

        gridLayout_2->addWidget(TypelineEdit, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        QuerypushButton = new QPushButton(ColorDataManageDialog);
        QuerypushButton->setObjectName(QStringLiteral("QuerypushButton"));
        QuerypushButton->setGeometry(QRect(490, 80, 141, 40));
        QuerypushButton->setMinimumSize(QSize(80, 40));
        QuerypushButton->setFont(font1);
        TypetableView = new QTableView(ColorDataManageDialog);
        TypetableView->setObjectName(QStringLiteral("TypetableView"));
        TypetableView->setGeometry(QRect(390, 80, 16, 21));

        retranslateUi(ColorDataManageDialog);

        QMetaObject::connectSlotsByName(ColorDataManageDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorDataManageDialog)
    {
        ColorDataManageDialog->setWindowTitle(QApplication::translate("ColorDataManageDialog", "Dialog", nullptr));
        label_5->setText(QApplication::translate("ColorDataManageDialog", "\350\275\246\345\236\213\351\242\234\350\211\262\357\274\232", nullptr));
        label_8->setText(QApplication::translate("ColorDataManageDialog", "\345\226\267\346\266\202\351\242\234\350\211\262\357\274\232", nullptr));
        printcolor_comboBox->setItemText(0, QApplication::translate("ColorDataManageDialog", "\351\273\221\350\211\262", nullptr));
        printcolor_comboBox->setItemText(1, QApplication::translate("ColorDataManageDialog", "\347\231\275\350\211\262", nullptr));

        InsertpushButton->setText(QApplication::translate("ColorDataManageDialog", "\346\267\273\345\212\240", nullptr));
        UpdatepushButton->setText(QApplication::translate("ColorDataManageDialog", "\344\277\256\346\224\271", nullptr));
        DeletepushButton->setText(QApplication::translate("ColorDataManageDialog", "\345\210\240\351\231\244", nullptr));
        label->setText(QApplication::translate("ColorDataManageDialog", "\351\242\234\350\211\262\351\200\211\346\213\251\357\274\232", nullptr));
        QuerypushButton->setText(QApplication::translate("ColorDataManageDialog", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorDataManageDialog: public Ui_ColorDataManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDATAMANAGEDIALOG_H
