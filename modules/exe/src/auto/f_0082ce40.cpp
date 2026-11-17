// c5d-model: Gemini 4 Hydrogen
// Calls virtual slot 1 with two arguments (edx preserved as second fastcall arg).

// src: GUESS (confidence: medium)
class VirtualSlot1Dispatcher_0082ce40
{
public:
    // src: GUESS (confidence: medium)
    virtual void Slot0();
    // src: GUESS (confidence: medium)
    virtual void __fastcall Slot1(int arg);
};

// src: GUESS (confidence: medium) [0x0082ce40]
void __fastcall DispatchSlot1_0082ce40(VirtualSlot1Dispatcher_0082ce40* obj, int arg)
{
    obj->Slot1(arg);
}
