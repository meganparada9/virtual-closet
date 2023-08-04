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
    
    bool check_value_exists(sqlite3* db, const string& tableName, const string& columnName, const string& value);
    
    sqlite3* initialize_database();
    
    void open_database();
    
    int execute_query(sqlite3* db, const std::string& query);
};


