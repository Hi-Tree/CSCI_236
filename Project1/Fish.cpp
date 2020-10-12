/* Meri Khurshudyan
   Project 1 Fish.cpp
   Creates a class Fish 
   which inherits certain aspects
   from its base class Animal       
*/

#include "Fish.hpp"

#include <string>

/* *********Accessor/Mutator Definitions****** */ 

Fish::Fish() : Animal(){ 
   venomous_ = false;  //sets the value of fish when the user does not initialize values
}

Fish::Fish(std::string name, bool domestic, bool predator) 
: Animal(name, domestic, predator){
    venomous_ = false;
}

bool Fish::isVenomous() const{
    return venomous_; 
}

void Fish::setVenomous(){
    venomous_ = true;
}
