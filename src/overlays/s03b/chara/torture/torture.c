#include "chara/snake/sna_init.h"
#include "libgcl/libgcl.h"
#include "libgv/libgv.h"
#include "Game/camera.h"
#include "Game/control.h"
#include "Game/game.h"
#include "Game/linkvarbuf.h"
#include "Game/object.h"

struct _TortureWork;
typedef void (*TTortureFn)(struct _TortureWork *, int);

typedef struct _TortureWork
{
    GV_ACT         actor;
    CONTROL        control;
    OBJECT         body;
    MOTION_CONTROL m_ctrl;
    OAR_RECORD     anims[34];
    SVECTOR        rots[16];
    SVECTOR        adjust[16];
    MATRIX         light[2];
    char           pad[0x24];
    short          f7FC;
    short          f7FE;
    short          f800;
    short          f802;
    short          f804;
    char           pad2[0x2];
    TTortureFn     f808;
    int            f80C;
    int            f810;
    int            f814;
    short          f818;
    short          f81A;
    char           pad3[0x4];
    short          f820;
    short          f822;
    SVECTOR        f824;
    SVECTOR        f82C;
    GV_PAD        *f834;
    int            f838;
    int            f83C;
    int            f840;
    int            f844;
    unsigned short f848;
    char           pad4[0x6];
    MENU_BAR_CONF  time_conf;
    unsigned short f85C;
    char           pad5[0x2];
    unsigned short f860[1];
    char           pad6[0x16];
    int            f878;
    int            f87C[8];
    short          f89C;
    short          f89E;
    short          f8A0;
    char           pad7[0x2];
    short          f8A4;
    short          f8A6;
    char           pad8[0xC];
    short          f8B4;
    short          f8B6;
    int            f8B8;
    SVECTOR        f8BC[8];
    GV_ACT        *f8FC;
    int            f900;
} TortureWork;

extern char s03b_dword_800D32F0[16];

extern int             GV_PadMask_800AB374;
extern int             GM_GameStatus_800AB3CC;
extern CONTROL        *GM_PlayerControl_800AB9F4;
extern int             GM_AlertMode_800ABA00;
extern SVECTOR         GM_PlayerPosition_800ABA10;
extern OBJECT         *GM_PlayerBody_800ABA20;
extern int             GM_PlayerStatus_800ABA50;
extern GV_PAD          GV_PadData_800B05C0[4];
extern UnkCameraStruct gUnkCameraStruct_800B77B8;
extern GM_Camera       GM_Camera_800B77E8;

extern const char s03b_dword_800D2E5C[];
extern const char s03b_aTurn_800D2E64[];
extern const char s03b_aLeave_800D2E6C[];
extern const char s03b_dword_800D2E74[];
extern const char s03b_dword_800D2E80[];
extern const char s03b_aTime_800D2E8C[];

GV_ACT * NewFadeIo_800C4224(int name, int where);

void InfoKill_800CA5D0(void);

void s03b_boxall_800C9328(void);
void s03b_boxall_800C9404(void);
void s03b_boxall_800C96E8(void);

void s03b_torture_800C5E48(TortureWork *work, int);

#define EXEC_LEVEL 5

void s03b_torture_800C3E80(TortureWork *work)
{
    int index;

    index = work->f80C;
    work->f80C++;
    work->f808(work, index);
}

void s03b_torture_800C3EB8(TortureWork *work)
{
    int f802;
    int index;

    f802 = work->f802;
    if (f802 & 0x2)
    {
        index = work->f810;
        work->f810++;
        s03b_torture_800C5E48(work, index);
    }
}

void s03b_torture_800C3EF8(TortureWork *work)
{
    if (work->f814 == 0)
    {
        return;
    }

    if (work->f814 > 0)
    {
        if (GM_Camera_800B77E8.field_22 == 0 && --work->f814 == 0)
        {
            DG_VisibleObjs(work->body.objs);
        }
    }
    else
    {
        if (GM_Camera_800B77E8.field_22 != 0 && ++work->f814 == 0)
        {
            DG_InvisibleObjs(work->body.objs);
        }
    }
}

