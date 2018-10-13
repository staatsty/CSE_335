/*
 *Cat class is publicly derived from Pet base class
 */

/*
 * File:   Cat.h
 * Author: Tyler Staats, Samuel Batali
 *
 *
 */

#ifndef CAT_H
#define CAT_H
#include <QTableWidget>
#include <string>
#include <iostream>
#include <iomanip>
#include "visitor.h"
using namespace std;

class Cat: public Pet{
public:
 Cat(string a, double c,string b, string d, bool e):Pet(a,c,b,d),m_Fluffy(e){ //ctor of Cat

    };

 Cat(const Cat& cat) = default; //copy ctor
 Cat& operator=(const Cat& cat) = default; //assignment overload ctor
 virtual ~Cat(){ //dtor of Cat

 }

 bool GetFluffy()const{ //returns if a cat is fluffy
     return m_Fluffy;
 }

 void SetFluffy(const bool& fluffy){ //sets if a cat is fluffy
     m_Fluffy = fluffy;
 }


virtual void Accept(Visitor* v){v->visitCat(this);}
 void addtotable(QTableWidget* table,int i) const{
     QString qstr = QString::fromStdString(m_Name);
     QString qstr1 = QString::fromStdString(m_Class);
     QString qstr2 = QString::fromStdString(m_Type);
     QString qstr3 = QString::number(m_Price);
     QString qstr4 = QString::fromStdString("Fluffy ");//adds a cat to the given table
     if(m_Fluffy){
         qstr4 += qstr2;
     }
     else{
         qstr4 = qstr2;
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

 virtual vector<string> getVec() const{
     vector<string> blank_vec;
     return blank_vec;
 }
protected:
Cat()= default; //default ctor protected so client cant access
bool m_Fluffy;
};



#endif /* CAT_H */

