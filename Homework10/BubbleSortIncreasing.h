/*
 *Bubblesortincreasing algorithm within a class

 */

/* 
 * File:   BubbleSortIncreasing.h
 * Author: Tyler Staats
 *
 * Created on February 14, 2018, 10:31 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "IntergerVectorSortableSearchable.h"
#include <vector>
using namespace std;
#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H

class BubbleSortIncreasing {
public:
    void sort(IntegerVectorSortableSearchable* integerVectorSortableSearchable){
        bool sorted = false;
        int n=integerVectorSortableSearchable->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(!integerVectorSortableSearchable->smaller(i-1,i)){
                    
                    integerVectorSortableSearchable->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
        
    }
};

#endif /* BUBBLESORTINCREASING_H */

