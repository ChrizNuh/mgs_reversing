#ifndef _HOMING_TARGET_H_
#define _HOMING_TARGET_H_

#include <SYS/TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>
#include "Game/control.h"

typedef struct Homing_Target
{
    MATRIX     *field_0;       // ptr
    CONTROL *field_4;       // ptr
    int         flag;       // alive
    int         field_C_bUsed; // auto_aimable
} Homing_Target;

void HomingTarget_2_80032EAC(MATRIX *pMtx, int vecY, int *pRetY, int *pRetX, int mapBit, int max_dist, int min_angle);
void HomingTarget_Clear_All_80032C68();
void HomingTarget_Free_80032CFC(Homing_Target *pTarget);
Homing_Target *HomingTarget_Alloc_80032C8C(MATRIX *a1, CONTROL *a2);

#endif // _HOMING_TARGET_H_
