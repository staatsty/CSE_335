
/* 
 * File:   Shape.h
 * Author: Tyler Staats
 *
 Created on January 24, 2018, 2:50 PM
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

/*
 * This class called shaped is the base class
 * takes 2 ints for x and y value and a string representing color
 * and open the template in the editor.
 */
class Shape{
public:
   int x;
   int y;
   string m_Color;
Shape(int a , int b, string c):x(a),y(b),m_Color(c){//ctor of Shape class
    cout<< "In Shape constructor with parameters  "<<endl;
 };
Shape(){ //default ctor
    x = 0;
    y = 0;
    m_Color = "";
    cout<< "In Shape constructor without parameters "<<endl;
    
};

Shape(const Shape& shape){ //copy ctor
    if(this!=&shape){
        m_Color = shape.getColor();
        x = shape.getX();
        y = shape.getY();
        cout<< "In Shape copy constructor" <<endl;
    }
    else{
        cout<< "In Shape copy constructor Self-copying"<<endl;
    }
}

Shape& operator=(const Shape& shape){ //"=" operator overload
    if(this!=&shape){
        m_Color = shape.getColor();
        x = shape.getX();
        y = shape.getY();
        cout<< "In Shape assignment operator"<<endl;
    }
    else{
        cout<< "In Shape assignment operator Self-copying"<<endl;
    }
    return *this;
}



virtual ~Shape(){ //dtor of shape
    cout<< "In Shape destructor "<<endl;
    
}



virtual float computeArea()  = 0; //pure virtual function for determining area

void printColor(){
    cout<<m_Color<<endl; //function that prints the color
}

string getColor() const{
    return m_Color; //function that returns color
}

int getX() const{
    return x; //function that returns x
}

int getY() const{
    return y; //function that returns y
}
};


#endif /* SHAPE_H */

