/*
 *Bird class that stores attributes for a bird
 * This class is derived from the pet base class
 */

/*
 * File:   Bird.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */

#ifndef BIRD_H
#define BIRD_H
#include <QTableWidget>
#include <string>
#include <iostream>
#include <iomanip>
#include <QTableWidgetItem>
#include "Pet.h"
using namespace std;

class Bird: public Pet {
 public:
 Bird(string a, double c,string b, string d, bool e):Pet(a,c,b,d),m_Nocturnality(e){ //ctor of Bird

    };

 Bird(const Bird& bird) = default; //copy ctor
 Bird& operator=(const Bird& bird) = default; //assign overload
 virtual ~Bird(){ //dtor of bird

    }

 bool GetNocturnality() const {
     return m_Nocturnality; //returns if a bird is nocturnal or not
 }

 void SetNocturnality(const bool& nocturnal){
     m_Nocturnality = nocturnal; //sets whether a bird is nocturnal or not
 }



virtual void Accept(Visitor* v){v->visitBird(this);}//for visitor pattern

 void addtotable(QTableWidget* table,int i)const{
     QString qstr = QString::fromStdString(m_Name);
     QString qstr1 = QString::fromStdString(m_Class);
     QString qstr2 = QString::fromStdString(m_Type);
     QString qstr3 = QString::number(m_Price);        //this takes needed bird data
     QString qstr4 = QString::fromStdString("Diurnal ");//and adds it to given table
     if(m_Nocturnality){
         qstr4 = qstr2;
     }
     else{
         qstr4 += qstr2;
     }
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
     itab2->setText(qstr4);
     itab3->setData(Qt::DisplayRole,m_Price);
     table->setItem(i, 0, itab);
     table->setItem(i, 1, itab1);
     table->setItem(i, 3, itab2);
     table->setItem(i, 2, itab3);
 }

 virtual vector<string> getVec() const{//return vec needed for bundle class
     vector<string> blank_vec;
     return blank_vec;
 }
protected:
Bird() = default; //default ctor protected so client cant access
bool m_Nocturnality;
};


#endif /* BIRD_H */

