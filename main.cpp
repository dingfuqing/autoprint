#include "mainwindow.h"
#include <QApplication>

#include "globe.h"

SysPara m_SysPara;
GlobalMember m_GlobalMember;
log_authcard m_log_authcard;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
