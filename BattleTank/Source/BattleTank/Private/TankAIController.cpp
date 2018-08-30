// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing pawn: %s"), *(GetPawn()->GetName()));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("AI Controller %s is not possessing any tank!"), *(GetOwner()->GetName()));
	}
	
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller pawn: %s"), *(PlayerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Player tank NOT found!"));
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


