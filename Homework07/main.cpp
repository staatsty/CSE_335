/*
 * Homework07
 * Template classes and functions
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on February 3, 2018, 3:27 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include<vector>
 #include "queue.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    queue<int> q1;  //creates queue of int
    cout<<"Inserting numbers 1-6"<<endl;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);  //adds 1-6 to the que
    q1.push(6);
    cout<<"Done inserting"<<endl;
    
    while(q1.empty() != true){ //loops through queue popping each
    cout<<"Popping number: "<<q1.pop()<<endl; //element and printing out the value
    }
    
    
    queue<double> q2; //creates a queue of doubles
    cout<<"Inserting numbers 0.1-0.6"<<endl;
    q2.push(0.1);
    q2.push(0.2);
    q2.push(0.3); //inserts the doubles into the queue
    q2.push(0.4);
    q2.push(0.5);
    q2.push(0.6);
    cout<<"Done inserting"<<endl;
    
    while(q2.empty() != true){ //loops through the queue and prints out each element after popping
    cout<<"Popping number: "<<q2.pop()<<endl; 
    }
    
    return 0;
}

