/* Meri Khurshudyan
   Project 1 Bird.cpp
   Creates a class Bird 
   which inherits certain aspects
   from its base class Animal       
*/

#include "Animal.hpp"
#include "Bird.hpp"
#include <string>
 using namespace std;

 Bird::Bird():Animal(){
     airborne_ = false;
     aquatic_ = false;
 }

 Bird::Bird(std::string name, bool domestic, bool predator) 
 : Animal(name, domestic, predator){
     airborne_ = false;
     aquatic_ = false;
 }


/* ***** Accessor/Mutator Definitions ****** */ 

bool Bird::isAirborne() const{
    return airborne_; 
}
bool Bird::isAquatic() const{
    return aquatic_; 
}
void Bird::setAirborne(){
    airborne_ = true; 
}
void Bird::setAquatic(){
    aquatic_ = true;
}