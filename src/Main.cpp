#include <iostream>

#include "HashTable.h"
#include "Slot.h"

int main() {
    HashTable hashTable;
    for (int i = 0; i < 26; i++) {
        Slot s = hashTable.table[i];
        std::cout << s.hashValue << " " << s.key << " " << s.state << std::endl;
    }
    hashTable.insert("hello");
    for (int i = 0; i < 26; i++) {
        Slot s = hashTable.table[i];
        std::cout << s.hashValue << " " << s.key << " " << s.state << std::endl;
    }
    hashTable.insert("jello");
    for (int i = 0; i < 26; i++) {
        Slot s = hashTable.table[i];
        std::cout << s.hashValue << " " << s.key << " " << s.state << std::endl;
    }
    hashTable.del("hello");
    for (int i = 0; i < 26; i++) {
        Slot s = hashTable.table[i];
        std::cout << s.hashValue << " " << s.key << " " << s.state << std::endl;
    }
    hashTable.insert("wello");
    for (int i = 0; i < 26; i++) {
        Slot s = hashTable.table[i];
        std::cout << s.hashValue << " " << s.key << " " << s.state << std::endl;
    }
    return 0;
}