// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO should this tick?

	// ...
}
	

void UTankAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

/*void ATank::AimAt(FVector HitLocation)
{
if (!ensure(TankAimingComponent)) { return; }

TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
//auto OurTankName = GetName();
//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *OurTankName,*HitLocation.ToString());
}*/


void UTankAimingComponent::AimAt(FVector HitLocation)
{
	/*auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();*/

	if (!ensure(Barrel))
	{
		return;
	}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//FVector EndLocation = GetOwner()->GetName	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution) 
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();		
		MoveBarrelTowards(AimDirection);		
	}

	//if no solution do nothing
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

	Barrel->Elevate(DeltaRotator.Pitch); // TODO remove literal value
	Turret->Rotate(DeltaRotator.Yaw);
}



