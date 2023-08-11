//
//  Prompts.cpp
//  virtual_closet
//
//  Created by Megan Parada on 8/4/23.
//

#include "Prompts.hpp"

Prompts::Prompts(){
    user_name = "";
    response = "";
    choice = -1;
    brand = "";
    color = "";
    size = "";
    clothing_item = "";
}

void Prompts::welcome(){
    cout << "***Welcome to virtual closet!!***\nPlease enter your name, and we will retrieve your closet: ";
    getline(cin, user_name);
}

void Prompts::returning_user(){
    cout << "Welcome, " << user_name << "!\nWhat can I help you with today?" << endl;
}

void Prompts::new_user(){
    cout << "Hmm, I don't seem to recognize you, " << user_name << "\nWould you like to create a virtual closet? ";
    getline(cin, response);
    if(response == "NO" || response == "no" || response == "No"){
        cout << "Well, it was nice meeting you, " << user_name << "! Ciao!";
        return;
    }
    else if(response == "YES" || response == "yes" || response == "Yes"){
        response = "y";
        cout << "Lovely, " << user_name << "!\nI will get that started for you!\n";
    }
}

void Prompts::functionalities(){
    cout << "You can choose to" << endl;
    cout << "1. add an item to your closet" << endl;
    cout << "2. delete an item from your closet" << endl;
    cout << "3. see all of your items of clothing" << endl;
    cout << "Please type the number of what you would like to do" << endl;
    
}

void Prompts::invalid_choice(){
    while(choice != 1 && choice != 2 && choice != 3){
        cout << "Please enter a valid number (1, 2, 3): " << endl;
        cin >> choice;
    }
}

void Prompts::insert(){
    cout << "What is the name of the item that you would like to insert today?" << endl;
    cin >> clothing_item;
    cin.ignore();
    cout << "What is the brand of this item?" << endl;
    getline(cin, brand);
    cout << "What is the color of this item?" << endl;
    cin >> color;
    cout << "What is the size of this item?" << endl;;
    cin >> size;
}

void Prompts::remove(){
    cout << "What is the name of the item that you would like to delete today?" << endl;
    getline(cin, clothing_item);
    cout << "What is the brand of this item?" << endl;
    getline(cin, brand);
    cout << "What is the color of this item?" << endl;
    cin >> color;
    cout << "What is the size of this item?" << endl;
    cin >> size;
}


