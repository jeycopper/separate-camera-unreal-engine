// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// Reference to our camera
	class AMyCamera* Camera;

protected:
	// Declare an override for the OnPossess method. This method will be called when the controller possesses will possess our player at the start of the game
	virtual void OnPossess(APawn* aPawn) override;

public:
	// Setter to set camera from another scripts
	FORCEINLINE void SetCamera(class AMyCamera* NewCamera) { Camera = NewCamera; }
};
