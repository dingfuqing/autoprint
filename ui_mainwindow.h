/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Userlogaction;
    QAction *Useraddaction;
    QAction *Modifyaction;
    QAction *Deleteaction;
    QAction *Exitaction;
    QAction *Datamanger;
    QAction *setsysetm;
    QAction *logfileinfo;
    QAction *Colormanger;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *MarginRBlineEdit;
    QLabel *label_5;
    QLineEdit *MarginRWlineEdit;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *MarginLBlineEdit;
    QLineEdit *MarginLWlineEdit;
    QWidget *widget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *TypelineEdit;
    QLineEdit *DatalineEdit;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_9;
    QComboBox *ClearNoz_comboBox;
    QComboBox *ColorSelect_comboBox;
    QLabel *label_10;
    QComboBox *SelectFile_comboBox;
    QFrame *planframe;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *SendDataButton;
    QPushButton *PrintInfoButton;
    QPushButton *ClearButton;
    QTableView *TypetableView;
    QMenuBar *menuBar;
    QMenu *UserMangerMenu;
    QMenu *DataMangerMenu;
    QMenu *SystemMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setBaseSize(QSize(800, 600));
        Userlogaction = new QAction(MainWindow);
        Userlogaction->setObjectName(QStringLiteral("Userlogaction"));
        Useraddaction = new QAction(MainWindow);
        Useraddaction->setObjectName(QStringLiteral("Useraddaction"));
        Modifyaction = new QAction(MainWindow);
        Modifyaction->setObjectName(QStringLiteral("Modifyaction"));
        Deleteaction = new QAction(MainWindow);
        Deleteaction->setObjectName(QStringLiteral("Deleteaction"));
        Exitaction = new QAction(MainWindow);
        Exitaction->setObjectName(QStringLiteral("Exitaction"));
        Datamanger = new QAction(MainWindow);
        Datamanger->setObjectName(QStringLiteral("Datamanger"));
        setsysetm = new QAction(MainWindow);
        setsysetm->setObjectName(QStringLiteral("setsysetm"));
        logfileinfo = new QAction(MainWindow);
        logfileinfo->setObjectName(QStringLiteral("logfileinfo"));
        Colormanger = new QAction(MainWindow);
        Colormanger->setObjectName(QStringLiteral("Colormanger"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 290, 711, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        MarginRBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginRBlineEdit->setObjectName(QStringLiteral("MarginRBlineEdit"));
        MarginRBlineEdit->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(14);
        MarginRBlineEdit->setFont(font);

        gridLayout->addWidget(MarginRBlineEdit, 0, 5, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        MarginRWlineEdit = new QLineEdit(gridLayoutWidget);
        MarginRWlineEdit->setObjectName(QStringLiteral("MarginRWlineEdit"));
        MarginRWlineEdit->setMinimumSize(QSize(0, 40));
        MarginRWlineEdit->setFont(font);

        gridLayout->addWidget(MarginRWlineEdit, 1, 5, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 4, 1, 1);

        MarginLBlineEdit = new QLineEdit(gridLayoutWidget);
        MarginLBlineEdit->setObjectName(QStringLiteral("MarginLBlineEdit"));
        MarginLBlineEdit->setMinimumSize(QSize(0, 40));
        MarginLBlineEdit->setFont(font);

        gridLayout->addWidget(MarginLBlineEdit, 0, 2, 1, 1);

        MarginLWlineEdit = new QLineEdit(gridLayoutWidget);
        MarginLWlineEdit->setObjectName(QStringLiteral("MarginLWlineEdit"));
        MarginLWlineEdit->setMinimumSize(QSize(0, 40));
        MarginLWlineEdit->setFont(font);

        gridLayout->addWidget(MarginLWlineEdit, 1, 2, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(widget, 0, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 20, 441, 211));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(105, 0));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(105, 0));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(105, 0));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(120, 40));
        lineEdit->setFont(font);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        TypelineEdit = new QLineEdit(gridLayoutWidget_2);
        TypelineEdit->setObjectName(QStringLiteral("TypelineEdit"));
        TypelineEdit->setMinimumSize(QSize(120, 40));
        TypelineEdit->setFont(font);

        gridLayout_2->addWidget(TypelineEdit, 1, 1, 1, 1);

        DatalineEdit = new QLineEdit(gridLayoutWidget_2);
        DatalineEdit->setObjectName(QStringLiteral("DatalineEdit"));
        DatalineEdit->setMinimumSize(QSize(120, 40));
        DatalineEdit->setFont(font);

        gridLayout_2->addWidget(DatalineEdit, 2, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(500, 20, 231, 211));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(80, 40));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(80, 40));

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        ClearNoz_comboBox = new QComboBox(gridLayoutWidget_3);
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->addItem(QString());
        ClearNoz_comboBox->setObjectName(QStringLiteral("ClearNoz_comboBox"));
        ClearNoz_comboBox->setMinimumSize(QSize(120, 40));
        ClearNoz_comboBox->setFont(font);

        gridLayout_3->addWidget(ClearNoz_comboBox, 1, 1, 1, 1);

        ColorSelect_comboBox = new QComboBox(gridLayoutWidget_3);
        ColorSelect_comboBox->addItem(QString());
        ColorSelect_comboBox->addItem(QString());
        ColorSelect_comboBox->setObjectName(QStringLiteral("ColorSelect_comboBox"));
        ColorSelect_comboBox->setMinimumSize(QSize(120, 40));
        ColorSelect_comboBox->setFont(font);

        gridLayout_3->addWidget(ColorSelect_comboBox, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(80, 40));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        SelectFile_comboBox = new QComboBox(gridLayoutWidget_3);
        SelectFile_comboBox->addItem(QString());
        SelectFile_comboBox->addItem(QString());
        SelectFile_comboBox->addItem(QString());
        SelectFile_comboBox->setObjectName(QStringLiteral("SelectFile_comboBox"));
        SelectFile_comboBox->setMinimumSize(QSize(120, 40));
        SelectFile_comboBox->setFont(font);

        gridLayout_3->addWidget(SelectFile_comboBox, 2, 1, 1, 1);

        planframe = new QFrame(centralWidget);
        planframe->setObjectName(QStringLiteral("planframe"));
        planframe->setGeometry(QRect(200, 440, 391, 81));
        planframe->setFrameShape(QFrame::StyledPanel);
        planframe->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(planframe);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 371, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SendDataButton = new QPushButton(horizontalLayoutWidget);
        SendDataButton->setObjectName(QStringLiteral("SendDataButton"));
        SendDataButton->setMinimumSize(QSize(80, 40));
        SendDataButton->setFont(font);

        horizontalLayout->addWidget(SendDataButton);

        PrintInfoButton = new QPushButton(horizontalLayoutWidget);
        PrintInfoButton->setObjectName(QStringLiteral("PrintInfoButton"));
        PrintInfoButton->setMinimumSize(QSize(80, 40));
        PrintInfoButton->setFont(font);

        horizontalLayout->addWidget(PrintInfoButton);

        ClearButton = new QPushButton(horizontalLayoutWidget);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));
        ClearButton->setMinimumSize(QSize(80, 40));
        ClearButton->setFont(font);

        horizontalLayout->addWidget(ClearButton);

        TypetableView = new QTableView(centralWidget);
        TypetableView->setObjectName(QStringLiteral("TypetableView"));
        TypetableView->setGeometry(QRect(20, 240, 21, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        UserMangerMenu = new QMenu(menuBar);
        UserMangerMenu->setObjectName(QStringLiteral("UserMangerMenu"));
        DataMangerMenu = new QMenu(menuBar);
        DataMangerMenu->setObjectName(QStringLiteral("DataMangerMenu"));
        SystemMenu = new QMenu(menuBar);
        SystemMenu->setObjectName(QStringLiteral("SystemMenu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(14);
        statusBar->setFont(font1);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(UserMangerMenu->menuAction());
        menuBar->addAction(DataMangerMenu->menuAction());
        menuBar->addAction(SystemMenu->menuAction());
        UserMangerMenu->addAction(Userlogaction);
        UserMangerMenu->addAction(Useraddaction);
        UserMangerMenu->addAction(Modifyaction);
        UserMangerMenu->addAction(Deleteaction);
        UserMangerMenu->addAction(Exitaction);
        DataMangerMenu->addAction(Datamanger);
        DataMangerMenu->addAction(Colormanger);
        DataMangerMenu->addAction(logfileinfo);
        SystemMenu->addAction(setsysetm);

        retranslateUi(MainWindow);

        ClearNoz_comboBox->setCurrentIndex(0);
        ColorSelect_comboBox->setCurrentIndex(0);
        SelectFile_comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\235\222\345\262\233\344\270\200\346\261\275\347\224\237\344\272\247\347\272\277\345\226\267\345\215\260\346\216\247\345\210\266\350\275\257\344\273\266", nullptr));
        Userlogaction->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        Useraddaction->setText(QApplication::translate("MainWindow", "\346\226\260\345\242\236\347\224\250\346\210\267", nullptr));
        Modifyaction->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        Deleteaction->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        Exitaction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        Datamanger->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        Datamanger->setIconText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
#ifndef QT_NO_TOOLTIP
        Datamanger->setToolTip(QApplication::translate("MainWindow", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
#endif // QT_NO_TOOLTIP
        setsysetm->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\231\250IP\345\234\260\345\235\200", nullptr));
        logfileinfo->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\346\226\207\344\273\266", nullptr));
        Colormanger->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\256\241\347\220\206", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\217\263\344\276\247\351\273\221\345\242\250\345\226\267\345\244\264\350\276\271\350\267\235\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\267\246\344\276\247\351\273\221\345\242\250\345\226\267\345\244\264\350\276\271\350\267\235\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\267\246\344\276\247\347\231\275\345\242\250\345\226\267\345\244\264\350\276\271\350\267\235\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\217\263\344\276\247\347\231\275\345\242\250\345\226\267\345\244\264\350\276\271\350\267\235\357\274\232", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\344\277\241\346\201\257\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\226\267\345\215\260\344\277\241\346\201\257\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\275\246\345\236\213\344\277\241\346\201\257\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\226\267\345\215\260\351\242\234\350\211\262\351\200\211\346\213\251\357\274\232", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\351\242\204\345\226\267\351\227\264\351\232\224\346\227\266\351\227\264\357\274\232", nullptr));
        ClearNoz_comboBox->setItemText(0, QApplication::translate("MainWindow", "15\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(1, QApplication::translate("MainWindow", "30\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(2, QApplication::translate("MainWindow", "45\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(3, QApplication::translate("MainWindow", "60\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(4, QApplication::translate("MainWindow", "75\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(5, QApplication::translate("MainWindow", "90\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(6, QApplication::translate("MainWindow", "105\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(7, QApplication::translate("MainWindow", "120\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(8, QApplication::translate("MainWindow", "135\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(9, QApplication::translate("MainWindow", "150\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(10, QApplication::translate("MainWindow", "165\347\247\222", nullptr));
        ClearNoz_comboBox->setItemText(11, QApplication::translate("MainWindow", "180\347\247\222", nullptr));

        ClearNoz_comboBox->setCurrentText(QApplication::translate("MainWindow", "15\347\247\222", nullptr));
        ColorSelect_comboBox->setItemText(0, QApplication::translate("MainWindow", "\351\273\221\350\211\262", nullptr));
        ColorSelect_comboBox->setItemText(1, QApplication::translate("MainWindow", "\347\231\275\350\211\262", nullptr));

        ColorSelect_comboBox->setCurrentText(QApplication::translate("MainWindow", "\351\273\221\350\211\262", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\226\207\344\273\266\351\200\211\346\213\251\357\274\232", nullptr));
        SelectFile_comboBox->setItemText(0, QApplication::translate("MainWindow", "ALERIS", nullptr));
        SelectFile_comboBox->setItemText(1, QApplication::translate("MainWindow", "\350\245\277\345\215\2272", nullptr));
        SelectFile_comboBox->setItemText(2, QApplication::translate("MainWindow", "\350\245\277\345\215\2273", nullptr));

        SelectFile_comboBox->setCurrentText(QApplication::translate("MainWindow", "ALERIS", nullptr));
        SendDataButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        PrintInfoButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\211\223\345\215\260", nullptr));
        ClearButton->setText(QApplication::translate("MainWindow", "\351\242\204\345\226\267", nullptr));
        UserMangerMenu->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        DataMangerMenu->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        SystemMenu->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
