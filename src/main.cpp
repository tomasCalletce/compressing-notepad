// #include <iostream>
// #include <string>

#include<bits/stdc++.h>
#define el '\n'
using namespace std;
void print(const char* note){
    cout << "Note saved: " << note << el; 
}

void compress(const char* note){
    cout << "Compressing note..." << el; 
}

void write(const string& note){
    const int size = note.size() + 1; 
    char* noteArray = new char[size];  

    strcpy(noteArray, note.c_str());  

    compress(noteArray);
    print(noteArray);  
}


string toLower(const string &s){
    string resp = s;
    for(char &c : resp)c = tolower(c);
    return resp;
}

int main() {
    string input;
    
    cout << "Enter command: ";
    string commands = "";
    while((getline(cin, input)) && toLower(input)!= "quit" && input!= "exit"){
        if(toLower(input) == "help"){
            cout<<commands<<el;
        }
        else if (input == toLower("write")) {
            cout << "Start typing and press enter to save compressed note: ";
            string note;
            getline(cin, note);

            write(note);  
        } else if (input == toLower("edit")) {
            cout << "Enter the name of the file to edit: ";
            string filename;
            getline(cin, filename);
        } else {
            cout << "Unknown command" << el;
        }   
    }
    return 0;
}