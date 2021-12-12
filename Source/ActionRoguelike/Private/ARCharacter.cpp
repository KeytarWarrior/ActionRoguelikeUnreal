// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AARCharacter::AARCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach a spring arm (bouncy) component to the player
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	//Attach the camera to the spring arm, so it's behind player and has collision (doesn't go into world)
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AARCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

//Function that passes movement input and uses specified key
void AARCharacter::MoveForward(float value)
{
	//Adds movement direction in given vector using 1 or -1 value from editor (Project Settings)
	AddMovementInput(GetActorForwardVector(), value);
}

// Called every frame
void AARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AARCharacter::MoveForward);

	//Vertical rotation
	PlayerInputComponent->BindAxis("turn", this, &APawn::AddControllerYawInput);
}

