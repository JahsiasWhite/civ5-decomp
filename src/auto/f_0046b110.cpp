#include <windows.h>

// Call counter bumped each time the weekday check runs.
int g_iLateWeekCheckCount;

// Returns true when the current UTC day is Thursday, Friday or Saturday.
bool IsLateWeekDayUTC()
{
    g_iLateWeekCheckCount += 1;
    bool bResult = false;
    SYSTEMTIME st;
    GetSystemTime(&st);
    WORD wDay = st.wDayOfWeek;
    if (wDay == 4 || wDay == 5 || wDay == 6)
        bResult = true;
    return bResult;
}
