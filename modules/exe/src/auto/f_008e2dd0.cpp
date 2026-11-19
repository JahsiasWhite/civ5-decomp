// src: GUESS (confidence: low) [0x008e2dd0]
struct Sub_008e2dd0 {
    char pad[0x24];
    unsigned int flags;
};

// src: GUESS (confidence: low) [0x008e2dd0]
struct Obj_008e2dd0 {
    char pad[4];
    Sub_008e2dd0* sub;
};

// src: GUESS (confidence: low) [0x008e2dd0]
int CheckFlags_008e2dd0(Obj_008e2dd0* obj) {
    if (obj != 0) {
        Sub_008e2dd0* s = obj->sub;
        if (s != 0) {
            if ((s->flags & 0xc0000000) == 0xc0000000) {
                return 1;
            }
        }
    }
    return 0;
}
