// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

ATank* ATankPlayerController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControllerTank();

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
	UE_LOG(LogTemp, Warning, TEXT("aim"));
	// cast ray from crosshair
	// find intersection with world
	// call tank to aim at location
}
