// Returns whether the value of one virtual getter is at least that of
// another (unsigned comparison). Slot names are placeholders.

class VirtualCountPair
{
public:
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0c() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1c() = 0;
    virtual unsigned int GetLimit() = 0;      // +0x20
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2c() = 0;
    virtual void vf30() = 0;
    virtual void vf34() = 0;
    virtual void vf38() = 0;
    virtual unsigned int GetCount() = 0;      // +0x3c

    bool IsAtLimit();
};

bool VirtualCountPair::IsAtLimit()
{
    unsigned int count = GetCount();
    return count >= GetLimit();
}
