/*
 * Homework03 create 3 classes to show inhertance
 * classes include Double Queue, Stack and Queue.
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on January 16, 2018, 12:35 PM
 */

#include <cstdlib>
#include <iostream>
#include<vector>
//using std::vector;
using namespace std;

/*
 * Base class is Double Queue class called Dqueue.
 * the class makes use of a vector composed of strings
 * Dqueue can insert data from left or right and delete data from left or right
 */
class Dqueue{
public:
vector<string> queue;
Dqueue(vector<string> a):queue(a){//ctor of Dqueue
        
 }

/*
 * This function allows for data to be inserted to the left in the queue
 */
void insertL(string stringVar){
 if (queue.size()==0){          //this if just adds the string to queue
     queue.push_back(stringVar);//if the queue is empty
 }  
 else{
  vector<string>::iterator it;//else a vector<string> iterator is initialized
  it = queue.begin();         //the iterator is set to the beginning of the vector
  it = queue.insert ( it , stringVar );//then the string is inserted at beginning
     
 }
}

/*
 * This function allows for data to be inserted to the right in the queue
 */
void insertR(string stringVar){
    queue.push_back(stringVar); //makes use of push_back to insert the string
}

/*
 * This function allows for data to be deleted on the left side
 */
void deleteL(){
    queue.erase(queue.begin());//use .erase to erase the beginning of vector
}

/*
 * This function allows for data to be deleted on the right side
 */
void deleteR(){
    queue.erase(queue.end());//use .erase to erase the end of vector
}

/*
 * This function allows for Dqueue values to be printed from left to right
 * Also the value gets deleted after being printed
 */
void printAndDeleteDqueue(){
    int queueSize = queue.size();//variable for current queueSize
      for(int i = 0; i<queueSize; i++){ //loops through queue
        cout<<queue.at(0)<<endl;     //prints first value then deletes
        deleteL();                   //making use of deleteL()
    }
}
};


/*
 * This class is called Stack.
 * the class is privately derived from Dqueue.
 * Stack can insert data from left(top) and delete data from left(top).
 */
class Stack: private Dqueue{
public:
Stack(vector<string> a):Dqueue(a){//ctor for Stack
       
  }

/*
 * This function allows for data to be inserted from the left
 */
void push(string stringVar){
    insertL(stringVar); //makes use of insertL() from base class
   }

/*
 * This function allows for data to be deleted on the left side
 */
void pop(){
    deleteL();   //uses deleteL from base class
}


/*
 * This function allows for the top value to be returned
 */
string top(){
    return queue.at(0); //returns the first element in queue
}

/*
 * This function allows for stack values to be printed from left to right
 * Also the value gets deleted after being printed
 */
void printAndDeleteStack(){
    printAndDeleteDqueue(); //makes use of printAndDeleteDqueue from base
    }

};


/*
 * This class is called Queue.
 * the class is publicly derived from Dqueue.
 * Queue can insert data from left and delete data from right.
 */
class Queue: public Dqueue{
public:
    int max = 10; //max capacity of queue
Queue(vector<string> a):Dqueue(a){ //ctor for Queue
       
   }

/*
 * This member function allows for data to be inserted from the left
 */
void push(string stringVar){
    if (full()){ //checks if queue is full doubles the max if full
        max*2;
        cout<<"Size increased to: "<<max<<endl;
        insertL(stringVar); //then adds next element to the left.
    }
    else{
        insertL(stringVar); //else just insert the element to the left
    }
    
   }
/*
 * This member function allows for data to be removed from the right
 */
void pop(){
    deleteR(); //makes use of deleteR from base
}

/*
 * This member function checks if queue is full or not
 */
bool full(){
    if (queue.size()== max){  //returns true if queue is full
        return true;
    }
    else{
        return false;   //else returns false
    }
}

/*
 * This function allows for Queue values to be printed from right to left
 * Also the value gets deleted after being printed
 */
void printAndDeleteQueue(){
    int queueSize = queue.size();  //variable for queue size
    int indexval = queueSize - 1; //index need to be one less then 
      for(int i = 0; i<queueSize; i++){  //loops through the queue and prints out last
        cout<<queue.at(indexval)<<endl;  //element in the queue
        indexval--;
        pop();   //removes last element after printing
      }
    }
};


int main(int argc, char** argv) {
    vector<string> v;       //initial vector 
    
    
    Dqueue dqueue1(v);     //create Dqueue object called dqueue1
    dqueue1.insertL("string1"); //insert all strings according to wanted test case
    dqueue1.insertL("string2"); //first 5 insert from the left of the queue
    dqueue1.insertL("string3");
    dqueue1.insertL("string4");
    dqueue1.insertL("string5");
    dqueue1.insertR("string6"); //6,7 and 8 insert from the right
    dqueue1.insertR("string7");
    dqueue1.insertR("string8");
    dqueue1.printAndDeleteDqueue(); //this function prints out the queue removes all
                                    //the strings as requested
    
    Stack stack1(v);    //creates Stack object called stack1
    stack1.push("string100");//pushes all values from the left(top)
    stack1.push("string200");
    stack1.push("string300");
    stack1.push("string400");
    stack1.printAndDeleteStack();//this function prints all values from left(top) to right
                                 //the strings are removed after print out
   
    
    Queue queue1(v);     //creates Queue object called queue1
    queue1.push("string10");
    queue1.push("string20"); //inserts the strings from the left of the queue
    queue1.push("string30");
    queue1.push("string40");
    queue1.printAndDeleteQueue(); //prints and deletes the queue from the right to left
    return 0;
}

