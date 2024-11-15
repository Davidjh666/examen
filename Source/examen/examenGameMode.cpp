// Copyright Epic Games, Inc. All Rights Reserved.

#include "examenGameMode.h"
#include "examenCharacter.h"
#include "ArmaDecorator.h"
#include "ArmaduraDecorator.h"
#include "PistolaDecorator.h" // Asegúrate de incluir tus decoradores

AexamenGameMode::AexamenGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void AexamenGameMode::BeginPlay()
{
    Super::BeginPlay();
    SetupCharacter();
}

void AexamenGameMode::SetupCharacter()
{
    // Crear el personaje base
    PlayerCharacter = NewObject<AexamenCharacter>();

    // Aplicar decoradores
    AexamenCharacter* PeonConArma = NewObject<AArmaDecorator>(PlayerCharacter, TEXT("espada"));
    AexamenCharacter* PeonConArmaYArmadura = NewObject<AArmaduraDecorator>(PeonConArma, TEXT("armadura de cuero"));
  
 
   
}
