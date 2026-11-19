// c5d-cflags: -/EHsc +/GS-
// src: GUESS (confidence: low) [0x1000a470]
struct NodeB_1000a470 {
    int pad0[4];
    int owner;
    int pad14;
    NodeB_1000a470* next;
};
// src: GUESS (confidence: low) [0x1000a470]
struct ArenaData_1000a470 {
    int pad0[8];
    NodeB_1000a470* headB;
};
// src: GUESS (confidence: low) [0x1000a470]
struct XmlDoc_1000a470 {
    int vtable;
    ArenaData_1000a470* data;
    int CountNodes();
};
int XmlDoc_1000a470::CountNodes() {
    if (this->data) {
        int n = 0;
        for (NodeB_1000a470* b = this->data->headB; b; b = b->next) {
            n++;
            if (!b->owner) break;
        }
        return n;
    }
    return -1;
}
