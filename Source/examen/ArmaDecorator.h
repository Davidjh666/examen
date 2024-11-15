// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorator.h"

class AArmaDecorator : public ADecorator
{
protected:
    FString Arma;
public:
    AArmaDecorator(AexamenCharacter* InCharacter, FString InArma); 
    virtual FString ObtenerDescripcion() const override;
};
