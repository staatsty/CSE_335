/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSearchableByType.h
 * Author: Tyler Staats
 *
 * Created on February 11, 2018, 12:57 PM
 */

#ifndef PETDATABASESEARCHABLEBYTYPE_H
#define PETDATABASESEARCHABLEBYTYPE_H

#include <string>
#include <iostream>
#include <iomanip>
#include "SearchableVector.h"
#include "PetDatabaseSortableByName.h"
#include "Pet.h"
#include <vector>
using namespace std;
class PetDatabaseSearchableByType: public SearchableVector{
        
protected:
    vector<Pet*> m_PetVector;
    string m_query;  //data values 
public:
        
    
    PetDatabaseSearchableByType(PetDatabaseSortableByType* petVectorSearch){
          m_PetVector = petVectorSearch->getVector();
    }   
        
     unsigned int getSize() const{//function that returns vector size
            return m_PetVector.size();
    }
    
    
    unsigned int compareAt(int i)const{ //virtual function used to compare values in binary
        if(m_PetVector[i]->GetType() == m_query){                      //search class
            return 0;
        }
        if(smaller(m_query,m_PetVector[i]->GetType())){
            return 1;
        }
        else{
            return 2;
        }
    }
    
    
    bool smaller(string i, string j) const{ //virtual function that returns if an
        if(i<j){     
           return true;
        }
       else{
            return false;
       }
    }
    
    void setQuery(string x){ // function that sets current query value
        m_query = x;
    }
    
   
    
    int getMiddle(){ //function that returns middle value of queue
        return m_PetVector.size()/2;
    }
    
    Pet* getPet(int x){
       return m_PetVector[x+1];
    }
};

#endif /* PETDATABASESEARCHABLEBYTYPE_H */

