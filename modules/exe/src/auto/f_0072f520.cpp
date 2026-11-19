// src: GUESS (confidence: low) [0x0072f520]
struct ListNode_0072f520 {
    ListNode_0072f520* next;
    ListNode_0072f520* prev;
    int val;
};

// src: GUESS (confidence: low) [0x0072f520]
struct Class_0072f520 {
    char pad[0x970c];
    ListNode_0072f520* head;

    bool Contains(int val);
};

bool Class_0072f520::Contains(int val) {
    ListNode_0072f520* h = this->head;
    for (ListNode_0072f520* cur = h->next; cur != h; cur = cur->next) {
        if (val == cur->val) {
            return true;
        }
    }
    return false;
}
