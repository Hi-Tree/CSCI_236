/* Meri Khurshudyan
   Project 1 Animal.cpp
   defines all Animal class objects to 
   be used by derived classes of
   Animal      
*/

#include "Animal.hpp"
#include <string>

Animal::Animal(){
    name_ = "";
    domestic_ = false;
    predator_ = false;
}

Animal::Animal(std::string name, bool domestic, bool predator){
    name_ = name;
    domestic_ = domestic;
    predator_ =  predator;
}

/* *********Accessor/Mutator Definitions****** */ 

std::string Animal::getName() const{
    return name_;
}

void Animal::setName(std::string user_name){
name_ = user_name;
}

bool Animal::isDomestic() const{
   return domestic_;

}

void Animal::setDomestic(){
   domestic_ = true;
}

bool Animal::isPredator() const {
    return predator_;

}

void Animal::setPredator(){
    predator_ = true;
}

