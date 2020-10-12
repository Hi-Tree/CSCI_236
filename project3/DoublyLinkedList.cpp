/* Meri Khurshudyan 
   double linked list and definitions 
*/

#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
#include <cstddef>
#include <iostream>

using namespace std;

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   DoubleNode<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new DoubleNode<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      DoubleNode<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
}  // end destructor

/* **************************** isEmpty ************************************* */

template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

/* ****************************** getSize *********************************** */
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
	return itemCount;
}  // end getCurrentSize


/* ****************************** Remove ********************************** */
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position){
DoubleNode<ItemType>* nextNodePtr = headPtr;              
DoubleNode<ItemType>* currentPtr = headPtr; 
DoubleNode<ItemType>* CatodePtr = headPtr;
   if(itemCount == 0){
      return false;
   }

   else if(position > itemCount){
      return false;
   }

   else if(itemCount == 1){
      if(position == 1){//one item removes one
      headPtr->setNext(nullptr);
      delete headPtr;
      headPtr = nullptr;
   }
   }

   else if(itemCount>1){
   if(position == 1){//more than 1 item(s) with position 1**************************
      currentPtr = headPtr;
      headPtr = headPtr->getNext(); //points to second position

      currentPtr->setNext(nullptr);//prev is already null 
      delete currentPtr;
      currentPtr = nullptr;
   }

   else if(position == itemCount){//final position*********************************
      while(nextNodePtr->getNext() != nullptr){
         nextNodePtr = nextNodePtr->getNext();//next node now points to last node
      }
      currentPtr = nextNodePtr->getPrev();//one node before final
      currentPtr->setNext(nullptr);//next of before final is now null

      nextNodePtr->setNext(nullptr);//names have been altered 
      nextNodePtr->setPrev(nullptr);
      delete nextNodePtr;
      nextNodePtr = nullptr;
   }

   else if(position > 1){
   for(int k=1; k < position; k++){
      currentPtr = currentPtr->getNext();//current pointer is the one that will be removed 
   }
      nextNodePtr = currentPtr->getPrev();//will point one before node to be deleted
      CatodePtr = currentPtr->getNext();//will point one after node to be deleted 
      nextNodePtr->setNext(CatodePtr);//will set next of prev to next of current
      CatodePtr->setPrev(nextNodePtr);//will set prev of next to prev 

      //node at position is now excluded from the list with a single pointer 
      currentPtr->setNext(nullptr);//names have been altered 
      currentPtr->setPrev(nullptr);
      delete currentPtr;
      currentPtr = nullptr;

   }
   
   }

itemCount --;
return true;   
}

/* ************************************* Insert ******************************************* */
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& anItem, const int& position){
   DoubleNode<ItemType>* nextNodePtr = headPtr;
   DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(anItem, nullptr, nullptr); 
   //creates a node with some item with nextnodeptr and prevnodeptr 

   if(itemCount == 0){ //if there are no items in the bag
      headPtr = newNodePtr; // the new node is the headptr
   }
   else{
      DoubleNode<ItemType>* TempPtr = headPtr;//pointer to first node and on
      if(position == 1){//if the position is 1 while there are more than 1 items in the bag
         headPtr = newNodePtr;//set the headptr to the newnodept
         newNodePtr->setNext(TempPtr);//new node will point to temp
         TempPtr->setPrev(newNodePtr);
         //sets the previous of the second node to the new node
      }

      else if(position == itemCount+1){
         while(nextNodePtr->getNext() != nullptr){
            nextNodePtr = nextNodePtr->getNext();     
         }
       nextNodePtr->setNext(newNodePtr);
       newNodePtr->setPrev(nextNodePtr);
   }
   
   else if(position > 1){
      for(int i = 1; i < position; i++){
         nextNodePtr = nextNodePtr->getNext(); // loops through until it reaches position
      }
      newNodePtr->setNext(nextNodePtr);//new node points to nextnode
      newNodePtr->setPrev(nextNodePtr->getPrev());//new node also pooints to the previous node
      nextNodePtr->getPrev()->setNext(newNodePtr);
      nextNodePtr->setPrev(newNodePtr);//next node points to new node 
      
   }
   }   
   itemCount++;
   return true; 
}

/* **************************** Clear ************************** */

template<class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
   DoubleNode<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      nodeToDeletePtr->setPrev(nullptr);
      delete nodeToDeletePtr; 
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr  
	itemCount = 0;
}  // end clear

/* ********N******** Display ********F****CR* */
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
   if (itemCount == 0)
      return;
   else 
   {
      DoubleNode<ItemType>* it = headPtr;
      int i = 1; 
      while (it != nullptr && i <= itemCount) {
         if (i == itemCount) {
            cout << it->getItem() << endl;
            return;
         }
         else { 
            cout << it->getItem() << " ";
            it = it->getNext();
            i++;
         }
      }

   //  DoubleNode<ItemType>* it = headPtr;
   //  while(it != nullptr)
   //  { 
   //      if () 
   //      cout << it->getItem() << " ";
   //      it = it->getNext();
   //  }

   }
   
//gitem vor kkartas 
}

/* ********************* Display Backwards *********************** */
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
   
   if (itemCount == 0)
      return;
   else  {
   DoubleNode<ItemType>* it = getAtPos(itemCount);
    while(it != nullptr){
       if (it == headPtr) {
          cout << it->getItem() << endl;
       }
       else { 
         cout << it->getItem() << " ";
       }
       it = it->getPrev();
    }
   }
}

/* ****************************** getHeadPtr() ***************************** */
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const{
   
   return headPtr;
}

/* ******************************** getAtPose ****************************** */
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const{
   DoubleNode<ItemType>* nextNodePtr = headPtr;
   if(itemCount == 0){
      return nullptr;
   }
   else{
   for(int i=1; i < pos; i++){
      nextNodePtr = nextNodePtr->getNext();
   }
   return nextNodePtr;
}
}

/* ********************************** interleave ************************************* */
template <typename ItemType>
DoublyLinkedList<ItemType>& DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list) {
   DoubleNode<ItemType>* nextNodePtr1 = headPtr;//odd positions
   DoubleNode<ItemType>* nextNodePtr2 = a_list.getHeadPtr();//even positions
   // DoublyLinkedList<ItemType>* result = new DoublyLinkedList();
      if(getSize() > a_list.getSize()){   
         for(int i = 1; i < a_list.getSize()+1; i++){
            if((i+1)%2 == 0){
              insert(nextNodePtr2->getItem(), i+1);
              nextNodePtr2 = nextNodePtr2->getNext();
            }
           // if(i%2 == 1){
             // nextNodePtr1=nextNodePtr1->getNext();
            //}
         
         }//exits when next = null
      }

      if(a_list.getSize() >= getSize()){
         
         for(int i = 1; i < itemCount+1; i++){
            if(i%2 == 0){
              insert(nextNodePtr2->getItem(), i);
              nextNodePtr2 = nextNodePtr2->getNext();
            }
            if(i%2){
              nextNodePtr1=nextNodePtr1->getNext();
            }
         
         }//exits when next = null
         while(nextNodePtr2 != nullptr){ 
         insert(nextNodePtr2->getItem(), itemCount+1); 
         nextNodePtr2 = nextNodePtr2->getNext();
       
      }    
      }
      return *this;       
}
