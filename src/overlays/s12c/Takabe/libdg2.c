#include "libdg/libdg.h"
#include "libgcl/libgcl.h"

// Modified versions of functions from libdg

#define SCRPAD_ADDR 0x1F800000

extern int s12c_dword_800DA414;
extern int s12c_dword_800DA418;
extern int s12c_dword_800DA41C;
extern int s12c_dword_800DA420;
extern int s12c_dword_800DA424;
extern int s12c_800DA428;
extern int s12c_800DA42C;
extern int s12c_800DA430;
extern int s12c_800DA434;

short SECTION("overlay.bss")  s12c_800DA440[768];
short SECTION("overlay.bss") *s12c_800DAA40;
short SECTION("overlay.bss") *s12c_800DAA44;
short SECTION("overlay.bss") *s12c_800DAA48;
short SECTION("overlay.bss") *s12c_800DAA4C;

extern int           GV_Clock_800AB920;
extern int           GM_GameStatus_800AB3CC;
extern int           GV_PauseLevel_800AB928;
extern int           DG_CurrentGroupID_800AB968;
extern unsigned int *ptr_800B1400[256];
extern short         DG_ClipMin_800AB96C[2];
extern short         DG_ClipMax_800AB970[2];

void s12c_800D497C(int arg0, int arg1)
{
    short *iter;
    int    i;

    s12c_800DAA40 = s12c_800DA440;
    s12c_800DAA44 = s12c_800DA440 + 256;
    s12c_800DAA48 = s12c_800DA440 + 512;

    s12c_800DA428 = arg0;
    s12c_800DA434 = arg1;
    s12c_800DA42C = arg1;
    s12c_800DA430 = arg0 + arg1;

    iter = s12c_800DAA44;
    for (i = s12c_800DA428; i < s12c_800DA430; i++)
    {
        *iter++ = ((i - s12c_800DA428) * 4096) / s12c_800DA434;
    }

    for (i = 255 - s12c_800DA434; i > 0; i--)
    {
        *iter++ = 4096;
    }

    iter = s12c_800DAA40;
    for (i = 256; i > 0; i--)
    {
        *iter++ = 0;
    }

    iter = s12c_800DAA48;
    for (i = 256; i > 0; i--)
    {
        *iter++ = 4096;
    }

    s12c_800DAA4C = s12c_800DAA44 - arg0;
}

void s12c_800D4AB4(int scale)
{
    if (scale > 255)
    {
        scale = 255;
    }

    s12c_800DA428 = scale;

    if ((scale + s12c_800DA42C) > 255)
    {
        s12c_800DA434 = 255 - scale;
    }
    else
    {
        s12c_800DA434 = s12c_800DA42C;
    }

    s12c_800DA430 = scale + s12c_800DA434;
    s12c_800DAA4C = s12c_800DAA44 - scale;
}

typedef struct _SCRATCHPAD_UNK
{
    unsigned int **buf;
    unsigned int *ot;
    int len;
    int unkC;
    int unk10;
    int unk14;
    void *unk18;
    short *unk1C;
} SCRATCHPAD_UNK;

// TODO: fix this
#define gte_ldrgb_s0(r0) __asm__ volatile("lwc2   $6,  4( %0 )" : : "r"(r0))
#define gte_ldrgb_s1(r0) __asm__ volatile("lwc2   $6, 12( %0 )" : : "r"(r0))
#define gte_ldrgb_s2(r0) __asm__ volatile("lwc2   $6, 20( %0 )" : : "r"(r0))
#define gte_ldrgb_s3(r0) __asm__ volatile("lwc2   $6, 28( %0 )" : : "r"(r0))

#define gte_ldrgb_f0(r0) __asm__ volatile("lwc2   $22,  4( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb_f1(r0) __asm__ volatile("lwc2   $20, 12( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb_f2(r0) __asm__ volatile("lwc2   $21, 20( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb_f3(r0) __asm__ volatile("lwc2   $22, 28( %0 )" : : "r"(r0) : "memory")

