/* Meri Khurshudyan
   Project 1 Bird.hpp
   Contains class to be used
   by Bird.cpp      
*/


#ifndef __BIRD__H__
#define __BIRD__H__
#include "Animal.hpp"
#include <string>

class Bird : public Animal{
    public:
             Bird();
             Bird(std::string name, bool domestic=false, bool predator=false);
             bool isAirborne() const;
             bool isAquatic() const;
             void setAirborne();
             void setAquatic();
    
    private:
            bool airborne_;
            bool aquatic_;

}; 


#endif  //!__BIRD__H__