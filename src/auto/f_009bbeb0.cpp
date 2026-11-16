// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct Unk_009bbeb0 {
    char pad[0x0c];
    int ref_count;
};

// src: GUESS (confidence: high) [0x009bbeb0]
void __cdecl IncRef_009bbeb0(Unk_009bbeb0* p) {
    p->ref_count++;
}
