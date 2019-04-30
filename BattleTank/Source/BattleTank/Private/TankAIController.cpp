// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
//#include "TankPlayerController.h"


/*ATank* ATankAIController::GetAIControlledTank() const
{
	
}*/

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//return nullptr;
	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO don't fire every frame
	}

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}






