// src: LIB [0x00939d70]
extern "C" __declspec(dllimport) int __stdcall AIL_sample_stage_property(void* sample, int stage, int property, int index, void* val1, void* val2, int flags);

// src: GUESS (confidence: high) [0x00889340]
bool GetSampleStageProperty_00889340(void* sample, int prop, int value)
{
    if (AIL_sample_stage_property(sample, 1, prop, -1, 0, &value, 0))
        return true;
    return false;
}
