// src: GUESS (confidence: low) [0x00939b40]
struct Array_00939b40 {
    int count;
    int* data;
};

// src: GUESS (confidence: low) [0x00939b40]
int SetElem_00939b40(Array_00939b40* arr, int index, int val) {
    if (arr != 0 && index >= 0 && index < arr->count) {
        arr->data[index] = val;
        return val;
    }
    return 0;
}
