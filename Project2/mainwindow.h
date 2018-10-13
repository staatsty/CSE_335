/*
 * File:   mainwindow.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include<QTableWidgetItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void addData(QString ,double); //custom signal to add data


private slots:
    void interfaceLocked(); //slots used to define siganls
    void on_loadButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);
    void on_tableWidget_2_cellClicked(int row, int column);

    void on_addButton_clicked();

    void on_showButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog* mDialog;
    std::vector<Dialog*> listeners;
};

#endif // MAINWINDOW_H
