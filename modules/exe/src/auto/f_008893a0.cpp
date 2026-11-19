// Miles Sound System: starts up and opens the digital output driver.

// src: LIB
extern "C" __declspec(dllimport) int __stdcall AIL_startup();
// src: LIB
extern "C" __declspec(dllimport) int __stdcall AIL_set_preference(unsigned int number, int value);
// src: LIB
extern "C" __declspec(dllimport) void* __stdcall AIL_open_digital_driver(unsigned int frequency, int bits, int channels, unsigned int flags);

// src: GUESS (confidence: low) [0x009237a0]
void* OpenDigitalDriver_009237a0(unsigned int frequency, int bits, int channels)
{
    if (!channels)
        return 0;
    AIL_startup();
    AIL_set_preference(1, 0x80);
    return AIL_open_digital_driver(frequency, bits, channels, 0);
}
