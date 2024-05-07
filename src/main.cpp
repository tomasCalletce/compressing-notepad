// #include <iostream>
// #include <string>

#include<bits/stdc++.h>
#include "LZ77.cpp"
#define el '\n'
using namespace std;
void print(const string note){
    cout << "Note saved: " << note << el; 
}

void compress(const string note){
    cout << "Compressing note..." << el; 
}

void writeFile(const string& s){
    //Meterlo a un file compress
    // runLZ(s, "C",/**input file compress*/, )
}
struct Token{
    int dist, len;
    char c;
    Token(){}
    Token(int dist, int len, char c): dist(dist), len(len), c(c){}
};
// Token t(1,1,'c');
// t.dist | t.len | t.c
//(int, int, char)
string toLower(const string &s){
    string resp = s;
    for(char &c : resp)c = tolower(c);
    return resp;
}


void runLZ(string s, char *modo, char *inputFileName, char *outputFileName){
     if (modo == "C") {
        LZ77 lz77 = LZ77();
        lz77.compress(inputFileName, outputFileName);
    } else if ( modo == "D") {
        LZ77 lz77 = LZ77();
        lz77.decompress(inputFileName, outputFileName);
    } 
}

string readFile(string fileName){
    string file;
    /// si no existe return ""
    // decompress && retornar string
    return file;
}


void fileHandler(string fileName){

    string file = readFile(fileName);
    string input ="";
    while((getline(cin, input)) && toLower(input)!= "quit" && input!= "exit"){
        file += input;
    }
    writeFile(file);
}

int main(int argv, string argc[]) {
    string input;
    
    cout << "Enter command: ";
    string commands = "";
   
    while((getline(cin, input)) && toLower(input)!= "quit" && input!= "exit"){
        if(toLower(input) == "help"){
            cout<<commands<<el;
        }
        else if (input == toLower("write")) {
            cout << "Start typing and press enter to save compressed note: ";
            string fileName;
            getline(cin, fileName);

            fileHandler(fileName);
        } else if (input == toLower("edit")) {
            cout << "Enter the name of the file to edit: ";
            string filename;
            getline(cin, filename);
            fileHandler(filename);

        } else {
            cout << "Unknown command" << el;
        }   
    }
    return 0;
}

