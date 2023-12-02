#include "Database.h"

Database::Database(string name) {
    name += ".db";
    const char* dbName = name.c_str();
    auto isMistakes = sqlite3_open(dbName, &db);
    if (isMistakes) {
        cout << "Couldn't open database.\n";
    }
    else {
        cout << "Database opened succsesfully!\n";
    }
}

void Database::close() {
    sqlite3_close(db);
    cout << "Database closed.\n";
}

void Database::checkMistakes(const char* sth) {
    auto exec = sqlite3_exec(db, sth, callback, 0, &errMsg);
    if (exec != SQLITE_OK) {
        cout << "SQL errror code: " << errMsg << "\n";
        errMsg = 0;
    }
    else {
        cout << "All done succsesfully!\n";
    }
}

void Database::addTabel(string tabelName) {
    // tabel creating and naming
    tabelName = "CREATE TABLE " + tabelName + "("\
        "ID INT PRIMARY KEY NOT NULL," \
        "NAME TEXT NOT NULL," \
        "SURNAME TEXT NOT NULL," \
        "PHONE INT NOT NULL );";

    const char* newTabel = tabelName.c_str();

    checkMistakes(newTabel);
}

void Database::addData(string command1, string command2) {
    // values that we want to insert
    string command = "INSERT INTO " + command1 + " (ID,NAME,SURNAME,PHONE) VALUES (" + command2 + " );";
    const char* insetrtingData = command.c_str();
    
    checkMistakes(insetrtingData);

    /*
    "INSERT INTO COMPANY (ID,NAME,SURNAME,PHONE)"
    "VALUES (2, 'Saul', 'Dith', 20133400 );"
    */
}

void Database::select(string command) {
    const char* select = command.c_str();

    auto exec = sqlite3_exec(db, select, callback, 0, &errMsg);
}

void Database::deleteData(string ID, string table) {
    ID = "DELETE FROM" + table + "WHERE ID = " + ID;
    const char* query = ID.c_str();
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);
}

void Database::updateData(string tabelName, string ID, string column, string newData) {
    string temp = "UPDATE " + tabelName + " SET " + column + "=" 
        + newData + " WHERE ID=" + ID;
    const char* update = temp.c_str();

    auto exec = sqlite3_exec(db, update, callback, 0, &errMsg);
}