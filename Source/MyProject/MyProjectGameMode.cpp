// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectGameMode.h"
#include "MyProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyCamera.h"
#include "MyPlayerController.h"

AMyProjectGameMode::AMyProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

APlayerController* AMyProjectGameMode::SpawnPlayerController(ENetRole InRemoteRole, const FString& Options)
{
	// Make sure that our own player controller class will be used
	PlayerControllerClass = AMyPlayerController::StaticClass();
	// Call the super method: thats where the class will get instantiated and returned
	APlayerController* PlayerController = Super::SpawnPlayerController(InRemoteRole, Options);
	// The player controller class will be our player controller class (AMyPlayerController in this case) because of the line PlayerControllerClass = AMyPlayerController::StaticClass(); at the beginning of the method
	// We can safely cast the instantiated player controller class to our player controller class so that we can use our methods
	AMyPlayerController* MyPlayerController = CastChecked<AMyPlayerController>(PlayerController);
	// Get the world. The one will be used to instantiate our camera actor
	UWorld* World = GetWorld();
	// Instantiate our camera actor (actor of type AMyCamera in this case) at position (0, 0, 0) with rotation (0, 0, 0)
	AActor* CameraActor = World->SpawnActor(AMyCamera::StaticClass(), &FVector::ZeroVector, &FRotator::ZeroRotator);
	// We have just spawned AMyCamera and assigned it to the variable CameraActor. Since we know it is of type AMyCamera, we can safelty cast CameraActor variable to the AMyCamera class to be able to use its methods
	AMyCamera* MyCamera = CastChecked<AMyCamera>(CameraActor);
	// Pass the instantiated player controller to the camera so that it can read the rotation from one
	MyCamera->SetPlayerController(PlayerController);
	// Pass instantiated camera to the player controller so that it can be bound to the player the controller possesses
	MyPlayerController->SetCamera(MyCamera);
	// Return the instantiated player controller
	return PlayerController;
}
