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
template<class T>
DoublyLinkedList<T>::DoublyLinkedList():head_(nullptr), tail_(nullptr), size_(0){}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list){
  head_ = nullptr;  //intializes head
  tail_ = nullptr;  //intializes tail
  size_ = 0; //intializes size 
  Erase();  //clear possible contents
  Copy(list); //copies list 
} //end copy constructor
template<class T> 
DoublyLinkedList<T>&::DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs){
  if(this != &rhs){
    head_ = nullptr;  //intializes head
    tail_ = nullptr;  //intializes tail
    size_ = 0;  //intializes size 
    Erase();  //clear possible contents
    Copy(rhs);  //copies list 
  }
  return *this; 
} //end assignment operator
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){Erase();}

//---------------------------
// non-mutable public methods
//---------------------------

template<class T>
size_t DoublyLinkedList<T>::get_size() const{
  return size_; //size of list
}//end get_size
template<class T>
bool DoublyLinkedList<T>::IsEmpty() const{
  if(size_ != 0)  //no items in list
    return false;

  return true;
}//end IsEmpty
template<class T>
T DoublyLinkedList<T>::Front() const{return head_->data;} //end Front
template<class T>
T DoublyLinkedList<T>::Back() const{return tail_->data;}  //end Back

template<class T>
void DoublyLinkedList<T>::AppendToFront(const T& data){
  Node* append = new Node(data, nullptr, nullptr); //create and fill node
 
  if(IsEmpty()){ //no nodes exist
    tail_ = append; //is tail
    head_ = append; //is head
  } else { //a node exists 
    append->next= head_;  //attach to front
    head_->prev= append;  //attach additional link
    head_ = append; //adjust head
  }
  size_++;
}//end AppendToFront

//---------------------------
// mutable public methods
//---------------------------

template<class T>
void DoublyLinkedList<T>::AppendToBack(const T& data){
  Node* append = new Node(data, nullptr, nullptr);
  if(IsEmpty()){ //no node exists 
    head_ = append; //only node
    tail_ = append; //only node
  } else {
    append->prev = tail_; //attach to back
    tail_->next = append; //attach additional link
    tail_ = append; //adjust tail
  }
  size_++;
} //end AppendToBack

template<class T> 
bool DoublyLinkedList<T>::RemoveFront(){
  
  if(IsEmpty()) //no nodes exist
    return false; //no nodes removed
    
  Node* del_node = head_; //node to delete
  if(head_->next == nullptr){ //head_ == tail_ only node left 
    head_ = nullptr;  //no nodes in list 
    tail_ = nullptr;  //no nodes in list 
  } else {  
    head_->next->prev = nullptr;  //prep new head node
    head_ = head_->next;  //set new head node
  }
  
  delete del_node;  //delete original head 
  size_--;  //decrement size
  
  return true;  //successful removal
}//end RemoveFront
 
template<class T> 
bool DoublyLinkedList<T>::RemoveBack(){
 
  if(IsEmpty()) //no nodes exist 
    return false;
    
  Node* del_node = tail_; //node to delete
  if(tail_->prev == nullptr) { //head_ == tail_ only node left 
    head_ = nullptr;  //no nodes in list
    tail_ = nullptr;  //no nodes in list
  } else {
    tail_->prev->next = nullptr;  //prep new tail node
    tail_ = tail_->prev;  //set new tail node
  }
  
  delete del_node;  //delete original tail
  size_--;  //decrement size 
  
  return true;  //successful removal
}//end RemoveBack

template<class T>
bool DoublyLinkedList<T>::RemoveByValue(const T& data){

  Node* del_node;
  if(head_->data == data) { //head 
  
    del_node = head_; //node to delete
    head_->next->prev = nullptr;  //prep new head
    head_ = head_->next;  //set new head
  } else if(tail_->data == data) {  //tail
  
    del_node = tail_; //node to delete
    tail_->prev->next = nullptr; //prep new tail
    tail_ = tail_->prev;  //set new tail
  } else { //center
  
    Node* traverse = head_; 
    while(traverse != nullptr){ 
      if(traverse->next->data == data){ //if value found 
        del_node = traverse->next; //node to remove
        break;
      } 
      traverse = traverse->next;  //advance
    }//end while 

    traverse->next = del_node->next; //attach and skip node to delete
    del_node->next->prev = traverse; //attach addtional link and skip node to delete
  }//end else

  if(del_node->data == data){ //correct value removed
    delete del_node;  //delete node
    size_--; //decrement size
    return true; //successful removal
  } else {
    return false; //unsuccessful removal
  }
}//end RemovByValue

template<class T>
void DoublyLinkedList<T>::Erase(){
  while(!IsEmpty()){
    RemoveBack(); //delete from back of list
  }//end while
}//end Erase

//---------------------------
// non-mutable private methods
//---------------------------

template<class T>
void DoublyLinkedList<T>::Copy(const DoublyLinkedList<T>& list){

  if(list.IsEmpty()){
    head_ = nullptr; //no nodes in list
    tail_ = nullptr; //no nodes in list
    return;  
  }
  
  Node* traverse = list.head_; 
  while(traverse != nullptr){
    AppendToBack(traverse->data); //copy data to 'this' list 
    traverse = traverse->next;  
  }//end while
} //end Copy
