// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.h"
#include "BattleTank.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possessing any tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayController possessing: %s"), *(ControlledTank->GetName()) );
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // out parameter
	
	if (GetSightRayHitLocation(OutHitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
		// tell controlled tank to aim at point
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No HitLocation to terrain!"));
	}

	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find crosshair position in screen space pixel coords
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// deproject the screen position of the crosshair to a world direction

	// line-trace along that look direction, and see what we hit (up to max range)

	return true;
}
