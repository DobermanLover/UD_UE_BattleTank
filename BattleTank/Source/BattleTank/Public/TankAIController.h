// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//Forward declarations
//class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Setup")
		float AcceptanceRadius = 300000.0;

private:
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
