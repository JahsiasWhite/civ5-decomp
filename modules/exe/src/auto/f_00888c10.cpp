// c5d-cflags: -/arch:SSE2
extern "C" __declspec(dllimport) void __stdcall AIL_set_digital_master_reverb(void* driver, float reverb_decay_time, float reverb_predelay, float reverb_damping);

// src: LIB [0x00888c10]
void SetDigitalMasterReverb_00888c10(void* driver, float decay, float predelay, float damping)
{
    AIL_set_digital_master_reverb(driver, decay, predelay, damping);
}
