// #include <iostream>
// #include <string>

#include<bits/stdc++.h>
#include "LZ77.cpp"
#define el '\n'
using namespace std;

// Token t(1,1,'c');
// t.dist | t.len | t.c
//(int, int, char)
string toLower(const string &s){
    string resp = s;
    for(char &c : resp)c = tolower(c);
    return resp;
}
LZ77 lz;

void runLZ(string s, char *modo, char *inputFileName, char *outputFileName){
     if (modo == "C") {
        LZ77 lz77 = LZ77();
        lz77.compress(inputFileName, outputFileName);
    } else if ( modo == "D") {
        LZ77 lz77 = LZ77();

    } 
}
  Token readToken(ifstream& inputFile) {
        Token token;
        inputFile.read(reinterpret_cast<char*>(&token), sizeof(Token));
        return token;
    }

    vector<Token> readFile(string fileName) {
        ifstream inputFile(fileName, ios::binary);
        vector<Token> tokens;
        while (inputFile.peek() != EOF) {
            Token token = readToken(inputFile);
            tokens.push_back(token);
        }
        inputFile.close();
        return tokens;
    }


void fileHandler(string fileName){
    cout << "Start typing and press enter to save compressed note: ";
    string file = lz.decompress(readFile(fileName));

    string input ="";
    while((getline(cin, input)) && toLower(input)!= "q"){
        file += input;
    }
    lz.compress(fileName, file);

    cout << "File Saved"<<el;
}

void compress(string outputFileName){
    ofstream outputFile(outputFileName, ios::binary);

}


int main(int argv, string argc[]) {
    string input;
    
    string commands = "";


    int it = 0;
    cout << "Enter command: ";
    while((getline(cin, input)) && toLower(input)!= "q"){
        if(toLower(input) == "help"){
            cout<<commands<<el;
        }
        else if (input == toLower("write") ) {
            cout << "Enter fileName: ";
            string fileName;
            getline(cin, fileName);

            fileHandler(fileName);
        } else if (input == toLower("edit")) {
            cout << "Enter the name of the file to edit: ";
            string filename;
            getline(cin, filename);
            fileHandler(filename);
        } else if(input == toLower("read")){
            cout << "Enter the name of the file to read: ";
            string filename;
            getline(cin, filename);
            cout<<lz.decompress(readFile(filename))<<el;
        }
        else {
            cout << "Unknown command" << el;
        }   
        cout << "Enter command: ";
    }
    return 0;
}

