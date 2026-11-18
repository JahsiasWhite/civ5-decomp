#include "Unk_00b89ec8.h"

void Unk_00b89ec8::LookupAndApply(int key)
{
    int value = Lookup(key);
    Apply(value);
}
