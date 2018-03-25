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
#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_
template<class T>
class DoublyLinkedList {

  public:
    //@desc default constructor, initializes default
    //      values for members
    //@post private members have known default values,
    //      rids class of possible garbage values
    DoublyLinkedList();
    //@desc   copy constructor, argument list data is 
    //        copied to 'this' list 
    //@param  const DoublyLinkedList<T>& list, a list to copy
    //@post   'this' list has identical data entries to 
    //        argument list
    DoublyLinkedList(const DoublyLinkedList<T>& list);
    //@desc   assignment operator, assigns argument list to 
    //        'this' list
    //@param  const DoublyLinkedList<T>& rhs, list to be assigned
    //@post   argument list data is copied to 'this' list
    //        hence argument list has been assigned to 'this' list
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);
    //@desc destructor, removes all data entries from list and 
    //      destroys it 
    //@post automatically called by class.Once called 
    //      the data is deleted and instance of the 
    //      class is destroyed
    ~DoublyLinkedList();
    
    //---------------------------
    // non-mutable public methods
    //---------------------------
    
    //@desc     checks to see if list contains data 
    //@mutable  method non-muatable, cannot mutate list
    //@return   if list contians data false, else true
    bool IsEmpty() const;
    
    //@desc     gets size of list 
    //@mutable  method non-mutable, cannot mutate list
    //@return   size_t, number of items in list
    size_t get_size() const;
    
    //@desc     retrieves first item in the list 
    //@pre      size_ > 0, do not call on empty list 
    //          undefined behavior.
    //@mutable  mehtod non-mutable, cannot mutate list
    //return    T,first item in the list, if list empty, 
    //          result is undefined
    T Front() const;
    
    //@desc     retrieves last item in the list
    //@pre      size_ > 0, do not call on empty list
    //          undefined behavior
    //@mutable  method non-mutable, cannot mutate list
    //@return   T, last item in the list, if list of empty,
    //          result is undefined 
    T Back() const;
    
    //---------------------------
    // mutable public methods
    //---------------------------
    
    //@desc     adds data entry to front of list
    //@param    const T& data, where T is a template type,
    //          and data holds the value to appended to
    //          the front of the list
    //@muatable method mutable, can mutate List
    //@post     the new data entry has been appended 
    //          to the front of the list
    void AppendToFront(const T& data);
    
    //@desc     adds data entry to back of list
    //@param    const T& data, where T is a template 
    //          type and data holds the value to 
    //          be appended to the list
    //@mutable  method mutable, can mutate list 
    //@post     the new data entry has been appended 
    //          to the back of the list
    void AppendToBack(const T& data);
    
    //@desc     removes a data entry from the front of the list
    //@pre      method has no effect on an empty List 
    //@mutable  method mutable, can mutate list
    //@post     first data entry in the list have been removed
    bool RemoveFront();
    
    //@desc     removes a data entry from the back of the list
    //@pre      method has no effect on an empty list
    //@mutable  method mutable, can mutate list
    //@post     last data entry in list is removed
    bool RemoveBack();
    
    //@desc     removes specified data entry from list
    //@param    const T& data, where T is a template type,
    //          and data is the value to be removed from 
    //          the list 
    //@mutable  method is mutable, can mutate list
    //@post     specified value is removed from list 
    bool RemoveByValue(const T& data);
    
    //@desc     deletes each data entry in the list 
    //@pre      method has no effect on an empty List
    //@mutable  method mutable,can mutate List
    //@post     list contains no data entries 
    void Erase();
    
  
    
  private:
    struct Node { 
      Node():next(nullptr),prev(nullptr){}
      Node(const T& d, Node* n, Node* p):data(d),next(n),prev(p){}
      
      T data; //value 
      Node* next; //upcoming node
      Node* prev; //preceeding node
    };
    
    DoublyLinkedList::Node* head_;  //front of list
    DoublyLinkedList::Node* tail_;  //back of list
    int size_;  //number of entries in List 
    
    //---------------------------
    // mutable private methods
    //---------------------------
    
    //@desc     deep copy on contents of list 
    //@param    const DoublyLinkedList<T>& list, 
    //          list that will be copied
    //@mutable  method mutable, can mutate list
    //@post     'this' list contains same data entries
    //          as argument list 
    void Copy(const DoublyLinkedList<T>& list); 
};
#include "DoublyLinkedList.cpp"
#endif 
