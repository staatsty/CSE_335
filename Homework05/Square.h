
/* 
 * File:   Square.h
 * Author: Tyler Staats
 *
 * Created on January 24, 2018, 2:50 PM
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>
using namespace std;

/*
 * This class is called Square and is derived from the Shape base class
 * Takes the same variables as shape with the added edgeLength variable
 */
class Square: public Shape{
public:
    float m_EdgeLength;
    Square(int a, int b, string c, float d):Shape(a,b,c),m_EdgeLength(d){// ctor for square
       cout<< "In Square constructor with parameters  "<<endl;
    };
    
    Square(){ //default ctor
        m_EdgeLength = 0 ;
        x = 0;
        y = 0;
        m_Color = "";
        cout<< "In Square constructor without parameters  "<<endl;
    };
    
    Square(const Square& square):Shape(square){ //copy ctor
        if(this!=&square){
        m_EdgeLength = square.getEdgeLength();
        cout<< "In Square copy constructor" <<endl;
        }
        
    else{
        cout<< "In Square copy constructor Self-copying"<<endl;
    }
    }
    
    Square& operator=(const Square& square){ //"=" operator overload
    if(this!=&square){
        Shape::operator = (square);
        m_EdgeLength = square.getEdgeLength();
        cout<< "In Square assignment operator"<<endl;
    }
    else{
        cout<< "In Square assignment operator Self-copying"<<endl;
    }
    return *this;
    }
    
    
    virtual ~Square(){//dtor of square
    cout<< "In Square destructor "<<endl;
    
    }
  
    
    int getEdgeLength()const{
        return m_EdgeLength; //function that returns edgelength
    }
    
    
    float  computeArea()   {return m_EdgeLength * m_EdgeLength;} //squares the edge length to find area
                                                             //uses virtual function from Shape class
    };

#endif /* SQUARE_H */

