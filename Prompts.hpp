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
    
    //requires: nothing
    //modifies: nothing
    //effects: prints a welcome message to the user
    void welcome();
    
    //requires: nothing
    //modifies: nothing
    //effects: prints a message to a returning user
    void returning_user();
    
    //requires: nothing
    //modifies: nothing
    //effects: prints a message to a new user
    void new_user();
    
    //requires: nothing
    //modifies: nothing
    //effects: prints out the different functions that a user can choose from
    void functionalities();
    
    //requires: nothing
    //modifies: nothing
    //effects: reminds a user to choose a valid functionality
    void invalid_choice();
    
    //requires: nothing
    //modifies: nothing
    //effects: prints messages and gets input for what a user wishes to insert into their closet
    void insert();
    
    //requires: nothing
    //modifies: nothing
    //effects: prints messages and gets input for what a user wishes to delete from their closet
    void remove();
};
