// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

class Handle_0081ab90 {
public:
    void* m_handle;
    // src: GUESS (confidence: high) [0x0081ab90]
    void __thiscall Close();
};

void Handle_0081ab90::Close() {
    if (m_handle) {
        CloseHandle(m_handle);
        m_handle = 0;
    }
}
