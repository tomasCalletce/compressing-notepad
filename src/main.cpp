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
    } else {
        cout << "Unknown command" << endl;
    }

    return 0;
}