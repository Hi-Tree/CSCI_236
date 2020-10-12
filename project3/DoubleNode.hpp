//Meri Khurshudyan double nodes
#ifndef NODE_
#define NODE_

template<class ItemType>
class DoubleNode
{
private:
   ItemType        item; // A data item
   DoubleNode<ItemType>* next; // Pointer to next node
   DoubleNode<ItemType>* previous; //Pointer to previous
public:
   DoubleNode();
   DoubleNode(const ItemType& anItem);
   DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(DoubleNode<ItemType>* nextNodePtr);
   void setPrev(DoubleNode<ItemType>* prevNodePtr);
   ItemType getItem() const ;
   DoubleNode<ItemType>* getNext() const ;
   DoubleNode<ItemType>* getPrev() const ;
}; // end Node

#include "DoubleNode.cpp"
#endif