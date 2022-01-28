#ifndef HASHTABLE
#define HASHTABLE

#include <array>
#include <iostream>

#include "Slot.h"

class HashTable {
   public:
    std::array<Slot, 26> table;

   public:
    HashTable();
    static int hash(std::string);
    int search(std::string);
    void insert(std::string);
    void del(std::string);
};

#endif