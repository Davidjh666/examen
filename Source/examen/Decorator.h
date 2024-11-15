// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "examenCharacter.h"

class ADecorator : public AexamenCharacter
{
protected:
    AexamenCharacter* Character;
public:
    ADecorator(AexamenCharacter* InCharacter);
    virtual FString ObtenerDescripcion() const override;
};
