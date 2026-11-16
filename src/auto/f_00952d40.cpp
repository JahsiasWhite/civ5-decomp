// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
struct UnkStruct_00952d40 {
    char pad[0x1c];
    void* field_1C;
};

// src: GUESS (confidence: high) [0x00952d40]
void* __cdecl GetField1C_00952d40(UnkStruct_00952d40* p) {
    return p->field_1C;
}
