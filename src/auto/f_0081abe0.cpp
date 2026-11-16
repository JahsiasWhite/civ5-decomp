// c5d-model: Gemini 3.8 Flash
extern "C" __declspec(dllimport) int __stdcall ReleaseMutex(void* hMutex);

// src: GUESS (confidence: low)
class MutexWrapper_0081abe0 {
public:
    void* m_hMutex;
    // src: GUESS (confidence: high) [0x0081abe0]
    void Release();
};

void MutexWrapper_0081abe0::Release() {
    ReleaseMutex(m_hMutex);
}
