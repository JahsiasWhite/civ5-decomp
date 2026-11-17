// c5d-model: Gemini 3.8 Flash
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

// src: GUESS (confidence: low)
class HandleWrapper_00838f40 {
public:
    void* m_h;
    // src: GUESS (confidence: high) [0x00838f40]
    void Close();
};

void HandleWrapper_00838f40::Close() {
    CloseHandle(m_h);
}
