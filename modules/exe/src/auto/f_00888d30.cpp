// c5d-model: Gemini 3.8 Flash

// src: LIB [0x009d6d80]
extern "C" __declspec(dllimport) void __stdcall AIL_pause_stream(void* stream, int onoff);

// src: GUESS (confidence: high) [0x00923140]
void PauseStream_00923140(void* stream, bool onoff)
{
    AIL_pause_stream(stream, onoff);
}
