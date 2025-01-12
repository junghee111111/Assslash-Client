// © 2020 Junghee Wang <agent474@naver.com>. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CalculateUtil.generated.h"

UCLASS(Blueprintable)
class ASSSLASH_API UCalculateUtil : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category="Util|Calculator")
	static void Calculate_ImpulseForce(int32 damageAmount, int32 attackTraceDir, int32 CON, int32 opMaxHP, double& impulseX, double& impulseZ);

	UFUNCTION(BlueprintPure, Category="Util|Calculator")
	static void Calculate_PlayerAbilityByStat(int32 STR, int32 DEX, int32 LUK, int32 SPD, int32 CON, int32& Att,
	                                          double& AttDistance, double& AttCritical, int32& AttMin, int32& AdditionalImpuse,
	                                          int32& Def, double& AttPostDelay, double& CriticalRate, double& WalkSpeed,
	                                          double& AttSpeed, int32& MaxHP);
};
