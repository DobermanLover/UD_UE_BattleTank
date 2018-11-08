// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();

	///adding code to log problems with possessing a tank
	if (AIControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("AIPlayerController possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController found on: %s"), *(AIControlledTank->GetName()));
	}

}




