//
//  user.hpp
//  virtual_closet
//
//  Created by Megan Parada on 7/21/23.
//

#ifndef user_hpp
#define user_hpp
#include <sqlite3.h>
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#endif /* user_hpp */

class User {
    public:
    string name;
    //maybe add like a favorite icon or something?
    vector<User> all_users;
    
    //checks if a user already exists
    bool user_exists(string n);
    void create_user(string n);
    User(string n);
    User();

    bool checkValueExists(sqlite3* db, const std::string& tableName, const std::string& columnName, const std::string& value);
    
    sqlite3* initialize_database();
    
    int execute_query(sqlite3* db, const std::string& query);
};