int s03b_torture_800C3F7C(GV_PAD *pad)
{
    char *analog;
    int   i;
    char  adjust;

    if (pad->analog == 0)
    {
        return 0;
    }

    if ((pad->status & (PAD_LEFT | PAD_DOWN | PAD_RIGHT | PAD_UP)) == 0)
    {
        return 0;
    }

    analog = &pad->right_dx;
    for (i = 0; i < 4; i++)
    {
        adjust = *analog - 64;
        if (adjust > 128)
        {
            return 1;
        }

        analog++;
    }

    return 0;
}

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C3FE4.s")
void s03b_torture_800C3FE4(TortureWork *work);

void s03b_torture_800C421C(TortureWork *work)
{
    work->f800 |= 0x1;

    if (GM_Camera_800B77E8.field_22 <= 0)
    {
        GM_Camera_800B77E8.field_22 = 1;
        work->f814 = -4;
    }
    else
    {
        work->f814 = -1;
    }
}

void s03b_torture_800C4260(TortureWork *work)
{
    work->f800 &= ~0x1;
    GM_Camera_800B77E8.field_22 = 0;
    work->f814 = 4;
}

void s03b_torture_800C4284(TortureWork *work)
{
    int f802;
    int f800;

    f802 = work->f802;
    if ((f802 & 0x2000) || (((f802 & 0x1) == 0) && (work->f834->status & PAD_TRIANGLE)))
    {
        f800 = work->f800;
        if ((f800 & 0x1) == 0)
        {
            s03b_torture_800C421C(work);
        }
    }
    else
    {
        f800 = work->f800;
        if (f800 & 0x1)
        {
            s03b_torture_800C4260(work);
        }
    }
}

int s03b_torture_800C4314(TortureWork *work)
{
    int f800;

    f800 = work->f800;
    if ((f800 & 0x4) || (work->f834->press & PAD_SELECT) == 0)
    {
        return 0;
    }

    work->f7FC = 6;
    work->f7FE = 0;
    return 1;
}

void s03b_torture_800C435C(TortureWork *work, int vx)
{
    GV_MSG msg;
    int    f802;

    f802 = work->f802;
    if (f802 & 0x8)
    {
        msg.address = GV_StrCode_80016CCC(s03b_dword_800D2E5C);
        msg.message_len = 2;
        msg.message[0] = GV_StrCode_80016CCC(s03b_aTurn_800D2E64);

        if (abs(vx) >= 2048)
        {
            msg.message[1] = work->control.field_8_rot.vx;
        }
        else
        {
            msg.message[1] = vx;
        }

        GV_SendMessage_80016504(&msg);
    }
}

void s03b_torture_800C43F0(void)
{
    GV_MSG msg;

    msg.address = GV_StrCode_80016CCC(s03b_dword_800D2E5C);
    msg.message_len = 1;
    msg.message[0] = GV_StrCode_80016CCC(s03b_aLeave_800D2E6C);

    GV_SendMessage_80016504(&msg);
}

void s03b_torture_800C4438(TortureWork *work, int message)
{
    GV_MSG msg;

    msg.address = GV_StrCode_80016CCC(s03b_dword_800D2E74);
    msg.message_len = 1;
    msg.message[0] = message;

    GV_SendMessage_80016504(&msg);
}

void s03b_torture_800C447C(TortureWork *work, int arg1, int arg2)
{
    GV_MSG msg;

    msg.address = GV_StrCode_80016CCC(s03b_dword_800D2E80);
    msg.message_len = 2;
    msg.message[0] = arg1;
    msg.message[1] = arg2;

    GV_SendMessage_80016504(&msg);
}

void s03b_torture_800C44D0(TortureWork *work, int arg1, int arg2)
{
    int max, now;

    max = work->f860[work->f85C];

    if (arg2 < 0)
    {
        now = arg1 * 4;

        if (now > max)
        {
            now = max;
        }

        max = now;
    }
    else if (arg2 == 0)
    {
        now = max - arg1;

        if (max == now)
        {
            now = max - 1;
        }
    }
    else
    {
        now = 0;
    }

    max *= 5;
    now *= 5;

    if (max > 1024)
    {
        work->time_conf.field_7_rgb_right[1] = (0x10000 / max) + 63;
        work->time_conf.field_7_rgb_right[2] = (0xFC00 / max) - 64;
    }

    menu_DrawBar2_80038DE0(28, now, now, max, &work->time_conf);
}

