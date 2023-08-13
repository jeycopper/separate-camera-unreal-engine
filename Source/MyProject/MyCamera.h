// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCamera.generated.h"

UCLASS()
class MYPROJECT_API AMyCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCamera();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// An actor the camera will follow
	class AActor* TargetToFollow;
	// Player controller
	class APlayerController* PlayerController;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Setter for the target the camera will follow
	FORCEINLINE void SetTargetToFollow(AActor* NewTargetToFollow) { TargetToFollow = NewTargetToFollow; }
	// Setter for the player controller
	FORCEINLINE void SetPlayerController(APlayerController* NewPlayerController) { PlayerController = NewPlayerController; }
};
