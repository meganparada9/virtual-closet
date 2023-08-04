//
//  Prompts.hpp
//  virtual_closet
//
//  Created by Megan Parada on 8/4/23.
//

#ifndef Prompts_hpp
#define Prompts_hpp

#include <stdio.h>
#include <string>
using namespace std;
#include <iostream>

#endif /* Prompts_hpp */
 

class Prompts {
public:
    Prompts();
    string user_name;
    string response;
    string clothing_item;
    string brand;
    string size;
    string color;
    int choice;
    
    void welcome();
    
    void returning_user();
    
    void new_user();
    
    void functionalities();
    
    void invalid_choice();
    
    void insert();
    
    void remove();
    
    void view();
};
