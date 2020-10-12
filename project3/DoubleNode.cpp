//Meri Khurshudyan 
#include "DoubleNode.hpp"
//#include <cstddef>

template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : next(nullptr)
{
} // end default constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr) :
                item(anItem), next(nextNodePtr), previous(prevNodePtr)
{
} // end constructor

template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* prevNodePtr)
{
   previous = prevNodePtr;
}

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
   return item;
} // end getItem

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
   return next;
} // end getNext

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const
{
   return previous;
} // end getNext

