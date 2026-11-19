// Records a new peak: flags the owner when the value rises above the last
// one by more than the threshold allows, then stores it.

// src: GUESS (confidence: low)
struct Peak_008f43f0
{
    char m_pad0[0xc];
    // src: GUESS (confidence: low)
    float m_last;
};

// src: GUESS (confidence: low)
struct Sample_008f43f0
{
    // src: GUESS (confidence: low)
    float m_value;
    // src: GUESS (confidence: low)
    float m_threshold;
};

// src: GUESS (confidence: low)
class Detector_008f43f0
{
public:
    // src: GUESS (confidence: low) [0x008f43f0]
    void Update(Peak_008f43f0* peak, const Sample_008f43f0* sample);

    char m_pad0[0x94];
    // src: GUESS (confidence: low)
    bool m_triggered;
};

void Detector_008f43f0::Update(Peak_008f43f0* peak, const Sample_008f43f0* sample)
{
    float value = sample->m_value;
    float last = peak->m_last;
    if (value > last && (value - last) + value > sample->m_threshold)
        m_triggered = true;
    peak->m_last = sample->m_value;
}
