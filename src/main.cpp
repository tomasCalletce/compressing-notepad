#include <iostream>
#include <string>

using namespace std;

void print(const char* note){
    cout << "Note saved: " << note << endl; 
}

void compress(const char* note){
    cout << "Compressing note..." << endl; 
}

void write(const string& note){
    const int size = note.size() + 1; 
    char* noteArray = new char[size];  

    strcpy(noteArray, note.c_str());  

    compress(noteArray);
    print(noteArray);  
}



int main() {
    string input;
    cout << "Enter command: ";
    getline(cin, input);

    if (input == "write") {
        cout << "Start typing and press enter to save compressed note: ";
        string note;
        getline(cin, note);

        write(note);  
    } else if (input == "edit") {
        cout << "Enter the name of the file to edit: ";

        string filename;
        getline(cin, filename);
    } else {
        cout << "Unknown command" << endl;
    }

    return 0;
}