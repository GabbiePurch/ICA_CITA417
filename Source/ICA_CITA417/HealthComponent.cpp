// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	

	// Makes sure our health stays between 0 and 100
	MaxHealth = FMath::Max(0.0f, MaxHealth);
	CurrentHealth = MaxHealth;
	

}

float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

void UHealthComponent::ApplyDamage(float Amount)
{
	if (Amount <= 0.0f)
	{
		return;
	}

	bool bWasAlive = IsAlive();

	// Basically saying do the math for CurrentHealth - amount but keep it between 0 and max health
	CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.0f, MaxHealth);

	if (bWasAlive && !IsAlive())
	{
		OnDeath.Broadcast();
	}
}

void UHealthComponent::Heal(float Amount)
{
	if (Amount <= 0.0f)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.0f, MaxHealth);
}

bool UHealthComponent::IsAlive() const
{
	return CurrentHealth > 0.0f;
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

