//------------------------------------------------------------------------------------------------------------------
//  Title :         test_doubly_linked_list.cpp
//  Author :        Garrison Shepard
//  Created :       March 24th, 2018
//
//  Description :   This is an implementation of a Doubly Linked List data structure
//                  Tests are run against operations to verify correctness.
//
//  Purpose :       To provide a link based list implementation that is doubly linked for general use 
//                  and study. Of Interest to those preparing for software engineering 
//                  interviews and studying Computer Science. Originally created for CS community 
//                  on college campus for interview preparation, open for public use.
//
//  Usage :         ./test_doubly_linked_list_implementation
//
//  Build with : g++ -g -std=c++11 -Wall -I.   -c test_doubly_linked_list.cpp -o test_doubly_linked_list.o
//               g++ -g -std=c++11 -Wall -o ./test_doubly_linked_list_implementation test_doubly_linked_list.o  
//                                       -I.  -L/usr/lib -L/usr/local/lib -lm    
//               Or for convience use Make all command (make file included)
//
//  Modifications : no modifications since creation date.
//------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include "DoublyLinkedList.h"
#define ERR_MSG std::cerr << "ERORR ->>> File:" << __FILE__ << ", Line--" << __LINE__ << ", "<< __TIMESTAMP__<< std::endl;
#define TEST_FAIL(method_name) std::cerr << method_name << " Test Failed" << std::endl;
#define TEST_SUCCESS(method_name) std::cerr << method_name << " Test Successful" << std::endl;
#define LOG std::cerr << "Line "<< __LINE__  << " was executed"<< std::endl;
//@desc prints line to standard output for 
//      formatting purposes
//@post line displayed in terminal
void Format(){
  std::cout << "---------------------------------------" << std:: endl;
}//end Format
//@desc checks a list for a value
//      used to test remove by value 
//@pre   reponsible for saving lists data before call to 
//       CheckForValue
//@param DoublyLinkedList<T>& list_one, a list to search
//@param int value,vlaue to check for in list
//@return false if not equal. else true
//@post the data in each list has been completely deleted 
bool CheckForValue(DoublyLinkedList<int>& list, int value){

  if(list.IsEmpty()) //no values
    return false;
  
  while(!list.IsEmpty()){
  
    if(list.Front() == value){  //if vlaue found
       list.Erase();
       return true; //value found 
    }
    list.RemoveFront();//advance to next item
  }
  list.Erase(); //clear entire list 
  return false;//value not found 

} //end CheckForValue 

