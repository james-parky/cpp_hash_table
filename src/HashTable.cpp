#include "HashTable.h"

#include <array>
#include <iostream>
#include <string>

#include "Slot.h"

HashTable::HashTable() {
    for (int i = 0; i < 26; i++) {
        table[i].hashValue = char(i + 97);
    }
}

int HashTable::hash(std::string key) {
    return int(key.back()) - 97;
}

int HashTable::search(std::string key) {
    int index = hash(key);

    for (int i = 0; i < 26; i++) {
        if (table[index].key == key) {
            return index;
        }
        switch (table[index].state) {
            case NeverUsed:
                return -1;

            case Occupied:
            case Tombstone:
                index++;
                index = index % 26;
        }
    }
    return -1;
}

void HashTable::insert(std::string key) {
    if (search(key) == -1) {
        int index = hash(key);
        for (int i = 0; i < 26; i++) {
            if (table[index].state != Occupied) {
                table[index].state = Occupied;
                table[index].key = key;
                std::cout << table[index].key << std::endl;
                return;
            } else {
                index++;
                index = index % 26;
            }
        }
    }
}

void HashTable::del(std::string key) {
    if (search(key) != -1) {
        int index = hash(key);
        table[index].state = Tombstone;
    }
}