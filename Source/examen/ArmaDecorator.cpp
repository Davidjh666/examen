// Fill out your copyright notice in the Description page of Project Settings.

#include "ArmaDecorator.h"

AArmaDecorator::AArmaDecorator(AexamenCharacter* InCharacter, FString InArma)
    : ADecorator(InCharacter), Arma(InArma)
{
}

FString AArmaDecorator::ObtenerDescripcion() const
{
    return ADecorator::ObtenerDescripcion() + " con un/a " + Arma;
}

