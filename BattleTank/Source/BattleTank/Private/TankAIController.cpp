// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
//#include "Tank.h"
//#include "TankPlayerController.h"


/*ATank* ATankAIController::GetAIControlledTank() const
{
	
}*/

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	//return nullptr;
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check units are cm

		// Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//ControlledTank->Fire(); // TODO don't fire every frame
	

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}






