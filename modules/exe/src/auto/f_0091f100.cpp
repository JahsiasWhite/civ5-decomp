#include "Unk_009bbd20.h"

int GetChoiceValue_009bbd20(UnkChoiceOwner* owner) {
    int value = 0;
    UnkChoiceRecord* record = owner->m_record;
    if (record) {
        if (record->m_useFirst)
            return record->m_first;
        value = record->m_second;
    }
    return value;
}
