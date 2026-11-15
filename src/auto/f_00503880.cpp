// c5d-model: claude-opus-5-5
// Returns the screen angle (radians) for one of the six hex directions.

float GetHexDirectionAngle(int eDirection)
{
    switch (eDirection)
    {
    case 0:
        return 2.61799288f;
    case 1:
        return 1.57079637f;
    case 2:
        return 0.523599863f;
    case 3:
        return 5.75958586f;
    case 4:
        return 4.71238899f;
    case 5:
        return 3.66519260f;
    default:
        return 1.0f;
    }
}
