//
//  main.cpp
//  virtual_closet
//
//  Created by Megan Parada on 7/21/23.
//
//#include <opencv2/opencv.hpp>
#include <iostream>
#include "User.hpp"
#include "sqlite3.h"

using namespace std;

int main(int argc, const char * argv[]) {
    User s;
     
    sqlite3* db;
    
    int rc = sqlite3_open("mydatabase.db", &db);

        if (rc != SQLITE_OK) {
            std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return 1;
        }
    
    //create names table
    string create_table_query =
            "CREATE TABLE IF NOT EXISTS Names ("
            "Name TEXT PRIMARY KEY);";
    s.execute_query(db, create_table_query);
    
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
    
    s.execute_query(db, create_clothing_table_query);

    string user_name, command;
    cout << "***Welcome to virtual closet!!***\nPlease enter your name, and we will retrieve your closet: ";
    getline(cin, user_name);
    if(s.checkValueExists(db, "Names", "Name", user_name)){
        cout << "Welcome, " << user_name << "!\nWhat can I help you with today?" << endl;
    }
    else{
        cout << "Hmm, I don't seem to recognize you, " << user_name << "\nWould you like to create a virtual closet? ";
        string response;
        getline(cin, response);
        if(response == "NO" || response == "no" || response == "No"){
            cout << "Well, it was nice meeting you, " << user_name << "! Ciao!";
            return 0;
        }
        else if(response == "YES" || response == "yes" || response == "Yes"){
            cout << "Lovely, " << user_name << "!\nI will get that started for you!\n";
            string insert_query = "INSERT INTO Names (Name) VALUES ('" + user_name + "');";
            s.execute_query(db, insert_query);
        }
        }
    
    cout << "You can choose to" << endl;
    cout << "1. add an item to your closet" << endl;
    cout << "2. delete an item from your closet" << endl;
    cout << "3. see all of your items of clothing" << endl;
    cout << "Please type the number of what you would like to do" << endl;
    int num = -1;
    cin >> num;
    
    
    //fix this later
    while(num != 1 && num != 2 && num != 3){
        cout << "Please enter a valid number (1, 2, 3): " << endl;
        cin >> num;
    }
    
    string category;
    if(num == 1){
        
        cout << "What is the name of the item that you would like to insert today?" << endl;
        string clothing_item;
        cin >> clothing_item;
        cout << "What is the brand of this item?" << endl;
        string brand;
        cin >> brand;
        cout << "What is the size of this item?" << endl;
        string size;
        cin >> size;
        cout << "What is the color of this item?" << endl;
        string color;
        cin >> color;
        
        string insert_query = "INSERT INTO ClothingTable (ClothingItem, Brand, Size, Color, Name) "
                                     "VALUES ('" + clothing_item + "', '" + brand + "', '" +
                                     size + "', '" + color + "', '" + user_name + "');";
        
        s.execute_query(db, insert_query);
    }
    else if(num == 2){
        cout << "What category of clothes is the piece that you would like to delete under?" << endl;
        cout << "The categories of clothing you currently have in your closet are: " << endl;
        cin >> category;
    }
    else if(num == 3){
        cout << "What category of clothes would you like to view today?" << endl;
        cout << "The categories of clothing you currently have in your closet are: " << endl;
        cin >> category;
    }
    
    
    
    //cv::Mat image = cv::imread(imagePath, cv::IMREAD_UNCHANGED);

   // if (image.empty()) {
        //std::cout << "Error: Could not open or read the image!" << std::endl;
        //return 1;
    //}

    //cv::imshow("Uploaded Image", image);
   // cv::waitKey(0);
    //cv::destroyAllWindows();
    sqlite3_close(db);
    return 0;
}

