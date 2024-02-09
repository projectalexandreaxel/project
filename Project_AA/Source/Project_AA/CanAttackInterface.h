#pragma once

#include "CanAttackInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UCanAttackInterface : public UInterface
{
    GENERATED_BODY()
};

class ICanAttackInterface
{    
    GENERATED_BODY()

public:
    virtual void Attack() = 0;
};