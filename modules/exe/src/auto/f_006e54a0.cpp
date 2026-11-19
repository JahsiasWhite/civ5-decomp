// src: GUESS (confidence: low) [0x006e54a0]
int __stdcall FindLastValid_006e54a0(int* arr, int max_idx, int dummy) {
    if (max_idx >= 0) {
        for (int i = max_idx; i >= 0; --i) {
            if (arr[i] != -1) {
                return arr[i];
            }
        }
    }
    return -1;
}
