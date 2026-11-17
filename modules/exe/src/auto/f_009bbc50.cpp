// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x00cb38b4]
extern void (__cdecl *g_GrannyLog_00cb38b4)(const char* file, int line, const char* msg);

// src: GUESS (confidence: high) [0x009bbc50]
void GrannyLogTrackMask_009bbc50(const char* msg) {
    g_GrannyLog_00cb38b4("..\\granny_track_mask.cpp", 0xa5, msg);
}
