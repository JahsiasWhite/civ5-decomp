// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall AIL_set_room_type(void*, void*);
// src: LIB [0x00922ff0]
int __cdecl MSS_AIL_set_room_type(void* a, void* b) {
    return AIL_set_room_type(a, b);
}
