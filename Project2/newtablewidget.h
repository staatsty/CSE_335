/*derived from QTablewidget used to implement table values, used for Distributed Collaboration Pattern
 *
 * File:   newtablewidget.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */
#ifndef NEWTABLEWIDGET_H
#define NEWTABLEWIDGET_H

#include<QTableWidget>
class NewTableWidget: public QTableWidget
{
    Q_OBJECT
public:
    NewTableWidget(QWidget* qw):QTableWidget(qw){};
    void setName(const QString& item){ //sets name member
        item_name=item;
    }

    void setPrice(const double& price){//sets price member
        item_price=price;
    }
    void setTable(const bool& truth){ //sets if table is selected
        table_selected = truth;
    }
    void setCurrentRow(const int& row){//sets row number
        currentRow=row;
    }
    int getCurrentRow()const{//returns row number
        return currentRow;
    }
    bool getTable()const{ //returns table truth value
        return table_selected;
    }

    QString getName()const{//returns name member
        return item_name;
    }
    double getPrice()const{//returns price
        return item_price;
    }



private:
    QString item_name;//memebers to help store needed values for proper database construction
    double item_price;
    bool table_selected;
    int currentRow;

};

#endif // NEWTABLEWIDGET_H
