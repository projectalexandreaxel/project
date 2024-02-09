#pragma once

#include "InteractableInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractableInterface : public UInterface
{
    GENERATED_BODY()
};

class IInteractableInterface
{    
    GENERATED_BODY()

public:
    virtual void Interact() = 0;
};