#define gte_ldrgb_f1_t(r0) __asm__ volatile("lwc2   $20, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb_f2_t(r0) __asm__ volatile("lwc2   $21, 28( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb_f3_t(r0) __asm__ volatile("lwc2   $22, 40( %0 )" : : "r"(r0) : "memory")

#define gte_strgb_s2_t(r0) __asm__ volatile("swc2   $20, 16( %0 );" "swc2   $21, 28( %0 )" : : "r"(r0) : "memory")
#define gte_strgb_s3_t(r0) __asm__ volatile("swc2   $20, 16( %0 );" "swc2   $21, 28( %0 );" "swc2   $22, 40( %0 )" : : "r"(r0) : "memory")

#define gte_strgb_s0(r0) __asm__ volatile("swc2   $22,  4( %0 )" : : "r"(r0) : "memory")
#define gte_strgb_s1(r0) __asm__ volatile("swc2   $22, 12( %0 )" : : "r"(r0) : "memory")
#define gte_strgb_s2(r0) __asm__ volatile("swc2   $20, 12( %0 );" "swc2   $21, 20( %0 )" : : "r"(r0) : "memory")
#define gte_strgb_s3(r0) __asm__ volatile("swc2   $20, 12( %0 );" "swc2   $21, 20( %0 );" "swc2   $22, 28( %0 )" : : "r"(r0) : "memory")


void s12c_800D4B2C(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
}

void s12c_800D4B34(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
    gte_strgb_s0(scratch->unk18);
    gte_lddp(p);
    gte_ldrgb_s0(buffer);
    scratch->unk18 = buffer;
    gte_dpcs_b();
}

void s12c_800D4B5C(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
    int color;

    gte_strgb_s0(scratch->unk18);
    gte_lddp(p);
    gte_ldrgb_s1(buffer);
    scratch->unk18 = buffer;
    gte_nop();
    gte_dpcs();
    color = LLOAD(&buffer->r0);
    gte_strgb_s1(buffer);
    gte_ldrgb(color);
    gte_dpcs();
}

void s12c_800D4BA4(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
    int color;

    gte_strgb_s0(scratch->unk18);
    gte_lddp(p);
    gte_ldrgb_f1(buffer);
    gte_ldrgb_f2(buffer);
    scratch->unk18 = buffer;
    gte_nop();
    gte_dpct();
    color = LLOAD(&buffer->r0);
    gte_strgb_s2(buffer);
    gte_ldrgb(color);
    gte_dpcs();
}

void s12c_800D4BF4(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
    int color;

    gte_strgb_s0(scratch->unk18);
    gte_lddp(p);
    gte_ldrgb_f1(buffer);
    gte_ldrgb_f2(buffer);
    gte_ldrgb_f3(buffer);
    scratch->unk18 = buffer;
    gte_nop();
    gte_dpct();
    color = LLOAD(&buffer->r0);
    gte_strgb_s3(buffer);
    gte_ldrgb(color);
    gte_dpcs();
}

void s12c_800D4C4C(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
    int color;

    gte_strgb_s0(scratch->unk18);
    gte_lddp(p);
    gte_ldrgb_f1_t(buffer);
    gte_ldrgb_f2_t(buffer);
    scratch->unk18 = buffer;
    gte_nop();
    gte_dpct();
    color = LLOAD(&buffer->r0);
    gte_strgb_s2_t(buffer);
    gte_ldrgb(color);
    gte_dpcs();
}

void s12c_800D4C9C(SCRATCHPAD_UNK *scratch, P_TAG *buffer, int p)
{
    int color;

    gte_strgb_s0(scratch->unk18);
    gte_lddp(p);
    gte_ldrgb_f1_t(buffer);
    gte_ldrgb_f2_t(buffer);
    gte_ldrgb_f3_t(buffer);
    scratch->unk18 = buffer;
    gte_nop();
    gte_dpct();
    color = LLOAD(&buffer->r0);
    gte_strgb_s3_t(buffer);
    gte_ldrgb(color);
    gte_dpcs();
}

