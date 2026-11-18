#include "Unk_008eb1f0.h"

void** UnkArrayOwnerRef::GetItems() {
    if (m_owner != 0 && m_owner->GetItemCount() > 0)
        return m_owner->m_itemsBegin;
    return 0;
}
