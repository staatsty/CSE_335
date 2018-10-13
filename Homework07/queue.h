/*
 Queue class to demonstrate a template class
 */

/* 
 * File:   queue.h
 * Author: Tyler Staats
 *
 * Created on February 3, 2018, 3:27 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>
#include <iomanip>
 
using namespace std;

template <class QueueType>class queue{ //template class called queue
    public:
        vector<QueueType> v1; //creates vector of given type
        
        
        void push(QueueType element){ //function that push back given element into vector
            v1.push_back(element);
        }
        
        QueueType top(){ //returns first value in queue
            return v1.at(0);
        }
        
        QueueType pop(){
            QueueType x = v1.at(0); //returns and removes first value in queue
            v1.erase(v1.begin());//use .erase to erase the beginning of vector
            return x;
        }
        
        bool empty(){ //function that returns true
            if (v1.size()==0){//if queue is empty
            return true; 
            }
            else{   //returns false if not empty
                return false;
            }
        }
        
        
};






#endif /* QUEUE_H */

