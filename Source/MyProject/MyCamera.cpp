// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyCamera::AMyCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character   
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Make sure camera class is constructed with target set to nullptr
	TargetToFollow = nullptr;
}

// Called when the game starts or when spawned
void AMyCamera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if target is set
	if (TargetToFollow) {
		// Get location of the target
		FVector TargetLocation = TargetToFollow->GetActorLocation();
		// Set camera location to be equal to the location of the target
		SetActorLocation(TargetLocation);
	}

	// Get the rotation for the camera (it is set in the MyProjectCharacter.cpp file in the void AMyProjectCharacter::Look(const FInputActionValue& Value) method based on the input from player)
	FRotator ControlRotation = PlayerController->GetControlRotation();
	// Apply the rotation to the camera actor
	SetActorRotation(ControlRotation);
}

