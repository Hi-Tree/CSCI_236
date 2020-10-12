//Meri Khurshudyan
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "DoubleNode.hpp"

template<class ItemType>
class DoublyLinkedList
{
private:
   DoubleNode<ItemType>* headPtr; // Pointer to first Doublenode
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the Doublenode containing a given entry
   // or the null pointer if the entry is not in the bag.
   DoubleNode<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   DoublyLinkedList();
   DoublyLinkedList(ItemType anItem, int *Pointer);
   DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag); // Copy constructor
   virtual ~DoublyLinkedList();                       // Destructor should be virtual
   int getSize() const;
   bool isEmpty() const;
   void clear();
   void display() const;
   void displayBackwards() const;
   bool insert(const ItemType& anItem, const int& position);
   bool remove(const int& position);
   DoubleNode<ItemType> *getHeadPtr() const;
   DoubleNode<ItemType> *getAtPos(const int& pos) const;
   DoublyLinkedList<ItemType>& interleave(const DoublyLinkedList<ItemType>& a_list);
}; // end DoublyLinkedList

#include "DoublyLinkedList.cpp"
#endif