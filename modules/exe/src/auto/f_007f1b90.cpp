// src: GUESS (confidence: medium) [0x007f1b90]
#include <cstring>
#include <map>

// src: GUESS (confidence: low)
class StringMap_007f1b90 {
public:
    // src: GUESS (confidence: medium) [0x007f1b90]
    void* FindValue(const char* szKey) const;

    std::map<void*, const char*> m_map;  // +0x00 (_Myhead at +0x04)
};

void* StringMap_007f1b90::FindValue(const char* szKey) const {
    for (std::map<void*, const char*>::const_iterator it = m_map.begin(); it != m_map.end(); ++it) {
        if (std::strcmp(it->second, szKey) == 0) {
            return it->first;
        }
    }
    return 0;
}
