/*
 *Bubble sort template class used to demonstrate template method pattern
 * same as HW 9
 */

/*
 * File:   BubbleSortTemplate.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
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
    virtual bool needSwap( SortableVector* sortableVector,int i , int j) const = 0; //pure virtual to determine if elements need swaping


    void sort(SortableVector* sortableVector){
        bool sorted = false;
        int n=sortableVector->getSize(); //this is the bubble sort algorithm
        while( !sorted ){                //from lecture slides
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

