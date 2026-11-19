// src: GUESS (confidence: low) [0x00825670]
struct Node_00825670 {
    Node_00825670* next;
    Node_00825670* prev;
    int val;
};

// src: GUESS (confidence: low) [0x00825670]
struct Class_00825670 {
    char pad[0x1cc];
    Node_00825670* head;

    int* FindVal(int val);
};

int* Class_00825670::FindVal(int val) {
    Node_00825670* h = this->head;
    for (Node_00825670* cur = h->next; cur != h; cur = cur->next) {
        if (cur->val == val) {
            return &cur->val;
        }
    }
    return 0;
}
