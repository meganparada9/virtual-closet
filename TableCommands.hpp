//
//  user.hpp
//  virtual_closet
//
//  Created by Megan Parada on 7/21/23.
//

#ifndef user_hpp
#define user_hpp
#include <sqlite3.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#endif /* user_hpp */

class TableCommands {
    public:
    sqlite3* database;
    TableCommands();
    
    //requires: db is a pointer to the sqlite dabatase, tablename is the Names table we want to check, column_name is the name column, value is the name of the user
    //modifies: nothing
    //effects: returns true if the user already exists in the Names table
    bool check_value_exists(sqlite3* db, const string& table_name, const string& column_name, const string& value);
    
    //requires: nothing
    //modifies: sqlite database
    //effects: returns a new database if one of the same name doesn't already exist
    sqlite3* initialize_database();
    
    //requires: nothing
    //modifies: nothing
    //effects: opens the desired database
    void open_database();
    
    //requires: db is a pointer to the sqlite database, query is a string that describes what the database should do
    //modifies: db
    //effects: the database will update based on the query
    int execute_query(sqlite3* db, const string& query);
    
    //requires: db is a pointer to the sqlite database, query is a string that tells what to print
    //modifies: nothing
    //effects: prints items in a user's closet
    void print_command(sqlite3* db, const string& query);
};


