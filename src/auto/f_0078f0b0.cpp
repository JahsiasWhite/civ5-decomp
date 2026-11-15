// CvEngineUtilityImpl::DoTurn does nothing. The linker folds this empty
// body with every other identical one, which is why it has so many callers.

class CvEngineUtilityImpl
{
public:
    void DoTurn();
};

void CvEngineUtilityImpl::DoTurn()
{
}
