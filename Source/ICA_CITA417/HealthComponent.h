// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICA_CITA417_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDeath OnDeath;

	// Max health can be changed by a designer in unreal editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

	// Returns current health
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealth() const;

	// Apply Damage to component
	UFUNCTION(BlueprintCallable, Category = "Health")
	void ApplyDamage(float Amount);

	// Heal this component
	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float Amount);

	//Check whether the owner is still alive
	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsAlive() const;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Health")
	float CurrentHealth;
		
};
