// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

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
		UE_LOG(LogTemp, Warning, TEXT("PlayController possessing: %s"), *(ControlledTank->GetName()));
	}
}