void *fog_prim_funcs_800C347C[] = {
    s12c_800D4B2C, // LINE_F2
    s12c_800D4B34, // LINE_F3
    s12c_800D4B34, // LINE_F4
    s12c_800D4B34, // LINE_G2
    s12c_800D4B5C, // LINE_G3
    s12c_800D4BA4, // LINE_G4
    s12c_800D4BF4, // SPRT
    s12c_800D4B34, // SPRT_16
    s12c_800D4B34, // SPRT_8
    s12c_800D4B34, // TILE
    s12c_800D4B34, // TILE_16
    s12c_800D4B34, // TILE_8
    s12c_800D4B34, // TILE_1
    s12c_800D4B34, // POLY_F3
    s12c_800D4B34, // POLY_F4
    s12c_800D4B34, // POLY_G3
    s12c_800D4BA4, // POLY_G4
    s12c_800D4BF4, // POLY_FT3
    s12c_800D4B34, // POLY_FT4
    s12c_800D4B34, // POLY_GT3
    s12c_800D4C4C, // POLY_GT4
    s12c_800D4C9C,
    s12c_800D4B2C,
    s12c_800D4B2C,
    s12c_800D4B2C,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

static inline SCRATCHPAD_UNK * get_scratch(void)
{
    return (SCRATCHPAD_UNK *)0x1f800000;
}

void s12c_800D4CF4(unsigned int *ot)
{
    SCRATCHPAD_UNK *scratch;
    unsigned int **buf;
    int            i;
    unsigned int  *tag;
    unsigned int   val;
    unsigned int  *next;

    scratch = get_scratch();
    scratch->unkC = s12c_800DA428;
    scratch->unk10 = s12c_800DA430;
    scratch->unk14 = s12c_800DA434;

    buf = scratch->buf;
    for (i = 256; i > 0; i--)
    {
        tag = *buf++;

        while (tag != NULL)
        {
            val = *tag;
            next = &ot[val >> 24];
            *tag = *next | 0x0C000000;
            *next = (unsigned int)tag;
            tag = (unsigned int *)(val & 0xFFFFFF);
        }
    }
}

#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D4D8C.s")
void s12c_fadeio_800D4D8C(void *, int, int, void *);

void FogSortChanl_800D4E98(DG_CHNL *chnl, int idx)
{
    SCRATCHPAD_UNK *scratch;
    int             mask;
    int             group_id;
    void          **queue;
    int             i;
    DG_PRIM        *prim;
    int             type;

    scratch = get_scratch();
    scratch->buf = ptr_800B1400;
    scratch->ot = (unsigned int *)chnl->mOrderingTables[idx] + 1;

    s12c_800D4CF4(scratch->ot);

    mask = 0x1F;
    if (GV_PauseLevel_800AB928 != 0)
    {
        mask = 0;
    }

    gte_ldfcdir(0, 0, 0);

    scratch->unk18 = (void *)0x1F800020;
    scratch->unk1C = s12c_800DAA44;

    group_id = DG_CurrentGroupID_800AB968;

    queue = (void **)&chnl->mQueue[chnl->mFreePrimCount];
    for (i = chnl->mTotalQueueSize - chnl->mFreePrimCount; i > 0; i--)
    {
        prim = *queue++;
        type = prim->type;

        if (type & DG_PRIM_INVISIBLE)
        {
            continue;
        }

        if ((prim->group_id != 0) && !(prim->group_id & group_id))
        {
            continue;
        }

        // TODO: clean up
        ((SCRATCHPAD_UNK *)0x1f800000)->len = prim->field_2E_k500;

        type = (type + 1) & mask;
        s12c_fadeio_800D4D8C(prim->field_40_pBuffers[idx], prim->n_prims, prim->field_30_prim_size, fog_prim_funcs_800C347C[type]);
    }

    gte_strgb_s0(*(void **)0x1F800018);
}

#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D5010.s")
void s12c_fadeio_800D5010(DG_OBJS *objs, int idx, unsigned int flag, int in_bound_mode); // DG_BoundObjs_800185BC

static inline void copy_bounding_box_to_spad(DG_Bounds *bounds)
{
    DG_Bounds *bounding_box = (DG_Bounds *)SCRPAD_ADDR;
    bounding_box->max.vx = bounds->max.vx;
    bounding_box->max.vy = bounds->max.vy;
    bounding_box->max.vz = bounds->max.vz;

    bounding_box->min.vx = bounds->min.vx;
    bounding_box->min.vy = bounds->min.vy;
    bounding_box->min.vz = bounds->min.vz;
}

static inline void set_svec_from_bounding_box(int i, SVECTOR *svec)
{
    svec->vx = i & 1 ? ((long *)SCRPAD_ADDR)[3] : ((long *)SCRPAD_ADDR)[0];
    svec->vy = i & 2 ? ((long *)SCRPAD_ADDR)[4] : ((long *)SCRPAD_ADDR)[1];
    svec->vz = i & 4 ? ((long *)SCRPAD_ADDR)[5] : ((long *)SCRPAD_ADDR)[2];
}

void s12c_fadeio_800D5B00(DG_CHNL *chnl, int idx);

void FogBoundChanl_800D5500(DG_CHNL *chnl, int idx)
{
    int          i, i2, i3, a2, t0, a3, t1;
    int          n_objs;
    int          bound_mode, bound_mode2;
    DG_OBJS    **objs;
    int          local_group_id;
    DVECTOR     *dvec;
    SVECTOR     *svec;
    DG_VECTOR   *vec3_1;
    DG_VECTOR   *vec3_2;
    DG_Bounds   *mdl_bounds;
    int          n_bounding_box_vec;
    unsigned int flag;
    short       *scrpad;

    DG_Clip_80017594(&chnl->field_5C_clip_rect, chnl->field_50_clip_distance);

    scrpad = (short *)SCRPAD_ADDR;
    memcpy(scrpad + 0x90 / 2, DG_ClipMax_800AB970, 4);
    memcpy(scrpad + 0x94 / 2, DG_ClipMin_800AB96C, 4);

    objs = chnl->mQueue;
    n_objs = chnl->mTotalObjectCount;
    local_group_id = DG_CurrentGroupID_800AB968;

    for (; n_objs > 0; --n_objs)
    {
        DG_OBJS *current_objs = *objs;
        objs++;
        flag = current_objs->flag;

        bound_mode = 0;
        *(int *)(SCRPAD_ADDR + 0x98) = flag;
        if (!(flag & DG_FLAG_INVISIBLE))
        {
            if (!current_objs->group_id || (current_objs->group_id & local_group_id))
            {
                bound_mode = 2;
                if (flag & DG_FLAG_GBOUND)
                {
                    gte_SetRotMatrix(&current_objs->objs->screen);
                    gte_SetTransMatrix(&current_objs->objs->screen);

                    svec = (SVECTOR *)(SCRPAD_ADDR + 0x18);
                    mdl_bounds = (DG_Bounds *)&current_objs->def->max;
                    copy_bounding_box_to_spad(mdl_bounds);
                    vec3_1 = (DG_VECTOR *)(SCRPAD_ADDR + 0x30);
                    vec3_2 = (DG_VECTOR *)(SCRPAD_ADDR + 0x60);
                    i = 9;

                    while (i > 0)
                    {
                        n_bounding_box_vec = 3;
                        do
                        {
                            set_svec_from_bounding_box(i, svec);
                            ++svec;
                            --i;
                            --n_bounding_box_vec;
                        } while (n_bounding_box_vec > 0);

                        svec = (SVECTOR *)(SCRPAD_ADDR + 0x18);
                        gte_stsxy3c(vec3_1);
                        gte_stsz3c(vec3_2);

                        gte_ldv3c((SVECTOR *)(SCRPAD_ADDR + 0x18));
                        vec3_1++;
                        vec3_2++;
                        gte_rtpt_b();
                    }

                    gte_stsxy3c(vec3_1);
                    gte_stsz3c(vec3_2);

                    // probably start of another inline func
                    a2 = *(short *)(SCRPAD_ADDR + 0x3C);
                    t0 = *(short *)(SCRPAD_ADDR + 0x3E);
                    a3 = a2;
                    t1 = t0;
                    dvec = (DVECTOR *)(SCRPAD_ADDR + 0x3C);

                    for (i2 = 7; i2 > 0; --i2)
                    {
                        dvec++;
                        if (dvec->vx < a2)
                        {
                            a2 = dvec->vx;
                        }
                        else
                        {
                            if (a3 < dvec->vx)
                                a3 = dvec->vx;
                        }
                        if (dvec->vy < t0)
                        {
                            t0 = dvec->vy;
                        }
                        else
                        {
                            if (t1 < dvec->vy)
                                t1 = dvec->vy;
                        }
                    }

                    if ((a2 > *(short *)(SCRPAD_ADDR + 0x90)) || (a3 < *(short *)(SCRPAD_ADDR + 0x94)) ||
                        (t0 > *(short *)(SCRPAD_ADDR + 0x92)) || (t1 < *(short *)(SCRPAD_ADDR + 0x96)))
                    {
                        bound_mode = 0;
                    }
                    else
                    {
                        int bound_mode3;
                        bound_mode2 = ((a3 > *(short *)(SCRPAD_ADDR + 0x90)) || (a2 < *(short *)(SCRPAD_ADDR + 0x94)) ||
                                       (t1 > *(short *)(SCRPAD_ADDR + 0x92)) || (t0 < *(short *)(SCRPAD_ADDR + 0x96)))
                                          ? 1
                                          : 2;
                        if (*(int *)(SCRPAD_ADDR + 0x98) & 0x2)
                        {
                            int   var_t2_2;
                            int   i3, t1, t0;
                            long *test;
                            var_t2_2 = 0;
                            test = (long *)(SCRPAD_ADDR + 0x6C);
                            t1 = 0;
                            t0 = 0xFFFF;
                            i3 = 8;
                            while (i3 > 0)
                            {

                                if (*test < t0)
                                {
                                    t0 = *test;
                                }
                                if (t1 < *test)
                                {
                                    t1 = *test;
                                }
                                if (*test)
                                {
                                    var_t2_2 = bound_mode2;
                                }
                                test++;
                                i3--;
                            }

                            if (var_t2_2)
                            {
                                if (t0 / 256 < s12c_800DA430)
                                {
                                    if (t1 / 256 >= s12c_800DA428)
                                    {
                                        bound_mode3 = var_t2_2 | 4;
                                    }
                                    else
                                    {
                                        bound_mode3 = var_t2_2;
                                    }
                                }
                                else
                                {
                                    bound_mode3 = 0;
                                }
                            }
                            else
                            {
                                bound_mode3 = 0;
                            }
                        }
                        else
                        {
                            long *test;
                            test = (long *)(SCRPAD_ADDR + 0x6C);
                            i3 = 8;
                            while (i3 > 0)
                            {
                                --i3;
                                if (*test)
                                {
                                    bound_mode3 = bound_mode2;
                                    goto END;
                                }
                                test++;
                            }
                            bound_mode3 = 0;
                        }
                    END:
                        bound_mode = bound_mode3;
                    }
                }
            }
        }
        current_objs->bound_mode = bound_mode;
        s12c_fadeio_800D5010(current_objs, idx, flag, bound_mode);
    }

    s12c_fadeio_800D5B00(chnl, idx);
}

// Identical to DG_WriteObjClut_80018D28
void s12c_fadeio_800D59CC(DG_OBJ *pObj, int idx)
{
    int       n_packs;
    POLY_GT4 *pPack = pObj->packs[idx];
    short     val = 0x3FFF;
    if (pPack && pPack->clut != val)
    {
        while (pObj)
        {
            n_packs = pObj->n_packs;
            while (n_packs > 0)
            {
                pPack->clut = val;

                ++pPack;
                --n_packs;
            }

            pObj = pObj->extend;
        }
    }
}

DG_TEX DG_UnknownTexture_800C34FC = {0};

// Identical to DG_WriteObjClutUV_80018D90
void s12c_fadeio_800D5A34(DG_OBJ *obj, int idx)
{
    unsigned short id;
    POLY_GT4      *pack;
    int            n_packs;
    short         *tex_ids;
    DG_TEX        *texture;
    unsigned short current_id;

    pack = obj->packs[idx];

    if (pack && pack->clut == 0x3FFF)
    {
        texture = &DG_UnknownTexture_800C34FC;
        id = 0;
        while (obj)
        {
            tex_ids = obj->model->materialOffset_50;
            for (n_packs = obj->n_packs; n_packs > 0; --n_packs)
            {
                current_id = *tex_ids;
                tex_ids++;
                if ((current_id & 0xFFFF) != id)
                {
                    id = current_id;
                    texture = DG_GetTexture_8001D830(id);
                }
                pack->clut = texture->field_6_clut;
                pack++;
            }
            obj = obj->extend;
        }
    }
}

// Identical to DG_BoundChanl_helper2_80018E5C
// there must be a way to match this without the repetition
void s12c_fadeio_800D5B00(DG_CHNL *chnl, int idx)
{
    int       i, i2;
    DG_OBJ   *obj;
    DG_OBJS  *objs;
    DG_OBJS **objs_list;

    objs_list = chnl->mQueue;
    if (GM_GameStatus_800AB3CC & GAME_FLAG_BIT_04)
    {
        for (i = chnl->mTotalObjectCount; i > 0; --i)
        {
            objs = *objs_list;
            objs_list++;
            if (objs->flag & DG_FLAG_IRTEXTURE && objs->bound_mode)
            {
                obj = objs->objs;
                for (i2 = objs->n_models; i2 > 0; --i2)
                {
                    if (obj->bound_mode)
                    {
                        s12c_fadeio_800D59CC(obj, idx);
                    }
                    obj++;
                }
            }
        }
    }
    else
    {
        for (i = chnl->mTotalObjectCount; i > 0; --i)
        {
            objs = *objs_list;
            objs_list++;
            if (objs->flag & DG_FLAG_IRTEXTURE && objs->bound_mode)
            {
                obj = objs->objs;
                for (i2 = objs->n_models; i2 > 0; --i2)
                {
                    s12c_fadeio_800D5A34(obj, idx);
                    obj++;
                }
            }
        }
    }
}

#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D5C48.s")
#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D5CDC.s")
#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D5DE0.s")
#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D6020.s")
void s12c_fadeio_800D6020(DG_OBJ *pObj, int idx); // DG_Trans_Chanl_helper_8001DF48

void FogTransChanl_800D63B0(DG_CHNL *pChannel, int idx)
{
    short *pScratchpad = (short *)getScratchAddr(0);
    DG_OBJS **ppObjs;
    int objects;
    DG_OBJS *pObjs;
    DG_OBJ *pObj;
    int uVar5;
    int models;
    DG_MDL *pMdl;
    DG_OBJ *pParent;
    short uVar1;

    DG_Clip_80017594(&pChannel->field_5C_clip_rect, pChannel->field_50_clip_distance);

    ppObjs = (DG_OBJS **)pChannel->mQueue;

    for (objects = pChannel->mTotalObjectCount; objects > 0; objects--)
    {
        pObjs = *ppObjs++;

        if (!pObjs->bound_mode)
        {
            continue;
        }

        pObj = pObjs->objs;
        uVar5 = !(pObjs->flag & DG_FLAG_GBOUND);

        for (models = pObjs->n_models; models > 0; pObj++, models--)
        {
            if (!pObj->bound_mode)
            {
                continue;
            }

            pMdl = pObj->model;
            pParent = &pObjs->objs[pMdl->parent_2C];

            ((POLY_GT4 **)pScratchpad)[0xfe] = pParent->packs[GV_Clock_800AB920];
            ((SVECTOR **)pScratchpad)[0xff] = pMdl->vertexIndexOffset_38;

            gte_SetRotMatrix(&pObj->screen);
            gte_SetTransMatrix(&pObj->screen);

            uVar1 = 0;

            if (uVar5 != 0)
            {
                uVar1 = pObj->bound_mode & 1;
            }

            pScratchpad[0xff] = uVar1;
            if (pObj->bound_mode & 4)
            {
                pScratchpad[0xff] |= 2;
            }

            if (pObjs->flag & DG_FLAG_SHADE)
            {
                pScratchpad[0xff] |= 4;
            }

            s12c_fadeio_800D6020(pObj, idx);
        }
    }
}

#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D6588.s")
#pragma INCLUDE_ASM("asm/overlays/s12c/s12c_fadeio_800D6698.s")
void s12c_fadeio_800D6698(DG_MDL* mdl);

//just an index using an int shifted to get each byte of the face normal idx, but didnt match that way
static inline void set_face_normal_pack(unsigned int *face_normals, POLY_GT4 *packs, void* dst)
{
    unsigned int fa, fb, fc, fd;
    fa = *face_normals;
    fb = *face_normals;
    fc = *face_normals;
    fd = *face_normals;

    fa <<= 2;
    fb >>= 6;
    fc >>= 22;
    fd >>= 14;

    fa &= 0x1FC;
    fb &= 0x1FC;
    fc &= 0x1FC;
    fd &= 0x1FC;
    fa = (int)(dst + fa);
    fb = (int)(dst + fb);
    fc = (int)(dst + fc);
    fd = (int)(dst + fd);

    LCOPY2( (void*)fa, &packs->r0, (void*)fb, &packs->r1 );
    LCOPY2( (void*)fc, &packs->r2, (void*)fd, &packs->r3 );
}

// Identical to DG_Shade_Chanl_helper_helper_8001CF88
POLY_GT4 *s12c_fadeio_800D6744( unsigned int *face_normals, POLY_GT4 *packs, int n_packs )
{
    for ( --n_packs; n_packs >= 0 ; --n_packs )
    {
        void *scrpad_pack = (void*)0x1F800020;
        if ( packs->tag & 0xFFFF )
        {
            set_face_normal_pack(face_normals, packs, scrpad_pack);
        }
        packs++;
        face_normals++;
    }

    return packs;
}

// Identical to DG_Shade_Chanl_helper_helper2_8001D034
POLY_GT4 *s12c_fadeio_800D67F0( unsigned int *face_normals, POLY_GT4 *packs, int n_packs, unsigned int* face )
{
    unsigned int t2, t6;
    unsigned int fa,fb,fc,fd;
    void* scrpad_pack;
    for ( --n_packs; n_packs >= 0 ; packs++, face_normals++, face++, --n_packs )
    {
        t6 = 0x80808080;
        scrpad_pack = (void*)0x1F800020;
        fa = *face_normals;

        if ( !( packs->tag & 0xFFFF ) && !( *face_normals & t6 ) ) continue;

        t2 = *face;
        fd = *face_normals;
        fa = *face_normals << 2;
        fb = *face_normals >> 6;
        fc = *face_normals >> 22;
        fd = *face_normals >> 14;

        fa &= 0x1FC;
        fb &= 0x1FC;
        fc &= 0x1FC;
        fd &= 0x1FC;

        fa += (unsigned int)scrpad_pack;
        fb += (unsigned int)scrpad_pack;
        fc += (unsigned int)scrpad_pack;
        fd += (unsigned int)scrpad_pack;

        if ( t2 & t6 )
        {
            int val;
            if ( t2 & 0x80 )
            {
                val = **(int**)&packs->r0;
            }
            else
            {
                val = *(int*)fa;
            }
            t2 >>= 8;
            *(int*)&packs->r0 = val;

            if ( t2 & 0x80 )
            {
                val = **(int**)&packs->r1;
            }
            else
            {
                val = *(int*)fb;
            }
            t2 >>= 8;
            *(int*)&packs->r1 = val;

            if ( t2 & 0x80 )
            {
                val = **(int**)&packs->r3;
            }
            else
            {
                val = *(int*)fd;
            }
            t2 >>= 8;
            *(int*)&packs->r3 = val;

            if ( t2 & 0x80 )
            {
                val = **(int**)&packs->r2;
            }
            else
            {
                val = *(int*)fc;
            }
            t2 >>= 8;
            *(int*)&packs->r2 = val;

        }
        else
        {
            LCOPY2( (void*)fa, &packs->r0, (void*)fb, &packs->r1 );
            LCOPY2( (void*)fc, &packs->r2, (void*)fd, &packs->r3 );
        }
    }

    return packs;
}

// Based on DG_Shade_Chanl_helper_8001D19C, but most of the body of
// the for loop extracted to a separate function?
void s12c_fadeio_800D6958( DG_OBJ* obj, int idx )
{
    // int n_normals;
    // DG_VECTOR* nidx;
    // DG_VECTOR* scrpd_nidx;
    // DG_VECTOR* scrpd_nidx2;
    // unsigned long *code;
    POLY_GT4* pack;
    DG_MDL* mdl;

    pack = obj->packs[ idx ];

    while ( obj )
    {
        mdl = obj->model; //t1;

        s12c_fadeio_800D6698(mdl);
        /*
        code = DG_PacketCode_800AB394;
        if ( mdl->flags_0 & 2 )
        {
            code = &DG_PacketCode_800AB394[1];
        }

        gte_ldrgb( code );
        scrpd_nidx = (DG_VECTOR*)0x1F800020;
        nidx = (DG_VECTOR*)mdl->normalIndexOffset_44; //a2
        n_normals = mdl->numNormals_40;

        scrpd_nidx[0] = nidx[0]; //maybe copyvector macro
        scrpd_nidx[1] = nidx[1];

        scrpd_nidx2 = (DG_VECTOR*)0x1F800020;
        while ( n_normals > 0 )
        {

            gte_ldv3c( scrpd_nidx2 );
            n_normals  -= 3;
            nidx += 2;
            gte_nct_b();
            scrpd_nidx2++;

            scrpd_nidx2[0] = nidx[0];
            scrpd_nidx2[1] = nidx[1];

            gte_strgb3( &scrpd_nidx2[-1].vx, &scrpd_nidx2[-1].vy, &scrpd_nidx2[-1].vz );
        }
        */

        if ( !( mdl->flags_0 & 0x10000 ) )
        {
            pack = s12c_fadeio_800D6744( (unsigned int*)mdl->normalFaceOffset_48, pack, obj->n_packs );
        }
        else
        {
            pack = s12c_fadeio_800D67F0( (unsigned int*)mdl->normalFaceOffset_48, pack, obj->n_packs, (unsigned int*)mdl->faceIndexOffset_3C );
        }
        obj = obj->extend;
    }
}

#pragma INCLUDE_ASM("asm/overlays/s12c/FogShadeChanl_800D6A04.s")

