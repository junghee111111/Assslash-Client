// © 2020 Junghee Wang <agent474@naver.com>. All rights reserved.


#include "CalculateUtil.h"

/**
 * Calculate impulse force when hit by ass
 * @param damageAmount damage taken
 * @param attackTraceDir attack trace direction (To the left or right)
 * @param impulseX return pin, X-axis force 
 * @param impulseZ return pin, Z-axis force
 */
void UCalculateUtil::Calculate_ImpulseForce(
	int32 damageAmount,int32 attackTraceDir, double& impulseX, double& impulseZ
	)
{
	impulseX = (damageAmount * 6 + 500) * attackTraceDir;
	impulseZ = (damageAmount * 8) + 300;
}

void UCalculateUtil::Calculate_PlayerAbilityByStat(
	int32 STR, int32 DEX, int32 LUK, int32 SPD, int32 CON,
	int32& Att, double& AttDistance, double& AttCritical, int32& AttMin, int32& AdditionalImpuse,
	int32& Def, double& AttPostDelay, double& CriticalRate, double& WalkSpeed, double& AttSpeed,
	int32& MaxHP
	)
{
	// 공격력
	if(STR>20){
		Att = 20 + (STR-20)*2;
	}else{
		Att = STR;
	}

	// 최소 공격력
	AttMin = (int)round(Att*(CON/100));
	if(AttMin>=Att)
	{
		AttMin = Att-1;
	}

	// 방어력
	if(STR>20)
	{
		Def = (int)round(6 + (STR)*0.8);
	} else
	{
		Def = (int)round(STR*0.6);
	}

	// 최대 HP
	MaxHP = 100 + ((STR-10)*3);

	// 크리티컬 확률
	CriticalRate = (LUK-10)/100 + 0.1;

	// 크리티컬 추가 대미지
	AttCritical = 0.5 + (LUK-10)/100;

	// 공격 거리
	AttDistance = 1 + (DEX)/200;

	// 공격 후 딜레이
	AttPostDelay = 0.4+ (0.3 - DEX/200);

	// 공격 속도 (1 ~ 2)
	AttSpeed = 0.9 + (SPD/100);
	
	// 이동 속도 (500~)
	WalkSpeed = 500 + SPD*4;

	// 추가 엉덩이 밀치기 (0~300)
	AdditionalImpuse = CON * 3;
}
