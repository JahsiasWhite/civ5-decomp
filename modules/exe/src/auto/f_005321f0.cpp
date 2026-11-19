// Copies the game's current value into every unit.

// src: GUESS (confidence: low)
struct Game_00669660
{
    char m_pad0[0x33f74];
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x03010570]
extern Game_00669660* g_game_03010570;

// src: GUESS (confidence: low)
struct Unit_00669660
{
    char m_pad0[0x1cc];
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low)
class Units_00669660
{
public:
    // src: GUESS (confidence: low) [0x00669660]
    void SyncValue();

    char m_pad0[0x1ae0];
    // src: GUESS (confidence: low)
    Unit_00669660** m_units;
    char m_pad1ae4[0x2318 - 0x1ae4];
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

void Units_00669660::SyncValue()
{
    int value = g_game_03010570->m_value;
    for (unsigned int i = 0; i < m_count; ++i)
        m_units[i]->m_value = value;
}
