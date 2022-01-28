#include <iostream>
#include <sstream>

#include "HashTable.h"
#include "Slot.h"

int main() {
    HashTable hashTable;
    std::string input;
    getline(std::cin, input);
    std::stringstream stream(input);
    while (stream.good()) {
        std::string token;
        stream >> token;
        switch (token[0]) {
            case 'A':
                hashTable.insert(token.substr(1));
                break;
            case 'D':
                hashTable.del(token.substr(1));
        }
    }

    for (Slot s : hashTable.table) {
        if (s.state == Occupied) std::cout << s.hashValue << ":" << s.key << " ";
    }
    std::cout << std::endl;

    return 0;
}