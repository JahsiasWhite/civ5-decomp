// c5d-model: Gemini 3.8 Flash
struct Obj_009bbd90 {
    char pad[0x1c];
    int val;
};
// src: GUESS (confidence: high) [0x009bbd90]
bool __cdecl Check_009bbd90(Obj_009bbd90* p) {
    return p->val <= 1;
}
