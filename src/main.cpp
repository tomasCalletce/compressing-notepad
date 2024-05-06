#include <iostream>
#include <string>
#include <cstring> 

int main() {
    const int MAX_NOTE_SIZE = 10; 
    char data[MAX_NOTE_SIZE];       

    std::string input;
    std::cout << "Enter command: ";
    std::getline(std::cin, input);

    if (input == "write") {
        std::cout << "Start typing and press enter to save compressed note: ";
        std::string note;
        std::getline(std::cin, note);

        strcpy(data, note.c_str()); 

        std::cout << "Saved Note: " << data << std::endl;

    } else {
        std::cout << "Unknown command" << std::endl;
    }

    return 0;
}
