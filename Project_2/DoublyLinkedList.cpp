//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** 
 * Meri Khurshudyan
 * 
 * ADT bag: Link-based implementation.
    @file LinkedBag.cpp */


#include <cstddef>
#include <iostream>
#include <ctime>
#include "LinkedBag.h"

using namespace std;

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

/* ************* Linked Bag ********OK******* */
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount) : headPtr(nullptr), itemCount(0)
{
   for(int i=0; i<entryCount; i++){
     add(entries[i]);
      
   }
}




template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
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
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

/* *********************** */
template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

/* ************** Get Current Size *********OK****** */
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   Node<ItemType>* nextNodePtr = headPtr;
   if(headPtr==nullptr){
      return 0;
   }
   else{
   int i=0;
	while(nextNodePtr->getNext() != nullptr){
      i++;
      nextNodePtr=nextNodePtr->getNext();
   }
   return i+1;
   }
}  // end getCurrentSize

/* ************** Get Current Size Recursive *******OK******* */
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive(){
   Node<ItemType>* nextNodePtr = headPtr;
   return Helper(nextNodePtr);
}

template<class ItemType>
int LinkedBag<ItemType>::Helper(Node<ItemType>* nextNodePtr){
   
      if(nextNodePtr==nullptr){
         return 0;
      }
      else{
         return Helper(nextNodePtr->getNext())+1;
      }
   }



/* ********* ADD ********OK** */
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, nullptr);
   Node<ItemType>* nextNodePtr = headPtr;

   if(itemCount == 0){
      headPtr = newNodePtr; 
   }

   else if(itemCount == 1)
   {
      headPtr->setNext(newNodePtr);
   }

   else{
      while(nextNodePtr->getNext() != nullptr)
      { 
         nextNodePtr = nextNodePtr->getNext();
      }
         nextNodePtr->setNext(newNodePtr);
   }
   itemCount++;
   return true; 
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector


/* ************* REMOVE SECOND ****OK************ */
template<class ItemType>
void LinkedBag<ItemType>::deleteSecondNode(){
   Node<ItemType>* TempPtr = headPtr->getNext()->getNext();// starts from second
   Node<ItemType>* nextNodePtr = headPtr;
   Node<ItemType>* SecondNode = nextNodePtr->getNext();
   if(itemCount >= 2){

   nextNodePtr->setNext(TempPtr);
      // Return node to the system
      SecondNode->setNext(nullptr);
      delete SecondNode;
      SecondNode = nullptr;
      
      itemCount--;
   } 
}


template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr 
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo



template<class ItemType>
void LinkedBag<ItemType>::display() const
{
   if (itemCount == 0)
      return;
   else 
   {
    Node<ItemType>* it = headPtr;
    while(it != nullptr)
    {
        std::cout << it->getItem() << std::endl;
        it = it->getNext();
    }
   }

}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

/*  ***************** Remove Random ********OK******** */
template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom()
{
   int amount = getCurrentSize();
   int random = rand() % amount;
   Node<ItemType>* nodePtr = headPtr;
   for (int k = 0; k < random; k++)
   {
      nodePtr = nodePtr->getNext();
   }
   ItemType store = nodePtr->getItem();
   remove (nodePtr->getItem());
   return store;
}
    ///



