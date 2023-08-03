//
//  user.cpp
//  virtual_closet
//
//  Created by Megan Parada on 7/21/23.
//

#include "user.hpp"


bool User::user_exists(string n){
    for(int i = 0; i < all_users.size(); i++){
        if(n == all_users[i].name){
            return true;
        }
    }
    return false;
}

User::User(string n){
    name = n;
}

User::User(){
    name = "";
}

void User::create_user(string n){
    User new_user = User(n);
    all_users.push_back(new_user);
}

bool User::checkValueExists(sqlite3 *db, const std::string &tableName, const std::string &columnName, const std::string &value){
    
    std::string query = "SELECT COUNT(*) FROM " + tableName + " WHERE " + columnName + " = ?;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    // Bind the value to the query
    rc = sqlite3_bind_text(stmt, 1, value.c_str(), -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return false;
    }

    // Execute the query
    bool valueExists = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        valueExists = (count > 0);
    }

    sqlite3_finalize(stmt);
    return valueExists;
}

sqlite3* User::initialize_database(){
    sqlite3* db;
        int rc = sqlite3_open("mydatabase.db", &db);

        if (rc != SQLITE_OK) {
            std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return nullptr;
        }

        return db;
}

int User::execute_query(sqlite3* db, const string& query) {
    char* errMsg;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return rc;
}



