// #include <iostream>
// #include <string>

#include<bits/stdc++.h>

#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define sz(a) (int) a.size()
using namespace std;

 struct Token {
        int distance;
        int length;
        char nextChar;
    };

struct LZ77{
    string compFileName;
    const int windowSize = 4096; // Tamaño de la ventana deslizante
    const int lookaheadBuffer = 15; // Tamaño del buffer de búsqueda adelantada
    LZ77(){}
    // LZ77(string compFileName): compFileName(compFileName){}

    // string decompress(string fileName){

    // }

    void compress(string outputFileName, string input){
         ofstream outputFile(outputFileName, ios::binary);
        int currentIndex = 0;
        d(input);
        while(currentIndex < sz(input)){
            d(currentIndex);
            vector<Token> tokens = search(currentIndex, input);
             for(Token token : tokens){
                outputFile.write(reinterpret_cast<const char*>(&token), sizeof(Token));
            }
        }
    }


    vector<Token> search(int &start, string input){
        int end = min(start + lookaheadBuffer, sz(input) );
        vector<Token> tokens;

        while (start < end) {
            int bestMatchDistance = 0;
            int bestMatchLength = 0;
            char bestMatchChar = input[start + bestMatchLength];

            for (int i = max(0, start - windowSize); i < start; ++i) {
                int j = start;
                int length = 0;
                while (j < end - 1 && i + length < start && input[i + length] == input[j]) {
                    ++j;
                    ++length;
                }

                if (length > bestMatchLength) {
                    bestMatchDistance = start - i;
                    bestMatchLength = length;
                    bestMatchChar = input[j];
                }
            }

            tokens.push_back({bestMatchDistance, bestMatchLength, bestMatchChar});
            start += (bestMatchLength + 1);
        }
        
        return tokens;
    }
};


int main(){

    string s;
    cin>>s;
    LZ77 lz;
    lz.compress("compressedfile.calle", s);
    return 0;
}