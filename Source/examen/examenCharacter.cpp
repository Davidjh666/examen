// Copyright Epic Games, Inc. All Rights Reserved.

#include "examenCharacter.h"
#include "ArmaDecorator.h"
#include "ArmaduraDecorator.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Engine.h"

AexamenCharacter::AexamenCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AexamenCharacter::BeginPlay() {
	Super::BeginPlay(); 

	// Configuración del temporizador para activar y desactivar armadura y arma
	/* GetWorldTimerManager().SetTimer(TimerHandle_Armadura, this, &AexamenCharacter::ActivarArmadura, 5.0f, false); 
	 GetWorldTimerManager().SetTimer(TimerHandle_Arma, this, &AexamenCharacter::ActivarArma, 15.0f, false);*/

	// Ejemplo de uso del patrón Decorator
	/* AexamenCharacter* Peon = NewObject<AexamenCharacter>();
	 AexamenCharacter* PeonConArma = NewObject<AArmaDecorator>(Peon, TEXT("espada"));
	 AexamenCharacter* PeonConArmaYArmadura = NewObject<AArmaduraDecorator>(PeonConArma, TEXT("armadura de cuero"));*/
	
	 
	 
	/* UE_LOG(LogTemp, Log, TEXT("%s"), *Peon->ObtenerDescripcion()); UE_LOG(LogTemp, Log, TEXT("%s"), *PeonConArma->ObtenerDescripcion()); 
	 UE_LOG(LogTemp, Log, TEXT("%s"), *PeonConArmaYArmadura->ObtenerDescripcion());

	 if (GEngine)
	 { 
		 GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Peon->ObtenerDescripcion()); 
	 GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, PeonConArma->ObtenerDescripcion()); 
	 GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, PeonConArmaYArmadura->ObtenerDescripcion());
	 }*/


}


FString AexamenCharacter::ObtenerDescripcion() const
{
     return TEXT("Peon");
}

//////////////////////////////////////////////////////////////////////////
// Input

void AexamenCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AexamenCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AexamenCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AexamenCharacter::TouchStopped);
}

void AexamenCharacter::ActivarArmadura()
{
	UE_LOG(LogTemp, Log, TEXT("Armadura puesta")); 
	GetWorldTimerManager().SetTimer(TimerHandle_Armadura, this, &AexamenCharacter::DesactivarArmadura, 10.0f, false);
}

void AexamenCharacter::DesactivarArmadura()
{
	UE_LOG(LogTemp, Log, TEXT("Armadura desaparece"));
}

void AexamenCharacter::ActivarArma()
{
	UE_LOG(LogTemp, Log, TEXT("Arma activada"));
	GetWorldTimerManager().SetTimer(TimerHandle_Arma, this, &AexamenCharacter::DesactivarArma, 5.0f, false);
}

void AexamenCharacter::DesactivarArma()
{
	UE_LOG(LogTemp, Log, TEXT("Arma desactivada"));
}

void AexamenCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AexamenCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AexamenCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

