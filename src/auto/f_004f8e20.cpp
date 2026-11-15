// c5d-model: claude-opus-5-5
// Releases the eight slot resources held in the owner's slot table,
// skipping the shared default resource.

struct SlotEntry_004f8e20
{
    void* resource;
    int pad[4];
};

struct SlotOwner_004f8e20
{
    char pad[0x188];
    SlotEntry_004f8e20 slots[8];
};

extern void* g_defaultSlotResource_02dd204c;

class SlotReleaser_004f8e20
{
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void ReleaseResource(void* resource);

    void ReleaseAllSlots();

    SlotOwner_004f8e20* m_owner;
};

void SlotReleaser_004f8e20::ReleaseAllSlots()
{
    SlotOwner_004f8e20* owner = m_owner;
    for (int i = 0; i < 8; ++i)
    {
        void* res = owner->slots[i].resource;
        if (res != 0)
        {
            if (res != g_defaultSlotResource_02dd204c)
                ReleaseResource(res);
            owner->slots[i].resource = 0;
        }
    }
}
