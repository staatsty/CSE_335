/*
 * Main file used to show test cases
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on January 24, 2018, 2:50 PM
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
    cout<<"*******************************************************"<<endl;
    {Square square1(1,2,"yellow",4);}
    Square* square2 = new Square();
    cout<<"*******************************************************"<<endl;
    Circle circle1(3,4,"green",6);
    Circle* circle2 = new Circle();
    cout<<"*******************************************************"<<endl;
    delete square2;
    delete circle2;
    
    return 0;
}

