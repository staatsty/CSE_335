/*
 bundle class derived from Pet. composed of different derived classes of pet
 */

/*
 * File:   Bundle.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */

#ifndef BUNDLE_H
#define BUNDLE_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <QTableWidget>

using namespace std;

class Bundle:public Pet{ //derived from pet
protected:
    vector<Pet*> entries;

    vector<string> petNames;
    double discount;

public:
    Bundle(string name,double price,vector<string> pets):Pet(name,price,"non","non"),petNames(pets){} //ctor of bundle
    virtual ~Bundle(){
      for(unsigned int i = 0; i<entries.size();i++){ //dtor of bundle
          delete entries[i];
      }
    }
    void setDiscount(const double& num){
        discount = num;
    }
    double getDiscount()const{
        return discount;
    }

    virtual vector<string> getVec()const{
        return petNames;
    }



     virtual void Accept(Visitor* v){v->visitBundle(this);}
     void addtotable(QTableWidget* table,int i) const{
            string name = m_Name;
            QString qstr = QString::fromStdString(name); //adds a bundle to given table
            QString qstr1 = QString::number(m_Price);
            QString qstr2 = QString::number(m_Discount)+"%";
            QTableWidgetItem *itab,*itab1,*itab2;
            itab = new QTableWidgetItem;
            itab1 = new QTableWidgetItem;
            itab2 = new QTableWidgetItem;
            itab->setFlags(itab->flags() & ~Qt::ItemIsEditable);
            itab1->setFlags(itab1->flags() & ~Qt::ItemIsEditable);
            itab2->setFlags(itab2->flags() & ~Qt::ItemIsEditable);
            itab->setText(qstr);
            itab1->setData(Qt::DisplayRole,m_Price);
            itab2->setText(qstr2);
            table->setItem(i, 0, itab);
            table->setItem(i, 1, itab1);
            table->setItem(i, 2, itab2);

        }


};

#endif /* BUNDLE_H */

