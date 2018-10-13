/*
 * Main file used to show test cases
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on January 22, 2018, 2:31 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include<vector>
#include <iomanip>   
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
/*
 * 
 */
int main(int argc, char** argv) {
    vector<Shape*> myShapes; //initialize a vector full of shape pointers (heterogenous container)
    Circle* circle1 = new Circle(1,2,"green",5.3);
    Circle* circle2 = new Circle(3,4,"red",10);
    Square* square1 = new Square(1,2,"blue",7);    //initializing Circle and Square pointers to
    Square* square2 = new Square(3,4,"yellow",2.5);// be inserted into the vector
    Square* square3 = new Square(5,6,"orange",2);
    Square* square4 = new Square(7,8,"purple",6);
    
    myShapes.push_back(circle1);
    myShapes.push_back(circle2);
    myShapes.push_back(square1);  //inserting all the shapes into the vector
    myShapes.push_back(square2);
    myShapes.push_back(square3);
    myShapes.push_back(square4);
   
    
    for(int i=0; i<myShapes.size(); ++i){  //this loop goes through the vector and outputs the area of each shape 
                                           //as well as outputting the color. This is done with the compute area function
        cout<<std::fixed<<std::setprecision(2)<<"Area of Shape "<<i+1<<": " <<myShapes[i]->computeArea()<<"  Color of Shape "<<i+1<<": "<<myShapes[i]->color<<endl;
    }                                      //set decimal size to 2 for cleaner output
    return 0;
}

