#include <stdlib.h>
#include <string.h>

// src: GUESS (confidence: high) [0x00406810]
bool checkTbbVersion_00406810() {
    const char* val = getenv("TBB_VERSION");
    if (val != NULL) {
        return strcmp(val, "0") != 0;
    }
    return false;
}
