// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "examenGameMode.generated.h"

UCLASS(minimalapi)
class AexamenGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AexamenGameMode();

    UPROPERTY(BlueprintReadOnly, Category = "Character")
    AexamenCharacter* PlayerCharacter;

    virtual void BeginPlay() override;

private:
    void SetupCharacter();
};
