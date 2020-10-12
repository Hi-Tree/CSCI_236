#include<iostream>
#include "DoublyLinkedList.hpp"
#include<string>

using namespace std;


int main(){
  DoublyLinkedList<int> cat;
  DoublyLinkedList<int> dog;

 
  dog.insert(4,1);
  dog.insert(4,2);
  dog.insert(4,3);
 
 
  cat.insert(5,1);
  cat.insert(5,2);
  

 

  
  cat.interleave(dog);
  cat.display();
}