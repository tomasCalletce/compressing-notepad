// #include <iostream>
// #include <string>

#include<bits/stdc++.h>
#define el '\n'
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

    string decompress(string fileName){

    }

    void compress(string fileName, string input){
        int currentIndex = 0;
        while(true){
            vector<Token> search(currentIndex, input);
        }
    }

    vector<Token> search(int start, string input){
        int end = min(start + lookaheadBuffer, static_cast<int>(input.size()));
        vector<Token> tokens;
        while (start < end) {
            int bestMatchDistance = -1;
            int bestMatchLength = -1;
            char bestMatchChar = input[start + bestMatchLength];

            for (int i = max(0, start - windowSize); i < start; ++i) {
                int j = start;
                int length = 0;
                while (j < end && input[i + length] == input[j]) {
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