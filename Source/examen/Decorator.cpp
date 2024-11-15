// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorator.h"

ADecorator::ADecorator(AexamenCharacter* InCharacter)
    : AexamenCharacter(), Character(InCharacter)
{
}

FString ADecorator::ObtenerDescripcion() const
{
    return Character->ObtenerDescripcion();
}
