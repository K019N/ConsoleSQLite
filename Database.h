#pragma once
#include "SQLite/sqlite3.h"
#include <string>
#include <iostream>

using namespace std;

class Database {
private:
	sqlite3* db;
	sqlite3_stmt* stmt;
	char* errMsg = 0;

	static int callback(void* data, int argc, char** argv, char** azColName) {
		for (int i = 0; i < argc; i++) {
			std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
		}
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	void checkMistakes(const char* sth);
public:
	Database(string name);
	void close();
	void addTabel(string tabelName);
	void addData(string commandLine1, string commandLine2);
	void select(string command);
	void deleteData(string ID, string table);
	void updateData(string TabelName, string ID, string column, string newData);
};
