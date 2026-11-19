// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x00723990]
class IFloatHandler_00723990 {
public:
    virtual void Dummy0() = 0;
    virtual void Dummy1() = 0;
    virtual void HandleFloat(float val) = 0;
    void ForwardFloat(float val);
};

// src: GUESS (confidence: high) [0x00723990]
void IFloatHandler_00723990::ForwardFloat(float val)
{
    HandleFloat(val);
}
