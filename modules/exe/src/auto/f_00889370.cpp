// src: LIB [0x00939d70]
extern "C" __declspec(dllimport) int __stdcall AIL_sample_stage_property(void* sample, int stage, int property, int index, void* val1, void* val2, int flags);

// src: GUESS (confidence: high) [0x00889370]
bool SetSampleStageProperty_00889370(void* sample, int prop, void* value)
{
    if (AIL_sample_stage_property(sample, 1, prop, -1, value, 0, 0))
        return true;
    return false;
}
