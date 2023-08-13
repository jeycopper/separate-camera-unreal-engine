// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyCamera.h"

void AMyPlayerController::OnPossess(APawn* aPawn)
{
	// It is important to call the super OnPossess method to make sure the default logic also gets executed
	Super::OnPossess(aPawn);
	// Set the target of our camera to be equal to the pawn this controller possesses (thus when the controller will possess the player when the game starts, the camera's target will be set to reference that player)
	Camera->SetTargetToFollow(aPawn);
	// Make sure our camera is the one used to present player with view
	SetViewTarget(Camera);
}
