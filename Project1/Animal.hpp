/* Meri Khurshudyan
   Project 1 Animal.hpp
   contains the class to be
   used by Animal.cpp and other
   derived classes       
*/

#ifndef __ANIMAL__H__
#define __ANIMAL__H__
#include <string>

class Animal{
    public:
        Animal();
        Animal(std::string name, bool domestic = false, bool predator = false);
        std::string getName() const;
        bool isDomestic() const; 
        bool isPredator() const;
        void setName(std::string name);
        void setDomestic(); 
        void setPredator();

    private:
        std::string name_;
        bool domestic_; 
        bool predator_;
};
#endif  //!__ANIMAL__H__