int s03b_torture_800C45E4(TortureWork *work)
{
    MENU_BAR_CONF *conf;

    memcpy(s03b_dword_800D32F0, s03b_aTime_800D2E8C, 5);

    conf = &work->time_conf;
    conf->field_0_text = s03b_dword_800D32F0;

    conf->field_4_rgb_left[0] = 31;
    conf->field_4_rgb_left[1] = 63;
    conf->field_4_rgb_left[2] = 192;

    conf->field_7_rgb_right[0] = 31;
    conf->field_7_rgb_right[1] = 127;
    conf->field_7_rgb_right[2] = 255;

    conf->field_A_bar_height = 1;
    return 0;
}

void s03b_torture_800C4654(TortureWork *work)
{
    int     n_msgs;
    GV_MSG *msg;

    if (work->control.field_56 == 0)
    {
        return;
    }

    n_msgs = work->control.field_56;
    msg = &work->control.field_5C_mesg[n_msgs] - 1;

    for (; n_msgs > 0; n_msgs--, msg--)
    {
        if (msg->message[0] == 4)
        {
            work->f802 |= 0x4;
        }
    }
}

void s03b_torture_800C46B8(TortureWork *work, int arg1)
{
    if (arg1 == 0)
    {
        NewFadeIo_800C4224(0, 28);
        s03b_boxall_800C9328();

        work->f820 = 0;

        if (work->f8FC != NULL)
        {
            GV_DestroyOtherActor_800151D8(work->f8FC);
        }

        work->f8FC = NULL;
    }

    if (arg1 == 32)
    {
        GM_Camera_800B77E8.field_22 = 0;

        if (work->f83C >= 0)
        {
            GCL_ExecProc_8001FF2C(work->f83C, NULL);
        }
    }
}

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C4740.s")
void s03b_torture_800C4740(TortureWork *work);

void s03b_torture_800C4A08(TortureWork *work)
{
    if (work->f848 == 0)
    {
        s03b_torture_800C4740(work);
    }
    else if (++work->f81A == 90)
    {
        work->f802 |= 0x4;
    }
}

void s03b_torture_800C4A70(TortureWork *work)
{
    s03b_torture_800C4654(work);
}

