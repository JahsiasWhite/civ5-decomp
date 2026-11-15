// c5d-model: claude-opus-5-5
// Returns true when the global owner's sub-object at +0x6f0 exists and its
// state field equals 9.

struct StateObject_0079fd50 {
    int pad0;
    int pad4;
    int pad8;
    int state;
};

struct GlobalOwner_0079fd50 {
    char pad[0x6f0];
    StateObject_0079fd50* sub;
};

GlobalOwner_0079fd50* g_pOwner_00cc8e74;

bool IsSubObjectState9_0079fd50()
{
    StateObject_0079fd50* sub = g_pOwner_00cc8e74->sub;
    if (sub != 0)
        return sub->state == 9;
    return false;
}
