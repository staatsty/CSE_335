/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortIncreasing.h
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
#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H

class BubbleSortIncreasing : public BubbleSortTemplate{
public:
    bool needSwap(SortableVector* sortableVector,int i, int j) const{
        return sortableVector -> smaller(i,j);
    }
};

#endif /* BUBBLESORTINCREASING_H */

