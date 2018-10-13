/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortDecreasing.h
 * Author: Tyler Staats
 *
 * Created on February 12, 2018, 10:31 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "BubbleSortTemplate.h"
#include <vector>
using namespace std;
#ifndef BUBBLESORTDECREASING_H
#define BUBBLESORTDECREASING_H

class BubbleSortDecreasing : public BubbleSortTemplate{
public:
    bool needSwap(SortableVector* sortableVector,int i, int j) const{
        return !sortableVector -> smaller(i,j);
    }
};


#endif /* BUBBLESORTDECREASING_H */

