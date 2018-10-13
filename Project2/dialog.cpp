//dialog functions defined
//Author: Tyler Staats,Samuel Batali
#include "dialog.h"
#include "ui_dialog.h"
#include "newtablewidget.h"
#include<iostream>
#include<newtablewidget.h>
#include <iostream>
#include <fstream>
Dialog::Dialog(QWidget *parent) : //ctor
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui-> tableWidget_3->setRowCount(100);
    ui-> tableWidget_3->setColumnCount(2); //sets up table widget and formats interface a bit
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_3->setStyleSheet("QHeaderView::section { background-color:lightgray }");//sets table widget color
    ui->tableWidget_3->setShowGrid(false);
    ui->tableWidget_3->verticalHeader()->setVisible(false);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows );
    ui->tableWidget_3->setSelectionMode(QAbstractItemView::SingleSelection );

}

Dialog::~Dialog() //dtor
{
    delete ui;
}

void Dialog::dataAdd(QString item1 ,double item2){ //slot for adding data to widget from mainwindow

    QTableWidgetItem *itab,*itab1;
    itab = new QTableWidgetItem;
    itab1 = new QTableWidgetItem;
    itab->setFlags(itab->flags() & ~Qt::ItemIsEditable);
    itab1->setFlags(itab1->flags() & ~Qt::ItemIsEditable); //takes data and inserts into proper spot
    itab->setText(item1);
    itab1->setData(Qt::DisplayRole,item2);
    ui->tableWidget_3->setItem(m_rowCount, 0,itab);
    ui->tableWidget_3->setItem(m_rowCount, 1, itab1);
    m_rowCount+=1;
}

void Dialog::on_deleteButton_clicked()
{
    ui->tableWidget_3->removeRow(ui->tableWidget_3->getCurrentRow());//deletes selected row from table
   m_rowCount-=1;

}

void Dialog::on_tableWidget_3_cellClicked(int row, int column)
{
    column = 0;
    ui->tableWidget_3->selectRow(row); //stores data from selected row for use
    ui->tableWidget_3->setName( ui->tableWidget_3->item(row,column)->text());
    ui->tableWidget_3->setPrice( ui->tableWidget_3->item(row,1)->data(Qt::DisplayRole).toDouble());
    ui->tableWidget_3->setCurrentRow(row);

}

void Dialog::on_checkoutButton_clicked()
{
    ui->tableWidget_3->sortByColumn(1,Qt::AscendingOrder); //sorts data at checkout
    double sum = 0;
     for(int i = 0; i<m_rowCount;i++){
        sum += ui->tableWidget_3->item(i,1)->data(Qt::DisplayRole).toDouble(); //loops to find a sum
    }
    QString totalAsString = QString::number(sum);
    ui->totalLabel->setText("Total: $"+totalAsString);
    ui->totalLabel->setStyleSheet("font-weight: bold; color: red;");//sets text label to nice output
    QFont font= ui->totalLabel->font();
    font.setPointSize(18);
    ui->totalLabel->setFont(font);

    ui->deleteButton->setEnabled(false);
    ui->checkoutButton->setEnabled(false); //disables some interface
    std::ofstream myfile;
    myfile.open("checkout.txt");
    for(int i = 0; i<m_rowCount;i++){
        myfile<< ui->tableWidget_3->item(i,0)->text().toStdString()<<","; //creates the text file to act as a receipt
       myfile<< ui->tableWidget_3->item(i,1)->data(Qt::DisplayRole).toDouble()<<std::endl;
   }
    emit lockInterface(); //signal to lock interface in main window
}
