// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmaduraDecorator.h"

AArmaduraDecorator::AArmaduraDecorator(AexamenCharacter* InCharacter, FString InArmadura)
    : ADecorator(InCharacter), Armadura(InArmadura)
{
}

FString AArmaduraDecorator::ObtenerDescripcion() const
{
    return ADecorator::ObtenerDescripcion() + " con una " + Armadura;
}
