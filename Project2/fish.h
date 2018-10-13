/*
 * Derived from Pet base class
 */

/*
 * File:   Fish.h
 * Author: Tyler Staats,  Samuel Batali
 *
 *
 */

#ifndef FISH_H
#define FISH_H
#include <QTableWidget>
#include <string>
#include <iostream>
#include <iomanip>
#include "visitor.h"
#include "pet.h"
using namespace std;

class Fish: public Pet{
public:
 Fish(string a,double c,string b, string d, string e):Pet(a,c,b,d),m_Water(e){ //ctor of Fish

    };

 Fish(const Fish& fish) = default; //copy ctor
 Fish& operator=(const Fish& fish) = default; //assign overload
 virtual ~Fish(){ //dtor of fish

    }

 string GetWater()const{ //returns water type
     return m_Water;
 }

 void SetWater(const string& water){ //sets water type
     m_Water = water;
 }

 virtual vector<string> getVec() const{
     vector<string> blank_vec;
     return blank_vec;
 }



 void addtotable(QTableWidget* table,int i)const{ //adds fish to given table
     QString qstr = QString::fromStdString(m_Name);
     QString qstr1 = QString::fromStdString(m_Class);
     QString qstr2 = QString::fromStdString(m_Water)+" "+QString::fromStdString(m_Type);
     QString qstr3 = QString::number(m_Price);
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

virtual void Accept(Visitor* v){v->visitFish(this);}
protected:
Fish()=default; //default ctor protected so client cant access
string m_Water;
};


#endif /* FISH_H */

