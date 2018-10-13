/*
 sortable integer vector class
 */

/* 
 * File:   IntegerVectorSortable.h
 * Author: Tyler Staats
 *
 * Created on February 13, 2018, 10:39 AM
 */

#ifndef INTEGERVECTORSORTABLE_H
#define INTEGERVECTORSORTABLE_H

#include <string>
#include <iostream>
#include <iomanip>
#include "SearchableVector.h"
#include "SortableVector.h"
#include <vector>
using namespace std;
class IntegerVectorSortable: public SortableVector{ //inherits from sortable vector class
        
protected:
    vector<int> m_IntegerVector;
    int m_query;  //data values 
public:
        
    IntegerVectorSearchable(){//ctor 
        vector<int> m_IntegerVector;
        int query = 0;
    }
    
    IntegerVectorSearchable(vector<int>& intergerVectorSearch){
          m_IntegerVector = intergerVectorSearch;
    }   
        
     unsigned int getSize() const{//function that returns vector size
            return m_IntegerVector.size();
    }
    
    insertInteger(int i){//function that inserts a int into the vector
        m_IntegerVector.push_back(i);
    }
    
     void print() const{ //function that prints out the vector
      for(int i=0;i<getSize();i++){
         cout<<m_IntegerVector[i]<<"; "<<endl;
    
      }  
     }
    
    
     bool smaller(int i, int j) const{ //virtual function that returns if an
        if(getInteger(i)<getInteger(j)){     //value is less then the other value
            return true;
        }
        else{
            return false;
        }
    }
    
    int getInteger(int i) const{ // function that returns a integer from queue at given element
        return m_IntegerVector[i];
    }
    
    void setQuery(int x){ // function that sets current query value
        m_query = x;
    }
    
    void swap(int i, int j){ //virtual function that swaps values
        int temp = m_IntegerVector[i];
        m_IntegerVector[i]=m_IntegerVector[j];
        m_IntegerVector[j]=temp;
    }
    
    
    
};

#endif /* INTEGERVECTORSORTABLE_H */

