  // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"
#include "Weapon.generated.h"



/**
 * 
 */
class UBoxComponent;

UCLASS()
class SLASH_API AWeapon : public AItemBase
{
	GENERATED_BODY()

public:
	AWeapon();
	void AttachToSocket(USceneComponent* Parent, FName SocketName);
	void Equip(USceneComponent* Parent, FName SocketName, AActor* NewOwner, APawn* NewInstigator);
	TArray<AActor*> IgnoreActors;
protected:
	virtual void BeginPlay() override;
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	bool ActorIsSameType(AActor* OtherActor);

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
								 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon Props")
	UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;
	
	UPROPERTY(EditAnywhere)
	float Damage = 20.f;

	void ExecuteGetHit(FHitResult& BoxHit);

public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }
};
