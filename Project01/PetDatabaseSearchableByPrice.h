/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSearchableByPrice.h
 * Author: Tyler Staats
 *
 * Created on February 11, 2018, 12:57 PM
 */

#ifndef PETDATABASESEARCHABLEBYPRICE_H
#define PETDATABASESEARCHABLEBYPRICE_H


#include <string>
#include <iostream>
#include <iomanip>
#include "SearchableVector.h"
#include "PetDatabaseSortableByName.h"
#include "Pet.h"
#include <vector>
#include <math.h>
using namespace std;
class PetDatabaseSearchableByPrice: public SearchableVector{
        
protected:
    vector<Pet*> m_PetVector;
    float m_query;  //data values 
public:
        
   // PetDatabaseSearchableByName(vector<Pet*> petVector ){//ctor 
   //      m_PetVector = petVector;
     //    int m_query = 0;
    //}
    
    PetDatabaseSearchableByPrice(PetDatabaseSortableByPrice* petVectorSearch){
          m_PetVector = petVectorSearch->getVector();
    }   
        
     unsigned int getSize() const{//function that returns vector size
            return m_PetVector.size();
    }
    
    
    unsigned int compareAt(int i)const{ //virtual function used to compare values in binary
        if(floor(m_PetVector[i]->GetPrice()) == floor(m_query)){  
            return 0;
        }
        if(smaller(m_query,m_PetVector[i]->GetPrice())){
            return 1;
        }
        else{
            return 2;
        }
    }
    
    
    bool smaller(float i, float j) const{ //virtual function that returns if an
        if(i<j){   
           return true;
        }
       else{
            float x = j;
            return false;
       }
    }
    
    void setQuery(float x){ // function that sets current query value
        m_query = x;
    }
    
  
    
    int getMiddle(){ //function that returns middle value of queue
        return m_PetVector.size()/2;
    }
    
    Pet* getPet(int x){
        return m_PetVector[x+1];
    }
};





#endif /* PETDATABASESEARCHABLEBYPRICE_H */

