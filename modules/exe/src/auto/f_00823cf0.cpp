// src: GUESS (confidence: low) [0x00823cf0]
struct HeapElem12 {
    unsigned short key;
    unsigned short pad2;
    int f4;
    int f8;
};

void __cdecl PushHeap12(HeapElem12* first, int hole, int top, HeapElem12 val) {
    int parent = (hole - 1) / 2;
    while (top < hole && first[parent].key < val.key) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = val;
}
