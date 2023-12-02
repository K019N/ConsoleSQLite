#include <iostream>
#include <string>
#include "Database.h"

using namespace std;

int main(int argc, char* argv[]) {
    int operation = 1;
    string input;
    
    // opening/creating data base
    cout << "Type database name you want to open or create: ";
    cin >> input;
    cout << "\n";
    Database db(input);

    // waiting for commands
    while (operation) {
        cout << "Choose what you want to do:\n" << "1 - create new table\n"
            << "2 - add data to table\n" << "3 - remove data from table\n"
            << "4 - make a request\n" << "5 - update data in tabel\n" 
            << "0 - close database\n";
        cin >> operation;

        if (operation == 1) { // create new table
            cout << "Input tabel name: ";
            cin >> input;
            db.addTabel(input);
        }
        else if (operation == 2) { // add data
            cout << "Input tabel name: ";
            getline(cin, input);
            getline(cin, input);  // ??!?!!!!???!!?!!!!??!!!!!!!?????
            string secondInput;
            cout << "Input ID,NAME,SURNAME,PHONE dividig by ,"
                << " and use ' ' for input strings : ";
            getline(cin, secondInput);
            db.addData(input, secondInput);
        }
        else if (operation == 3) {  //remove data
            string table;
            cout << "Input table name:\n";
            cin >> table;
            cout << "Input ID you want to delete:\n";
            cin >> input;
            db.deleteData(input, table);
        }
        else if (operation == 4) {  //make request
            cout << "Input your request: ";
            getline(cin, input);
            getline(cin, input);  // ??!?!!!!???!!?!!!!??!!!!!!!?????
            db.select(input);
        }
        else if (operation == 5) {  // update row
            string ID, column, newData;
            cout << "Input table name: ";
            cin >> input;
            cout << "Input person's ID: ";
            cin >> ID;
            cout << "Input column name what you want to change: ";
            cin >> column;
            cout << "Input new data: ";
            cin >> newData;

            db.updateData(input, ID, column, newData);
        }
        else if (operation == 0) {
            break;
        }
    }

    db.close();
    return 0;
}

