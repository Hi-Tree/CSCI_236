#include<iostream>
#include <string>
#include "Mammal.hpp"
using namespace std;

int main(){
    Mammal  cat("cat",1,1);
    cout << cat.getName()<<endl;
    return 0;
}