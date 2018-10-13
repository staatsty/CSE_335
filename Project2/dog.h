/*
 *dog class is derived from the Pet Base class
 */

/*
 * File:   Dog.h
 * Author: Tyler Staats, Samuel Batali
 *
 */

#ifndef DOG_H
#define DOG_H
#include <QTableWidget>
#include <string>
#include <iostream>
#include <iomanip>
#include "visitor.h"
using namespace std;

class Dog : public Pet{
public:
 Dog(string a,double c, string b, string d, string e):Pet(a,c,b,d),m_Category(e){ //ctor Dog

    };
 Dog(const Dog& dog) = default; //copy ctor
 Dog& operator=(const Dog& dog) = default; //assign overload
 virtual ~Dog(){  //dtor of dog

    }

 string GetCategory()const{ //returns category
    return m_Category;
 }

 void SetCategory(const string& category){ //sets category
     m_Category = category;
 }



 void addtotable(QTableWidget* table,int i)const{
     QString qstr = QString::fromStdString(m_Name);
     QString qstr1 = QString::fromStdString(m_Class); //adds dog to  given table
     QString qstr2 = QString::fromStdString(m_Category)+" "+QString::fromStdString(m_Type);
     QString qstr3 = QString::number(m_Price);
     QString qstr4 = QString::fromStdString("Fluffy ");
     QTableWidgetItem *itab,*itab1,*itab2,*itab3;
     itab = new QTableWidgetItem;
     itab1 = new QTableWidgetItem;
     itab2 = new QTableWidgetItem;
     itab3 = new QTableWidgetItem;
     itab->setFlags(itab->flags() & ~Qt::ItemIsEditable);
     itab1->setFlags(itab1->flags() & ~Qt::ItemIsEditable);
     itab2->setFlags(itab2->flags() & ~Qt::ItemIsEditable);
     itab3->setFlags(itab3->flags() & ~Qt::ItemIsEditable);
     itab->setText(qstr);
     itab1->setText(qstr1);
     itab2->setText(qstr2);
     itab3->setData(Qt::DisplayRole,m_Price);
     table->setItem(i, 0, itab);
     table->setItem(i, 1, itab1);
     table->setItem(i, 3, itab2);
     table->setItem(i, 2, itab3);
 }

 virtual vector<string> getVec() const{//needed for bundle
     vector<string> blank_vec;
     return blank_vec;
 }
 virtual void Accept(Visitor* v){v->visitDog(this);}//needed for visitor pattern
protected:
Dog()=default; //default ctor protected so clients cant access
string m_Category;

};





#endif /* DOG_H */

