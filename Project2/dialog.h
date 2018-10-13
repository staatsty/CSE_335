/*
 * File:   dialog.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTableWidgetItem>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog //inherits from q dialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0); //declared public
    ~Dialog();                            //functions
    Ui::Dialog* getUi() const {return ui;}

signals:
    void lockInterface(); //signal to lock interface at checkout
private slots:

    void dataAdd(QString,double); //slot for adding data to table
    void on_deleteButton_clicked(); //slots for interface

    void on_tableWidget_3_cellClicked(int row, int column);

    void on_checkoutButton_clicked();

private:
    Ui::Dialog *ui;
    int m_rowCount=0;//variable to keep track  of current row number in tablewidget3
};

#endif // DIALOG_H
