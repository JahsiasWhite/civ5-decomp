#include "Unk_0066a390.h"

// A handle from the registered factory, or an empty one when none is set.
UnkHandle_0066a390 MakeHandle_0066a390()
{
    if (g_handleFactory_02dd201c)
        return UnkHandle_0066a390(g_handleFactory_02dd201c());
    return UnkHandle_0066a390(0);
}
