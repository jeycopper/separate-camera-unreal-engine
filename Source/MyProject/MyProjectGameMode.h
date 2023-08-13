// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyProjectGameMode.generated.h"

UCLASS(minimalapi)
class AMyProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyProjectGameMode();

	// Override this method to change what happens when a player controller is spawned
	virtual APlayerController* SpawnPlayerController(ENetRole InRemoteRole, const FString& Options) override;
};



