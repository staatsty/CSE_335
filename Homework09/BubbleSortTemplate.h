/*
 *Bubble sort template class used to demonstrate template method pattern
 */

/* 
 * File:   BubbleSortTemplate.h
 * Author: Tyler Staats
 *
 * Created on February 10, 2018, 10:21 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "SortableVector.h"
#include <vector>
using namespace std;

#ifndef BUBBLESORTTEMPLATE_H
#define BUBBLESORTTEMPLATE_H
class BubbleSortTemplate{
    
public:
    virtual bool needSwap( SortableVector* sortableVector,int i , int j) const = 0;
    
    
    void sort(SortableVector* sortableVector){
        bool sorted = false;          //preforms bubble sort algorithm 
        int n=sortableVector->getSize(); //from lecture slides
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(needSwap(sortableVector,i-1,i)){
                    sortableVector->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
    }
    
    
};


#endif /* BUBBLESORTTEMPLATE_H */

