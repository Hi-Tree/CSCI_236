/* Meri Khurshudyan
   Project 1 Fish.hpp
   contains the class to be
   used by Fish.cpp     
*/

#ifndef __FISH__H__
#define __FISH__H__
#include "Animal.hpp"
#include<string>

class Fish : public Animal{
    public:
        Fish();
        Fish(std::string name, bool domestic = false, bool predator = false);
        bool isVenomous() const;
        void setVenomous();
    
    private:
        bool venomous_; 
};

#endif  //!__FISH__H__
