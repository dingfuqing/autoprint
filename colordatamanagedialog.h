#ifndef COLORDATAMANAGEDIALOG_H
#define COLORDATAMANAGEDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "databaseoperation.h"
namespace Ui {
class ColorDataManageDialog;
}

class ColorDataManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColorDataManageDialog(QWidget *parent = 0);
    ~ColorDataManageDialog();

    void QuerypushDataInfoHnadle();

    bool eventFilter(QObject *target, QEvent *event);
    void SetOperationOfLevel();
    QString GetSGSendData(QString str, QString index);void FillTypetableView();

private:
    Ui::ColorDataManageDialog *ui;

    DataBaseOperation databaseoperation;
    QStandardItemModel * model;
    bool showview;
    int typeindex;
    int printcolor_index;
  private slots:

      void on_DeletepushButton_released();
      void on_DeletepushButton_pressed();
      void on_UpdatepushButton_released();
      void on_UpdatepushButton_pressed();
      void on_InsertpushButton_released();
      void on_InsertpushButton_pressed();
      void on_QuerypushButton_released();
      void on_QuerypushButton_pressed();
      void ShowTypetableView();

      void on_TypetableView_clicked(QModelIndex index);
      void on_TypetableView_pressed(const QModelIndex &index);
      void on_printcolor_comboBox_currentIndexChanged(int index);
};

#endif // COLORDATAMANAGEDIALOG_H
