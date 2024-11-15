// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorator.h"

class AArmaduraDecorator : public ADecorator
{
protected:
    FString Armadura;
public:
    AArmaduraDecorator(AexamenCharacter* InCharacter, FString InArmadura); 
    virtual FString ObtenerDescripcion() const override;
};

