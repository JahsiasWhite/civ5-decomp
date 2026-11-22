// src: GUESS (confidence: low)
// Parse improvement/asset type string to enum

#include <string.h>

int __stdcall fn_005c3a90(const char* name)
{
    if (strcmp(name, "FARM") == 0) {
        return 1;
    }
    if (strcmp(name, "PASTURE") == 0) {
        return 3;
    }
    if (strcmp(name, "SPECIAL") == 0) {
        return 2;
    }
    if (strcmp(name, "SPRING") == 0) {
        return 4;
    }
    if (strcmp(name, "ANIMATED") == 0) {
        return 5;
    }
    if (strcmp(name, "ANIMATED_ROTATED") == 0) {
        return 6;
    }
    if (strcmp(name, "RANDOM") == 0) {
        return 7;
    }
    if (strcmp(name, "SNAPSHOT") == 0) {
        return 0;
    }
    return 0;
}
