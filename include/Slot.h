#ifndef SLOT_H
#define SLOT_H

#include <string>

typedef enum { NeverUsed,
               Tombstone,
               Occupied } State;

struct Slot {
    char hashValue;
    std::string key;
    State state;
    Slot() : hashValue('a'), key(""), state(NeverUsed){};
};

#endif