//@desc compares to lists to see if they are equal. 
//      used to test assignment and copy operator
//@pre   reponsible for saving lists data before call to IsEqual
//@param DoublyLinkedList<T>& list_one, a list to compare
//@param DoublyLinkedList<T>& list_two, a list to compare
//@return false if not equal. else true
//@post the data in each list has been completely deleted 
template<class T>
bool IsEqual(DoublyLinkedList<T>& list_one, DoublyLinkedList<T>& list_two){
 
  bool flag = false; //equality error 
  if(list_one.get_size() != list_two.get_size()) //Lists are not equal
    return false;   
 
  if(list_one.IsEmpty() && list_two.IsEmpty()) {//Lists are equal 
    return true;
  }
  
  while(!list_one.IsEmpty() && !list_two.IsEmpty()){
    if(list_one.Front() == list_two.Front()){ //data entries are equal 
      list_one.RemoveFront(); //advance to next item 
      list_two.RemoveFront(); //advance to next item 
    } else {
      flag = false;  //detected error
      return flag;  //not equal
    } //end if
  }//end while
  
  list_one.Erase(); //completely delete List one 
  list_two.Erase(); //completely delete List two 
  return true; //equal 
} //end IsEqual
void TestDoublyLinkedList(){

  Format(); //format standad output
  std::cout << "Test Doubly Linked List" << std::endl;
  Format(); //format standad output
  
  DoublyLinkedList<int> list_a; //test default constructor 
  
  if(!list_a.IsEmpty()){
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("IsEmpty()"); //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("IsEmpty()"); //print test result to standard output (terminal)
  }
  Format(); //format standard output (terminal)
  list_a.AppendToBack(1); //test AppendToBack
  list_a.AppendToBack(9); //test AppendToBack
  list_a.AppendToBack(7); //test AppendToBack
  list_a.AppendToBack(8); //test AppendToBack
  
  if(list_a.get_size() != 4){ //not all items were appended
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("AppendToBack()");  //print test result to standard output (terminal)
  }else{
    TEST_SUCCESS("AppendToBack()"); //print test result to standard output (terminal)
  }  
  Format(); //format standard output(terminal)
  
  DoublyLinkedList<int> list_b; //test default constructor 
  list_b.AppendToFront(11); //test AppendToFront
  list_b.AppendToFront(99); //test AppendToFront
  list_b.AppendToFront(77); //test AppendToFront
  list_b.AppendToFront(88); //test AppendToFront
  list_b.AppendToFront(44); //test AppendToFront
  
  if(list_b.get_size() != 5){ //not all items were appended 
    ERR_MSG;  //print error message to standrd output (terminal)
    TEST_FAIL("AppendToFront()"); //print test result to standard output (terminal)
  }else{
    TEST_SUCCESS("AppendToFront()"); //print test result to standard output (terminal)
  }
  Format(); //format standard output (Terminal)
  
  while(!list_a.IsEmpty()){list_a.RemoveBack();}  //test RemoveBack
  
  if(!list_a.IsEmpty()){
    ERR_MSG;  //print error messgae to standard output (temrinal)
    TEST_FAIL("RemoveBack()");  //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("RemoveBack()"); //print test result to standard output (terminal)
  }
  Format(); //format standard output (terminal)
  
  while(!list_b.IsEmpty()){list_b.RemoveFront();}  //test RemoveFront
  
  if(!list_b.IsEmpty()){
    ERR_MSG;  //print error messgae to standard output (temrinal)
    TEST_FAIL("RemoveFront()");  //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("RemoveFront()"); //print test result to standard output (terminal)
  }
  Format(); //format standard output (terminal)
  
  list_b.AppendToFront(11); //test AppendToFront
  list_b.AppendToFront(99); //test AppendToFront
  list_b.AppendToFront(77); //test AppendToFront
  list_b.AppendToFront(88); //test AppendToFront
  list_b.AppendToFront(44); //test AppendToFront
   
  list_b.Erase(); //Test Erase
  
  if(!list_b.IsEmpty()){
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("Erase()"); //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("Erase()");  //print test result to standard output (terminal)
  }
  Format(); //format standard output(terminal)
  DoublyLinkedList<int> list_c;
  list_c.AppendToFront(111); 
  list_c.AppendToFront(999);
  list_c.AppendToFront(777);
  list_c.AppendToFront(888); 
  list_c.AppendToFront(444); 
  
  list_c.RemoveByValue(777);
  if(CheckForValue(list_c, 777)){ //checks for value destroys list in the process
     ERR_MSG; //print error message to standard output (terminal)
     TEST_FAIL("RemoveByValue()");  //print test result to standard output (terminal)
  } else {
     TEST_SUCCESS("RemoveByValue()"); //print test result to standard output (terminal)
  }
  Format(); //format standad output
  
  list_a.AppendToBack(1); //test AppendToBack
  list_a.AppendToBack(9); //test AppendToBack
  list_a.AppendToBack(7); //test AppendToBack
  list_a.AppendToBack(8); //test AppendToBack
  
  DoublyLinkedList<int> list_d(list_a); //test copy constructor
  
  if(!IsEqual(list_a, list_d)){
    ERR_MSG;  //print error message to standard terminal
    TEST_FAIL("Copy Constructor"); //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("Copy Constructor"); //print test result to standard output (terminal)
  }
  Format(); //format standard output (terminal)
  
  list_d.AppendToBack(1); //fill list
  list_d.AppendToBack(9);
  list_d.AppendToBack(7); 
  list_d.AppendToBack(8); 
  
  DoublyLinkedList<int> list_e = list_d;  //test assignmment operator
  
  if(!IsEqual(list_d, list_e)){
    ERR_MSG;  //print error message to standard terminal
    TEST_FAIL("Assignment Operator"); //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("Assignment Operator"); //print test result to standard output (terminal)
  }
  Format(); //format standard output  (terminal)
  
}//end TestDoublyLinkedList

int main(){
  TestDoublyLinkedList();
  return 0;
}
