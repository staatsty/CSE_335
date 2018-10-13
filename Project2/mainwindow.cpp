/*
*mainwindow where functions and slots are defined, most work don here, creates a basic shopping UI.
* Author: Tyler Staats,Samuel Batali
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include "pet.h"
#include "bird.h"
#include "cat.h"
#include "fish.h"
#include "dog.h"
#include "databuilder.h"
#include "dataparser.h"
#include <QDir>
#include "BubbleSortDecreasing.h"
#include "PetDatabaseSortableByName.h"
#include "bundle.h"
#include "nonstackedbasedsumvisitor.h"
#include "ui_dialog.h"
#include "dialog.h"
#include "newtablewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows );//sets taables interface
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection );
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows );
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection );
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //sets table widget color full setup is in
    ui->tableWidget->setStyleSheet("QHeaderView::section { background-color:lightgray }");//the load button slot
    ui->tableWidget_2->setStyleSheet("QHeaderView::section { background-color:lightgray }");
    ui->addButton->setEnabled(false);//disable add to cart untill data is loaded in
    if (listeners.size()<1){
   Dialog* newListener = new Dialog(this);
    listeners.push_back(newListener); //makes popout cart window only 1
    }
    connect(listeners[0], SIGNAL(lockInterface()),//connects dialog signal to this window
    this, SLOT(interfaceLocked())); //for locking interface at checkout


}

MainWindow::~MainWindow()//dtor
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    DataBuilder builder;
    DataParser parser;
    parser.setBuilder(&builder); //uses builder pattern to load database with pet data

    parser.parseInv("Pets.csv");
    vector<Pet*> allPets = builder.getExpression();
    BubbleSortDecreasing bsd;
    PetDatabaseSortableByName petDatabaseSortableByName(allPets); //sorts the data after being built using abstract factory
    bsd.sort(&petDatabaseSortableByName);
    vector<Pet*> sorted_vec = petDatabaseSortableByName.getVector();
    ui-> tableWidget->setRowCount(allPets.size());
    ui-> tableWidget->setColumnCount(4);         //sets up the table
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->verticalHeader()->setVisible(false);

   for(unsigned int i=0;i<sorted_vec.size();i++){ //loads data into table
       sorted_vec[i]->addtotable(ui->tableWidget,i);
   }

   DataBuilder builder1;
   parser.setBuilder(&builder1);
   parser.parseBundle("Bundles.csv"); //sorts bundle data using builder pattern
   vector<Pet*> allbundles = builder1.getExpression();
      for(unsigned int i=0; i<allbundles.size();i++){
          vector<Pet*> discount;
          vector<string> compare_vec = allbundles[i]->getVec(); //after bundle is made need to compare
          for(unsigned int j=0;j<compare_vec.size();j++){ //bundle pets to pets stored in invtory
              for(unsigned int k=0;k<sorted_vec.size();k++){//this is so wecan have the individual prices to visit
                  if(compare_vec[j]==sorted_vec[k]->GetName()){//when applying visitor pattern
                      discount.push_back(sorted_vec[k]);
                  }
                  else{
                      continue;
                  }
              }
          }
          NonStackBasedSumVisitor sbsv;//after we have the vector full of discount pets(all pets in the bundle)
          for(unsigned int i=0;i<discount.size();i++){//use vistor pattern to find the sum before discount
              discount[i]->Accept(&sbsv);
          }
          double petSums=sbsv.getResult();
          double bundlePrice = allbundles[i]->GetPrice();
          double discountPrecent = (petSums-bundlePrice)/petSums;
          int precent = discountPrecent * 100;
          allbundles[i]->SetDiscount(precent); //sets the discount price once found

      }

   //truns add cart putton on since data now exsist
   BubbleSortDecreasing bsd1;
   PetDatabaseSortableByName petDatabaseSortableByName1(allbundles);//sorts the bundle now using abstract factory
   bsd1.sort(&petDatabaseSortableByName1);
   vector<Pet*> sorted_bundle = petDatabaseSortableByName1.getVector();
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui-> tableWidget_2->setRowCount(sorted_bundle.size());
    ui-> tableWidget_2->setColumnCount(3);        //sets up table now with correct data
    ui->tableWidget_2->setShowGrid(false);

   for(unsigned int i=0;i<sorted_bundle.size();i++){
       sorted_bundle[i]->addtotable(ui->tableWidget_2,i);
   }


}

void MainWindow::on_tableWidget_cellClicked(int row, int column)//if one cell is clicked highlights entire row
{
    ui->addButton->setEnabled(true);
    column = 0;                                                 //also stores data that would be needed for adding
    ui->tableWidget->selectRow(row);
    ui->tableWidget->setName( ui->tableWidget->item(row,column)->text());
    ui->tableWidget->setPrice( ui->tableWidget->item(row,2)->data(Qt::DisplayRole).toDouble());
    ui->tableWidget->setTable(true);
    ui->tableWidget_2->setTable(false);



}

void MainWindow::on_tableWidget_2_cellClicked(int row, int column)//if one cell is clicked highlights entire row
{   column = 0;
    ui->addButton->setEnabled(true);
    ui->tableWidget_2->selectRow(row);                           //also stores data that would be needed for adding
    ui->tableWidget_2->setName( ui->tableWidget_2->item(row,column)->text());
    ui->tableWidget_2->setPrice( ui->tableWidget_2->item(row,1)->data(Qt::DisplayRole).toDouble());
    ui->tableWidget->setTable(false);
    ui->tableWidget_2->setTable(true);
}

void MainWindow::on_addButton_clicked()
{

    connect(this, SIGNAL(addData(QString ,double)),//connects signal add data to this window
    listeners[0], SLOT(dataAdd(QString ,double)),Qt::UniqueConnection);

    if (ui->tableWidget->getTable()){
    emit addData(ui->tableWidget->getName(),ui->tableWidget->getPrice());//emits signal based on which table is selected
    }
    if(ui->tableWidget_2->getTable()){
        emit addData(ui->tableWidget_2->getName(),ui->tableWidget_2->getPrice());
    }



}
void MainWindow::interfaceLocked(){ //locks interface at checkout
    ui->loadButton->setEnabled(false);
    ui->addButton->setEnabled(false);
    ui->showButton->setEnabled(false);
}

void MainWindow::on_showButton_clicked() //shows cart
{
    listeners[0]->show();
}
