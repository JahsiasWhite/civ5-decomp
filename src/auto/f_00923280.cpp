// c5d-model: Gemini 3.8 Flash
// c5d-review: __declspec(naked) AIL wrapper thunk
extern "C" void* __imp__AIL_sample_volume_pan_12;

// src: GUESS (confidence: high) [0x00923280]
__declspec(naked) void __cdecl AIL_SampleVolumePanThunk_00923280(void* p1, void* p2, void* p3) {
    __asm {
        mov eax, dword ptr [esp + 0x0c]
        mov ecx, dword ptr [esp + 0x08]
        mov edx, dword ptr [esp + 0x04]
        push eax
        push ecx
        push edx
        call dword ptr [__imp__AIL_sample_volume_pan_12]
        ret
    }
}
