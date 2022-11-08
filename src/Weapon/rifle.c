#include "rifle.h"
#include "Game/object.h"
#include "Game/game.h"
#include "Game/camera.h"

// PSG1

extern char      aRifle_0[]; // = "rifle"
extern GM_Camera GM_Camera_800B77E8;

#pragma INCLUDE_ASM("asm/Weapon/rifle_act_helper_80067BFC.s") // 356 bytes

Actor * bullet_init_80076584(MATRIX *pMtx, int a2, int a3, int noiseLen);
void *  NewRifleSight_8006989C(short);
int     rifle_act_helper_80067BFC();

extern int       DG_CurrentGroupID_800AB968;
extern int       GM_CurrentMap_800AB9B0;
extern short     d_800AB9EC_mag_size;
extern SVECTOR   svector_800AB8D4;

extern short gGameState_800B4D98[0x60];
extern short gGcl_gameStateVars_800B44C8[0x60];

#define GM_GetWeapon(x) (&gGameState_800B4D98[0x11 + (x)])

void rifle_act_80067D60(Actor_Rifle *pActor)
{
    MATRIX mtx, mtx2;
    SVECTOR vec;

    int temp_s1;
    int temp_s2;
    int temp_v0;
    int temp_v0_2;
    short temp_a2;

    GM_CurrentMap_800AB9B0 = pActor->field_44_pCtrl->field_2C_map->field_0_map_index_bit;
    DG_GroupObjs(pActor->field_20_obj.objs, DG_CurrentGroupID_800AB968);

    if (!(pActor->field_48_pParentObj->objs->flag & DG_FLAG_INVISIBLE))
    {
        DG_VisibleObjs(pActor->field_20_obj.objs);
        GM_Camera_800B77E8.field_20 = 320;
        return;
    }

    DG_InvisibleObjs(pActor->field_20_obj.objs);

    temp_s2 = *pActor->field_50;

    if ((GM_Camera_800B77E8.field_22 == 1) && !pActor->field_5c && (temp_s2 & 1) && (pActor->field_48_pParentObj->objs->flag & DG_FLAG_INVISIBLE))
    {
        pActor->field_5c = NewRifleSight_8006989C(1);
        sd_set_cli_800887EC(0x1FFFF20, 0);
    }

    if (temp_s2 & 1)
    {
        temp_v0 = pActor->field_58;
        pActor->field_58++;

        if (temp_v0 >= 9)
        {
            temp_v0_2 = rifle_act_helper_80067BFC();
            temp_a2 = GM_Camera_800B77E8.field_20;

            if (temp_a2 < temp_v0_2)
            {
                GM_Camera_800B77E8.field_20 += GM_Camera_800B77E8.field_20 / 3;

                if (temp_v0_2 < GM_Camera_800B77E8.field_20)
                {
                    GM_Camera_800B77E8.field_20 = temp_v0_2;
                }
            }
            else
            {
                GM_Camera_800B77E8.field_20 = GV_NearExp4_800263B0(temp_a2, temp_v0_2);
            }
        }
    }

    temp_s1 = d_800AB9EC_mag_size;

    if (!temp_s1 && (temp_s2 & 2))
    {
        GM_SeSet_80032858(&pActor->field_44_pCtrl->field_0_position, 4);
        GM_SetNoise(5, 2, &pActor->field_44_pCtrl->field_0_position);
    }
    else if ((temp_s1 > 0) && (temp_s2 & 2))
    {
        vec.vx = pActor->field_44_pCtrl->field_8_rotator.vx - 0x400;
        vec.vy = pActor->field_44_pCtrl->field_8_rotator.vy;
        vec.vz = 0;

        RotMatrixYXZ_80093798(&vec, &mtx);

        DG_SetPos_8001BC44(&pActor->field_48_pParentObj->objs->objs[pActor->field_4c_numParent].world);
        DG_MovePos_8001BD20(&svector_800AB8D4);

        ReadRotMatrix_80092DD8(&mtx2);

        mtx.t[0] = mtx2.t[0];
        mtx.t[1] = mtx2.t[1];
        mtx.t[2] = mtx2.t[2];

        bullet_init_80076584(&mtx, pActor->field_54, 0, 2);

        GM_Sound_80032968(0, 63, 27);
        GM_SetNoise(100, 2, &pActor->field_44_pCtrl->field_0_position);

        d_800AB9EC_mag_size = --temp_s1;
        *GM_GetWeapon(ePSG1) -= 1;
    }
}

void rifle_kill_80068118(Actor_Rifle *rifle)
{
    GM_FreeObject_80034BF8(&rifle->field_20_obj);

    if (gGameState_800B4D98[GM_CurrentWeapon] != WEAPON_PSG1)
    {
        GM_Camera_800B77E8.field_20 = 0x140;
    }

    sd_set_cli_800887EC(0x1ffff21, 0);

    if ((Actor *)rifle->field_5c)
    {
        GV_DestroyOtherActor_800151D8((Actor *)rifle->field_5c);
    }
}

int rifle_loader_80068184(Actor_Rifle *actor_rifle, OBJECT *parent_obj, int num_parent)
{
    OBJECT *obj = &actor_rifle->field_20_obj;

    int id = GV_StrCode_80016CCC(aRifle_0);
    GM_InitObjectNoRots_800349B0((OBJECT_NO_ROTS *)obj, id, WEAPON_FLAG, 0);

    if (!obj->objs)
        return -1;

    GM_ConfigObjectRoot_80034C5C(obj, parent_obj, num_parent);
    actor_rifle->field_5c = 0;

    return 0;
}

extern char  aRifleC[]; // = "rifle.c";
extern short d_800ABA2C_ammo;

Actor_Rifle * NewRifle_80068214(GM_Control *pCtrl, OBJECT *pParentObj, int numParent, int *a4, int a5)
{
    Actor_Rifle *pActor = (Actor_Rifle *)GV_NewActor_800150E4(6, sizeof(Actor_Rifle));
    int ammo, magSize;

    if (pActor)
    {
        GV_SetNamedActor_8001514C(&pActor->field_0_actor, (TActorFunction)&rifle_act_80067D60,
                                  (TActorFunction)&rifle_kill_80068118, aRifleC);

        if (rifle_loader_80068184(pActor, pParentObj, numParent) < 0)
        {
            GV_DestroyActor_800151C8(&pActor->field_0_actor);
            return NULL;
        }

        pActor->field_44_pCtrl = pCtrl;
        pActor->field_48_pParentObj = pParentObj;
        pActor->field_4c_numParent = numParent;
        pActor->field_50 = a4;
        pActor->field_54 = a5;
        pActor->field_58 = 0;
    }

    ammo = d_800AB9EC_mag_size ? 6 : 5;
    magSize = gGameState_800B4D98[GM_WeaponRifle];

    if (ammo > 0 && ammo < magSize)
    {
        magSize = ammo;
    }

    d_800ABA2C_ammo = ammo;
    d_800AB9EC_mag_size = magSize;

    return pActor;
}