void s03b_torture_800C4A90(TortureWork *work)
{
    s03b_torture_800C4A70(work);
}

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C4AB0.s")
void s03b_torture_800C4AB0(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C4C48.s")
#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C4DF0.s")
void s03b_torture_800C4DF0(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C4E64.s")
void s03b_torture_800C4E64(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C4F54.s")
void s03b_torture_800C4F54(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C50A8.s")
void s03b_torture_800C50A8(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C53C8.s")
void s03b_torture_800C53C8(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C5420.s")
void s03b_torture_800C5420(TortureWork *work, int);

#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C59FC.s")
#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C5AF8.s")
#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C5CC8.s")
#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C5E48.s")
#pragma INCLUDE_ASM("asm/overlays/s03b/s03b_torture_800C5EC4.s")
void s03b_torture_800C5EC4(TortureWork *work);


void s03b_torture_800C6024(TortureWork *work)
{
    int f802;

    if (work->f7FE == 0)
    {
        work->f808 = s03b_torture_800C4DF0;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
        work->f802 |= 0x8;
    }

    f802 = work->f802;
    if (f802 & 0x4)
    {
        work->f802 &= ~0x4;
        work->f7FC = 1;
        work->f7FE = 0;
    }
}

void s03b_torture_800C6080(TortureWork *work)
{
    int comp;

    if (work->f7FE < 2)
    {
        if (work->f8FC)
        {
            GV_DestroyOtherActor_800151D8(work->f8FC);
            work->f8FC = NULL;
        }

        work->f808 = s03b_torture_800C4E64;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
        work->f802 |= 0x8;
    }

    if (work->f848 == 0 && work->f7FE == 120)
    {
        NewFadeIo_800C4224(0, 28);
    }

    comp = (work->f848 == 0) ? 150 : 180;
    if (work->f7FE == comp)
    {
        if (work->f848 == 0 && work->f83C >= 0)
        {
            GM_Camera_800B77E8.field_22 = 0;
            GCL_ExecProc_8001FF2C(work->f83C, NULL);
            GV_DestroyActor_800151C8(&work->actor);
            GM_GameStatus_800AB3CC &= ~GAME_FLAG_BIT_30;
        }
        else
        {
            work->f7FC = 2;
            work->f7FE = 0;
            work->f802 &= ~0x8;
        }
    }
}

void s03b_torture_800C61A4(TortureWork *work)
{
    int f802;

    if (work->f7FE < 2)
    {
        work->f808 = s03b_torture_800C4F54;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
        work->f802 |= 0x8;
    }

    f802 = work->f802;
    if (f802 & 4)
    {
        work->f802 &= ~0xC;
        work->f7FC = 7;
        work->f7FE = 0;
    }
}

void s03b_torture_800C6204(TortureWork *work)
{
    int f802;

    if (work->f7FE < 2)
    {
        s03b_torture_800C43F0();
        work->f808 = s03b_torture_800C50A8;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
        GM_GameStatus_800AB3CC |= GAME_FLAG_BIT_30;
    }

    f802 = work->f802;
    if (f802 & 0x4)
    {
        work->f802 &= ~0x4;

        GM_GameStatus_800AB3CC &= ~GAME_FLAG_BIT_30;
        GM_GameStatus_800AB3CC &= ~GAME_FLAG_BIT_29;

        if (work->f83C >= 0)
        {
            GCL_ExecProc_8001FF2C(work->f83C, NULL);
            GV_DestroyActor_800151C8(&work->actor);
        }
    }
}

void s03b_torture_800C62C4(TortureWork *work)
{
    int f802;

    if (work->f7FE < 2)
    {
        work->f808 = s03b_torture_800C53C8;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
        GM_GameStatus_800AB3CC |= GAME_FLAG_BIT_30;
    }

    if (work->f7FE == 0x1E)
    {
        s03b_torture_800C4260(work);
    }

    f802 = work->f802;
    if (f802 & 0x4)
    {
        work->f802 &= ~0x4;
        work->f7FC = 3;
        work->f7FE = 0;
        GM_GameStatus_800AB3CC &= ~GAME_FLAG_BIT_29;
        GM_GameStatus_800AB3CC &= ~GAME_FLAG_BIT_30;
    }
}

void Torture_800C6380(TortureWork *work)
{
    int f802;

    if (work->f7FE < 2)
    {
        work->f808 = s03b_torture_800C5420;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
    }

    if (!s03b_torture_800C4314(work))
    {
        f802 = work->f802;
        if (f802 & 0x4)
        {
            work->f802 &= ~0x4;
            work->f820 = 0;
            work->f7FC = 5;
            work->f7FE = 0;
        }
    }
}

void Torture_800C6400(TortureWork *work)
{
    int f802;

    if (work->f7FE < 2)
    {
        InfoKill_800CA5D0();
        work->f808 = s03b_torture_800C4AB0;
        work->f81A = 0;
        work->f818 = 0;
        work->f80C = 0;
        GM_GameStatus_800AB3CC |= STATE_PADRELEASE | GAME_FLAG_BIT_18;
        work->f802 |= 0x8;
    }

    f802 = work->f802;
    if (f802 & 0x4)
    {
        work->f7FC = 7;
        work->f7FE = 0;
        work->f83C = work->f838;
        work->f802 &= ~0xC;
        GM_GameStatus_800AB3CC &= ~STATE_PADRELEASE;
    }
}

void Torture_800C64BC(TortureWork *work)
{
    s03b_torture_800C5EC4(work);

    switch (work->f7FC)
    {
    case 0:
        s03b_torture_800C6024(work);
        break;

    case 1:
        s03b_torture_800C6080(work);
        break;

    case 2:
        s03b_torture_800C62C4(work);
        break;

    case 3:
        Torture_800C6380(work);

        if (work->f7FC == 6)
        {
            work->f7FE = 1;
            work->f802 &= ~0x4;
            goto next;
        }
        break;

    case 4:
        break;

    case 5:
        s03b_torture_800C61A4(work);
        break;

    case 6:
next:
        Torture_800C6400(work);
        break;

    case 7:
        s03b_torture_800C6204(work);
        break;
    }

    if (work->f7FE < 16000)
    {
        work->f7FE++;
    }

    s03b_boxall_800C9404();

    sna_act_helper2_helper2_80033054(GV_StrCode_80016CCC("スネーク"), &work->adjust[6]);

    s03b_torture_800C435C(work, 4000);
    s03b_torture_800C3EF8(work);
    s03b_torture_800C3E80(work);
    s03b_torture_800C3EB8(work);
    s03b_torture_800C4284(work);
    s03b_torture_800C3FE4(work);
}

void TortureAct_800C6600(TortureWork *work)
{
    UnkCameraStruct *cam;
    int              f800;

    GV_PadMask_800AB374 &= ~0x800;
    GM_GameStatus_800AB3CC |= GAME_FLAG_BIT_28;

    GM_ActMotion_80034A7C(&work->body);

    work->control.field_0_mov.vy += work->body.field_18 - work->control.field_32_height;


    GM_ActControl_80025A7C(&work->control);
    GM_ActObject_80034AF4(&work->body);

    DG_GetLightMatrix_8001A3C4(&work->control.field_0_mov, work->light);

    GM_PlayerPosition_800ABA10 = work->control.field_0_mov;

    cam = &gUnkCameraStruct_800B77B8;
    cam->field_0.vx = work->body.objs->objs[6].world.t[0];
    cam->field_0.vy = work->body.objs->objs[6].world.t[1];
    cam->field_0.vz = work->body.objs->objs[6].world.t[2];

    GM_SnakeCurrentHealth = (work->f804 > 0) ? work->f804 : 0;

    work->control.field_32_height = work->body.field_18;

    Torture_800C64BC(work);

    f800 = work->f800;
    if (f800 & 0x1)
    {
        GV_NearExp2PV_80026924((short *)&cam->field_28, (short *)&work->f82C, 3);
    }
    else
    {
        cam->field_28 = work->control.field_8_rot;
    }
}

void TortureDie_800C6774(TortureWork *work)
{
    GM_FreeControl_800260CC(&work->control);
    GM_FreeObject_80034BF8(&work->body);

    GM_PlayerStatus_800ABA50 &= ~PLAYER_PREVENT_WEAPON_ITEM_SWITCH;

    s03b_boxall_800C96E8();
    s03b_boxall_800C9328();

    GM_SnakeCurrentHealth = GM_SnakeMaxHealth;

    if (GM_PlayerControl_800AB9F4 == &work->control)
    {
        GM_PlayerControl_800AB9F4 = NULL;
    }

    if (GM_PlayerBody_800ABA20 == &work->body)
    {
        GM_PlayerBody_800ABA20 = NULL;
    }
}

void Torture_800C6814(TortureWork *work)
{
    int   params[7];
    int  *iter;
    char *res;

    if (!GCL_GetOption_80020968('b'))
    {
        return;
    }

    iter = params;
    while ((res = GCL_Get_Param_Result_80020AA4()))
    {
        *iter++ = GCL_StrToInt_800209E8(res);
    }

    work->f89C = params[1];
    work->f89E = params[2];
    work->f8A0 = params[0];
    work->f8A4 = params[3];
    work->f8A6 = params[4];
    work->f8B4 = params[5];
    work->f8B6 = params[6];

    if (GCL_GetOption_80020968('z'))
    {
        work->f844 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }
    else
    {
        work->f844 = -1;
    }
}

void Torture_800C68E8(TortureWork *work)
{
    int      count;
    SVECTOR *iter;

    if (!GCL_GetOption_80020968('x'))
    {
        return;
    }

    count = 0;
    iter = work->f8BC;
    while (GCL_Get_Param_Result_80020AA4())
    {
        GCL_StrToSV_80020A14(GCL_Get_Param_Result_80020AA4(), iter);
        iter++;
        count++;
    }

    work->f8B8 = count;
}

void Torture_800C695C(TortureWork *work)
{
    char *opt;

    work->f7FE = 0;
    work->f800 = 0;
    work->f802 = 0;
    work->f804 = GM_SnakeMaxHealth;
    work->f810 = 0;
    work->f814 = 0;
    work->f81A = 0;
    work->f818 = 0;
    work->f822 = 0;
    work->f820 = 0;
    work->f824 = work->control.field_0_mov;
    work->f834 = &GV_PadData_800B05C0[2];
    work->f82C = work->control.field_8_rot;
    work->f8FC = NULL;
    work->f900 = 0;

    opt = (char *)GCL_GetOption_80020968('m');
    if (opt != NULL)
    {
        work->f7FC = GCL_StrToInt_800209E8(opt);
    }
    else
    {
        work->f7FC = 0;
    }

    if (work->f7FC < 2)
    {
        GM_Camera_800B77E8.field_22 = 2;
        work->f802 |= 0x2000;
    }
    else
    {
        GM_Camera_800B77E8.field_22 = 0;
    }

    opt = (char *)GCL_GetOption_80020968('c');
    if (opt != NULL)
    {
        work->f848 = GCL_StrToInt_800209E8(opt);
    }
    else
    {
        work->f848 = 0;
    }

    opt = (char *)GCL_GetOption_80020968('f');
    if (opt != NULL && GCL_StrToInt_800209E8(opt) != 0)
    {
        work->f802 |= 0x80;
    }
}

void Torture_800C6AB0(TortureWork *work)
{
    int   count;
    int  *iter;
    char *res;

    if (GCL_GetOption_80020968('v'))
    {
        count = 0;
        iter = work->f87C;
        while ((res = GCL_Get_Param_Result_80020AA4()))
        {
            if (count == 8)
            {
                break;
            }

            *iter++ = GCL_StrToInt_800209E8(res);
            count++;
        }

        work->f878 = count;
    }
    else
    {
        work->f878 = 0;
    }
}

int TortureGetResources_800C6B3C(TortureWork *work, int name, int map)
{
    CONTROL *control;
    char    *pos;
    char    *dir;
    OBJECT  *body;
    int      model;
    int      motion;
    int      oar;
    int      proc;

    control = &work->control;
    if (GM_InitLoader_8002599C(control, name, map) < 0)
    {
        return -1;
    }

    pos = (char *)GCL_GetOption_80020968('p');
    dir = (char *)GCL_GetOption_80020968('d');
    GM_ConfigControlString_800261C0(control, pos, dir);

    GM_ConfigControlHazard_8002622C(control, control->field_0_mov.vy, -2, -2);
    GM_ConfigControlAttribute_8002623C(control, RADAR_VISIBLE);

    body = &work->body;

    model = GV_StrCode_80016CCC("sne_nude");
    motion = GV_StrCode_80016CCC("sne_03b");
    GM_InitObject_80034A18(body, model, BODY_FLAG2, motion);
    GM_ConfigObjectJoint_80034CB4(body);

    oar = GV_StrCode_80016CCC("sne_03b");
    GM_ConfigMotionControl_80034F08(body, &work->m_ctrl, oar, &work->anims[0], &work->anims[17], control, work->rots);
    GM_ConfigMotionAdjust_80035008(body, work->adjust);
    GM_ConfigObjectLight_80034C44(body, work->light);
    GM_ConfigObjectAction_80034CD4(body, 0, 0, 0);

    if (GCL_GetOption_80020968('e'))
    {
        work->f83C = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }
    else
    {
        work->f83C = -1;
    }

    if (GCL_GetOption_80020968('s'))
    {
        work->f838 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }
    else
    {
        work->f838 = -1;
    }

    if (GCL_GetOption_80020968('a'))
    {
        work->f840 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }
    else
    {
        work->f840 = -1;
    }

    Torture_800C68E8(work);
    Torture_800C6814(work);
    Torture_800C6AB0(work);
    s03b_torture_800C45E4(work);
    Torture_800C695C(work);

    GM_PlayerControl_800AB9F4 = control;
    GM_PlayerBody_800ABA20 = body;

    gUnkCameraStruct_800B77B8.field_28 = control->field_8_rot;
    gUnkCameraStruct_800B77B8.field_0 = control->field_0_mov;

    work->body.objs->objs[6].world.t[0] = gUnkCameraStruct_800B77B8.field_0.vx;
    work->body.objs->objs[6].world.t[1] = gUnkCameraStruct_800B77B8.field_0.vy;
    work->body.objs->objs[6].world.t[2] = gUnkCameraStruct_800B77B8.field_0.vz;

    GM_AlertMode_800ABA00 = 10;
    GM_PlayerStatus_800ABA50 |= PLAYER_PREVENT_WEAPON_ITEM_SWITCH;

    s03b_boxall_800C9328();

    GM_ActMotion_80034A7C(body);

    work->control.field_32_height = work->body.field_18;

    GM_ActControl_80025A7C(control);
    GM_ActObject_80034AF4(body);

    proc = GCL_StrToInt_800209E8((char *)GCL_GetOption_80020968('n'));
    GCL_ExecProc_8001FF2C(proc, NULL);

    GV_PadMask_800AB374 = ~0x810;
    GM_GameStatus_800AB3CC |= GAME_FLAG_BIT_28;

    return 0;
}

GV_ACT * NewTorture_800C6E1C(int name, int where)
{
    TortureWork *work;

    work = (TortureWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(TortureWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)TortureAct_800C6600, (TActorFunction)TortureDie_800C6774, "torture.c");

        if (TortureGetResources_800C6B3C(work, name, where) >= 0)
        {
            return &work->actor;
        }

        GV_DestroyActor_800151C8(&work->actor);
    }

    return NULL;
}
