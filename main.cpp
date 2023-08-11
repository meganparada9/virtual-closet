//
//  main.cpp
//  virtual_closet
//
//  Created by Megan Parada on 7/21/23.
//
//#include <opencv2/opencv.hpp>
#include <iostream>
#include "TableCommands.hpp"
#include "sqlite3.h"
#include "Prompts.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    //create a user
    TableCommands s;
    
    //creates a prompts object
    Prompts p;
    
    
    //create names table
    string create_table_query =
            "CREATE TABLE IF NOT EXISTS Names ("
            "Name TEXT PRIMARY KEY);";
    s.execute_query(s.database, create_table_query);
    
    //create clothing table
    string create_clothing_table_query =
            "CREATE TABLE IF NOT EXISTS ClothingTable ("
            "ID INTEGER PRIMARY KEY, "
            "ClothingItem TEXT, "
            "Brand TEXT, "
            "Size TEXT, "
            "Color TEXT, "
            "Name TEXT, "
            "FOREIGN KEY (Name) REFERENCES Names(Name));";
    
    s.execute_query(s.database, create_clothing_table_query);

    p.welcome();
    
    if(s.check_value_exists(s.database, "Names", "Name", p.user_name)){
        p.returning_user();
    }
    else{
        p.new_user();
        if(p.response == "y"){
            string insert_query = "INSERT INTO Names (Name) VALUES ('" + p.user_name + "');";
            s.execute_query(s.database, insert_query);
        }
    }
    int choice;
    p.functionalities();
    
    while(cin >> choice){
        p.choice = choice;
        p.invalid_choice();
        
            if(p.choice == 1){
                p.insert();
                string insert_query = "INSERT INTO ClothingTable (ClothingItem, Brand, Size, Color, Name) "
                                             "VALUES ('" + p.clothing_item + "', '" + p.brand + "', '" +
                                             p.size + "', '" + p.color + "', '" + p.user_name + "');";
                
                s.execute_query(s.database, insert_query);
                cout << "You have successfully inserted " << p.clothing_item << " into your closet!";
            }
            else if(p.choice == 2){
                p.remove();
                string delete_query = "DELETE FROM ClothingTable WHERE Name = '" + p.user_name + "' AND ClothingItem = '" + p.clothing_item + "' AND Brand = '" + p.brand + "' AND Size = '" + p.size + "' AND Color = '" + p.color + "';";
                s.execute_query(s.database, delete_query);
                cout << "You have successfully deleted " << p.clothing_item << " from your closet!" << endl;
            }
            else if(p.choice == 3){
                string print_query = "SELECT ClothingItem, Brand, Size, Color FROM ClothingTable WHERE Name = '" + p.user_name + "';";
                s.print_command(s.database, print_query);
            }
        cout << "Is there anything else I can help you with today?" << endl;
        string response;
        cin >> response;
        if(response == "NO" || response == "no" || response == "No" || response == "n" || response == "N"){
            cout << "Thanks for visiting virtual closet! See you next time!" << endl;
            return 0;
        }
        p.functionalities();
    }
    
    
    
    
    
    sqlite3_close(s.database);
    return 0;
}

