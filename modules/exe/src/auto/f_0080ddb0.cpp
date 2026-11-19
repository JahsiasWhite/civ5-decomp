// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: low)
struct KeyFrame_008a7d00
{
    // src: GUESS (confidence: low)
    unsigned int m_ticks;
};

// src: GUESS (confidence: low)
struct TrackData_008a7d00
{
    // src: GUESS (confidence: low)
    unsigned char m_pad00[0x2c];
    // src: GUESS (confidence: low)
    KeyFrame_008a7d00** m_keys;
};

// src: GUESS (confidence: low)
struct AnimPlayer_008a7d00
{
    // src: GUESS (confidence: low)
    unsigned int m_flags;
    // src: GUESS (confidence: low)
    TrackData_008a7d00* m_track;
    // src: GUESS (confidence: low)
    float m_speed;
    // src: GUESS (confidence: low)
    float m_dir;
    // src: GUESS (confidence: low)
    float m_minTime;
    // src: GUESS (confidence: low)
    float m_maxTime;
    // src: GUESS (confidence: low)
    int m_key0;
    // src: GUESS (confidence: low)
    int m_key1;
    // src: GUESS (confidence: low)
    float m_alpha;
    // src: GUESS (confidence: low)
    float m_time;
    // src: GUESS (confidence: low)
    float m_prevTime;
    // src: GUESS (confidence: low)
    float m_rate;
    // src: GUESS (confidence: low)
    float m_scale;
};

// src: GUESS (confidence: medium) [0x008a7d00]
void AdvanceAnim_008a7d00(AnimPlayer_008a7d00* obj, float dt)
{
    obj->m_prevTime = obj->m_time;
    obj->m_time = obj->m_rate * obj->m_speed * obj->m_dir * dt * obj->m_scale + obj->m_time;
    int clamped = 0;
    if (obj->m_time <= obj->m_minTime)
    {
        obj->m_time = obj->m_minTime;
        clamped = 1;
    }
    if (obj->m_time >= obj->m_maxTime)
    {
        obj->m_time = obj->m_maxTime;
        clamped = 1;
    }
    if (!clamped)
    {
        if (obj->m_dir < 0.0)
        {
            while ((float)(unsigned int)obj->m_time < (float)obj->m_track->m_keys[obj->m_key0]->m_ticks)
            {
                obj->m_key0 = obj->m_key0 - 1;
                obj->m_key1 = obj->m_key1 - 1;
            }
        }
        else
        {
            while ((float)(unsigned int)obj->m_time >= (float)obj->m_track->m_keys[obj->m_key0]->m_ticks &&
                   (float)(unsigned int)obj->m_time >= (float)obj->m_track->m_keys[obj->m_key1]->m_ticks)
            {
                obj->m_key0 = obj->m_key0 + 1;
                obj->m_key1 = obj->m_key1 + 1;
            }
        }
        obj->m_alpha = (obj->m_time - (float)obj->m_track->m_keys[obj->m_key0]->m_ticks) /
                       ((float)obj->m_track->m_keys[obj->m_key1]->m_ticks - (float)obj->m_track->m_keys[obj->m_key0]->m_ticks);
    }
    if (dt > 0.0 && clamped && (obj->m_flags & 1))
    {
        obj->m_time = (obj->m_flags & 2) ? obj->m_maxTime : obj->m_minTime;
        obj->m_key0 = 0;
        obj->m_key1 = obj->m_key0 + 1;
        obj->m_flags |= 4;
        obj->m_alpha = 0.0f;
    }
    else if (dt > 0.0 && clamped)
    {
        obj->m_flags |= 4;
        obj->m_alpha = 1.0f;
    }
    if (!clamped)
    {
        obj->m_flags &= ~4;
    }
}
