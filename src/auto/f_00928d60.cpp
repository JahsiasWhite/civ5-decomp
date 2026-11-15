// c5d-model: claude-opus-5-5
// Control-message handler for a codec/stream-like object: handles a few
// get/set/flag messages itself and forwards everything else to the
// default handler found in its dispatch table.

struct CtlObject;

typedef unsigned int (__cdecl *CtlHandlerFn)(CtlObject* obj, int msg, unsigned int a, unsigned int b);

struct CtlDispatch
{
    char pad00[0x40];
    CtlHandlerFn defaultHandler;
};

struct CtlInner
{
    char pad00[0xa0];
    unsigned int value;
};

struct CtlObject
{
    int magic;
    int field04;
    CtlDispatch* dispatch;
    char pad0c[0x5c - 0x0c];
    CtlInner* inner;
    unsigned int value60;
    int field64;
    unsigned int value68;
    char pad6c[0xf4 - 0x6c];
    unsigned int flagsF4;
    unsigned int flagsF8;
    unsigned int valueFC;
};

unsigned int __cdecl CtlObject_HandleMessage(CtlObject* obj, int msg, unsigned int a, unsigned int b)
{
    unsigned int old;
    switch (msg)
    {
    case 0x28:
        return obj->value60;
    case 0x29:
        old = obj->value60;
        obj->value60 = a;
        return old;
    case 0x10:
        obj->value68 = b;
        return 1;
    case 0x20:
        obj->flagsF4 |= a;
        return obj->flagsF4;
    case 0x21:
        obj->flagsF8 |= a;
        return obj->flagsF8;
    case 0x32:
        return obj->valueFC;
    case 0x33:
        old = obj->valueFC;
        obj->valueFC = a;
        return old;
    case 0x11:
        if (obj->magic == 0xfeff)
        {
            obj->inner->value = a;
            return a;
        }
        return 0;
    default:
        return obj->dispatch->defaultHandler(obj, msg, a, b);
    }
}
