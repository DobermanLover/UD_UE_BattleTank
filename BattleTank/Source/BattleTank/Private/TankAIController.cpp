// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
//#include "TankPlayerController.h"


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn= GetWorld()->GetFirstPlayerController()->GetPawn();
	//return nullptr;
	if (PlayerPawn == nullptr)
	{
		//UE_LOG(LogTemp, Error, TEXT("AIPlayerController is not finding player controlled tank"));
		return nullptr;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AIPlayerController found on: %s"), *(PlayerPawn->GetName()));
		return Cast<ATank>(PlayerPawn);
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	auto PlayerTank = GetPlayerTank();

	///adding code to log problems with possessing a tank
	if (AIControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController found on: %s"), *(AIControlledTank->GetName()));
	}

	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController can't find a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController found a tank on: %s"), *(PlayerTank->GetName()));
	}
}




