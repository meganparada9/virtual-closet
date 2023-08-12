//
//  user.cpp
//  virtual_closet
//
//

#include "TableCommands.hpp"

TableCommands::TableCommands(){
    database = initialize_database();
}

bool TableCommands::check_value_exists(sqlite3 *db, const string &table_name, const string &column_name, const string &value){
    string query = "SELECT COUNT(*) FROM " + tableName + " WHERE " + columnName + " = ?;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    // bind the value to the query
    rc = sqlite3_bind_text(stmt, 1, value.c_str(), -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return false;
    }

    // execute the query
    bool value_exists = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        value_exists = (count > 0);
    }

    sqlite3_finalize(stmt);
    return value_exists;
}

sqlite3* TableCommands::initialize_database(){
    sqlite3* db;
    int rc = sqlite3_open("mydatabase.db", &db);

    if (rc != SQLITE_OK) {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
    }

    return db;
}

int TableCommands::execute_query(sqlite3* db, const string& query) {
    char* errMsg;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    return rc;
}

void TableCommands::print_command(sqlite3* db, const string& query){
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    
    if(rc == SQLITE_OK){
        cout << "Here are your clothing items!" << endl;
        while(sqlite3_step(stmt) == SQLITE_ROW){
            const char* clothing_item = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            const char* brand = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            const char* size = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            const char* color = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            cout << "Clothing Item: " << clothing_item << ", Brand: " << brand << ", Size: " << size << ", Color: " << color << endl;
        }
    }
    sqlite3_finalize(stmt);
}



