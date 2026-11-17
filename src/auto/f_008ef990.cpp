// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high) [0x008ef950]
void CallbackA_008ef950();
// src: GUESS (confidence: high) [0x008ef910]
void CallbackB_008ef910();

// src: GUESS (confidence: high)
struct PairOut_008ef990 {
    void* m_fnA;
    void* m_fnB;
    void* m_ctx;
};

// src: GUESS (confidence: high)
class Host_008ef990 {
public:
    void InitOut(PairOut_008ef990* out);
};

// src: GUESS (confidence: high) [0x008ef990]
void Host_008ef990::InitOut(PairOut_008ef990* out) {
    if (out) {
        out->m_fnA = (void*)&CallbackA_008ef950;
        out->m_fnB = (void*)&CallbackB_008ef910;
        out->m_ctx = this;
    }
}
