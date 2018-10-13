/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Salman
 *
 * Created on January 26, 2018, 1:06 PM
 */

#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Bird.h"
#include "PetDatabaseSortableByName.h"
#include "PetDatabaseSortableByWeight.h"
#include "PetDatabaseSortableByPrice.h"
#include "PetDatabaseSortableByType.h"
#include "BubbleSortDecreasing.h"
#include "BubbleSortIncreasing.h"
#include "PetDatabaseSearchableByName.h"
#include "PetDatabaseSearchableByPrice.h"
#include "PetDatabaseSearchableByType.h"
#include "PetDatabaseSearchableByWeight.h"
#include "BinarySearch.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Test sorting pets
    Bird Archie1("Archie1","Parrot",99.99,5, true); 
    Bird Archie2("Archie2","Owl", 70, 6 , false); 
    Bird Archie3("Archie3","Penguin", 49.99,9 , true);  
    
    vector<Pet*> birdPets;
    birdPets.push_back(&Archie1);  
    birdPets.push_back(&Archie2); 
    birdPets.push_back(&Archie3);
    
    Dog Maggie1("Maggie1","Labrador",1000 ,70, "Hound"); 
    Dog Maggie2("Maggie2","Beagle", 499.99, 50 , "Sport"); 
    Dog Maggie3("Maggie3","Bulldog",799.99 ,60, "Companion");
    
    vector<Pet*> dogPets;
    dogPets.push_back(&Maggie1);  
    dogPets.push_back(&Maggie2); 
    dogPets.push_back(&Maggie3); 
    
    Fish Casper1("Casper1","Cod", 10.99 ,1, "Saltwater"); 
    Fish Casper2("Casper2","Catfish",9.99, 2, "FreshWater"); 
    Fish Casper3("Casper3","Herring",12 , 1 , "AnyWater");
    
    vector<Pet*> fishPets;
    fishPets.push_back(&Casper1);  
    fishPets.push_back(&Casper2); 
    fishPets.push_back(&Casper3);
    
    Cat Smokey1("Smokey1","Siamese", 200, 30 , false); 
    Cat Smokey2("Smokey2","Persian", 299.99,45, true); 
    Cat Smokey3("Smokey3","British", 250.50,28 , true);
   
    vector<Pet*> catPets;
    catPets.push_back(&Smokey1);  
    catPets.push_back(&Smokey2); 
    catPets.push_back(&Smokey3);
    
    vector<Pet*> allPets;
    allPets.insert(allPets.end(), birdPets.begin(), birdPets.end());
    allPets.insert(allPets.end(), dogPets.begin(), dogPets.end());
    allPets.insert(allPets.end(), fishPets.begin(), fishPets.end());
    allPets.insert(allPets.end(), catPets.begin(), catPets.end());
    
    BubbleSortIncreasing bs;
    BubbleSortDecreasing bsd;
    cout<<"*********************** Before Sorting"<<endl;
    PetDatabaseSortableByName petDatabaseSortableByName(allPets);
    petDatabaseSortableByName.DisplayRecords();
    bs.sort(&petDatabaseSortableByName);
    cout<<"*********************** After Sorting By Name Descending"<<endl;
    petDatabaseSortableByName.DisplayRecords();
    
    bsd.sort(&petDatabaseSortableByName);
    cout<<"*********************** After Sorting By Name Ascending"<<endl;
    petDatabaseSortableByName.DisplayRecords();
    
    PetDatabaseSortableByType petDatabaseSortableByType(allPets);
    bs.sort(&petDatabaseSortableByType);
    cout<<"*********************** After Sorting By Type Descending"<<endl;
    petDatabaseSortableByType.DisplayRecords();
    
    bsd.sort(&petDatabaseSortableByType);
    cout<<"*********************** After Sorting By Type Ascending"<<endl;
    petDatabaseSortableByType.DisplayRecords();
    
    cout<<"*********************** After Sorting By Price Descending"<<endl;
    PetDatabaseSortableByPrice petDatabaseSortableByPrice(allPets);
    bs.sort(&petDatabaseSortableByPrice);
    petDatabaseSortableByPrice.DisplayRecords();
    
    cout<<"*********************** After Sorting By Price Ascending"<<endl;
    bsd.sort(&petDatabaseSortableByPrice);
    petDatabaseSortableByPrice.DisplayRecords();
    
    cout<<"*********************** After Sorting By Weight Descending"<<endl;
    PetDatabaseSortableByWeight petDatabaseSortableByWeight(allPets);
    bs.sort(&petDatabaseSortableByWeight);
    petDatabaseSortableByWeight.DisplayRecords();
    
    cout<<"*********************** After Sorting By Weight Ascending"<<endl;
    bsd.sort(&petDatabaseSortableByWeight);
    petDatabaseSortableByWeight.DisplayRecords();
    
    BinarySearch s;
    
    cout<<"*********************** Searching for Name Casper3 ..."<<endl;
    PetDatabaseSearchableByName SName(&petDatabaseSortableByName);
    SName.setQuery("Casper3");
    SName.getPet(s.search(&SName))->print();
    
    cout << "*********************** Searching for Type Penguin ..."<<endl;
    PetDatabaseSearchableByType SType(&petDatabaseSortableByType);
    SType.setQuery("Penguin");
    SType.getPet(s.search(&SType))->print();
    
    cout << "*********************** Searching by Price $99.99 ..."<<endl;
    PetDatabaseSearchableByPrice SPrice(&petDatabaseSortableByPrice);
    SPrice.setQuery(99.99);
    SPrice.getPet(s.search(&SPrice))->print();
    
    cout << "*********************** Searching by Weight 2 lbs..."<<endl;
    PetDatabaseSearchableByWeight SWeight(&petDatabaseSortableByWeight);
    SWeight.setQuery(2);
    SWeight.getPet(s.search(&SWeight))->print();
    
    cout << "*********************** Searching for Name Charlie ..."<<endl;
    SName.setQuery("Charlie");
    if (s.search(&SName) == -1) cout << "Charlie not found." << endl;
    else cout << " Search failed." << endl;
    
    
    return 0;
}

