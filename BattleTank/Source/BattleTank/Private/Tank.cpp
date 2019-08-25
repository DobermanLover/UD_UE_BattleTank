// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
//#include "TankMovementComponent.h"
//#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: C++ Begin Play"), *OurTankName);

	//TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

/*void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *OurTankName,*HitLocation.ToString());
}*/



