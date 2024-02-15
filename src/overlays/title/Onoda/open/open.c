#include "libdg/libdg.h"
#include "libgv/libgv.h"
#include "Font/font.h"
#include "Menu/menuman.h"
#include "SD/sd.h"
#include "Game/game.h"

typedef struct _OpenWork
{
    GV_ACT   actor;
    DG_PRIM *prim[4]; 
    char     pad[0x110];
    int      f140[9];
    int      f164;
    int      f168;
    int      f16C;
    int      f170;
    int      f174;
    int      f178;
    int      f17C;
    int      f180;
    int      f184;
    int      f188;
    POLY_FT4 f18C_polys[22];
    POLY_FT4 f4FC_polys[18];
    POLY_FT4 f7CC_polys[9];
    POLY_GT4 f934_polys[6];
    int      fA6C;
    int      fA70;
    int      fA74;
    int      fA78;
    int      fA7C;
    int      fA80;
    int      fA84;
    int      fA88;
    int      fA8C;
    int      fA90;
    int      fA94;
    int      fA98;
    int      fA9C;
    int      fAA0;
    int      fAA4;
    char     fAA8; // Could be array or part of some struct (KCB?)
    char     fAA9;
    char     fAAA;
    char     fAAB;
    char     fAAC;
    char     fAAD;
    char     fAAE;
    char     fAAF;
    char     pad6[0x28]; // AB0
    int      fAD8;
    int      fADC;
    int      fAE0;
    int      fAE4;
    int      fAE8;
    int      fAEC;
    int      fAF0;
    int      fAF4;
    int      fAF8;
    int      fAFC;
    int      fB00;
    int      fB04;
    int      fB08;
    int      fB0C;
    int      fB10;
    int      fB14;
    int      fB18;
    int      fB1C;
    int      fB20;
    int      fB24;
    int      fB28;
    int      fB2C;
    int      fB30;
    int      fB34;
    int      fB38;
    int      fB3C;
    int      fB40;
    int      fB44;
    int      fB48;
    KCB      kcb[24]; // B4C
    char     pad8[0x1540]; // F6C
    int      f24AC;
    int      f24B0;
    int      f24B4;
    int      f24B8;
    int      f24BC;
    int      f24C0;
    int      f24C4;
    int      f24C8;
    int      f24CC;
    int      f24D0;
    int      f24D4;
    int      f24D8;
    int      f24DC;
    int      f24E0;
    int      f24E4;
    int      f24E8;
    int      f24EC;
    int      f24F0;
    int      f24F4;
    int      f24F8_proc;
    char     pad9[8];
} OpenWork;

extern int title_dword_800D92D0;
extern int title_dword_800C33D4;

extern const char title_aMemorycardslot_800D8FAC[];      // = "MEMORY CARD SLOT 1  :  "
extern const char title_aFull_800D8FC4[];                // = "   FULL"
extern const char title_aNocard_800D8FCC[];              // = "NO CARD"
extern const char title_aMemorycardslot_800D8FD4[];      // = "MEMORY CARD SLOT 2  :  "
extern const char title_aDoyouwanttocontinue_800D8FEC[]; // = "DO YOU WANT TO CONTINUE\n"
extern const char title_aYourgamelikethis_800D9008[];    // = "YOUR GAME LIKE THIS?"
extern const char title_aYes_800D9020[];                 // = "YES"
extern const char title_aNo_800D9024[];                  // = "NO"
extern const char aOpenC[];                              // = "open.c"

extern int GM_GameStatus_800AB3CC;
extern int gDiskNum_800ACBF0;

#define EXEC_LEVEL 1

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C4500.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C4674.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C47B8.s")
void title_open_800C47B8(OpenWork *, int);

void title_open_800C4AD0(OpenWork *work, int index, int color)
{
    KCB *kcb;

    kcb = &work->kcb[index];
    font_set_color_80044DC4(kcb, 0, color, 0);
    font_clut_update_80046980(kcb);
}

void * title_open_800C4B20(KCB *kcb)
{
    return kcb->font_clut_buffer;
}

int title_open_800C4B2C(int val)
{
    int ret;
    int pow2;
    int val2;

    val2 = val;
    pow2 = 1;
    while (val2 >= 2)
    {
        val2 /= 2;
        pow2 *= 2;
    }
    pow2 *= 2;

    do
    {
        ret = GV_RandU_80017090(pow2) - (pow2 - val);
    } while (ret < 0);

    return ret;
}

void title_open_800C4B94(POLY_GT4 *poly, int r0, int g0, int b0, int r2, int g2, int b2)
{
    setRGB0(poly, r0, g0, b0);
    setRGB1(poly, r0, g0, b0);
    setRGB2(poly, r2, g2, b2);
    setRGB3(poly, r2, g2, b2);
}

void title_open_800C4BD4(POLY_GT4 *poly, int shade3, int shade4)
{
    int shade1, shade2;

    shade1 = shade3 * 192 / 128;
    shade2 = shade4 * 192 / 128;

    setRGB0(poly, shade3, shade1, shade3);
    setRGB1(poly, shade3, shade1, shade3);
    setRGB2(poly, shade4, shade2, shade4);
    setRGB3(poly, shade4, shade2, shade4);
}

// Identical to title_open_800C4F1C, but sets 0x200 to f140[] elements
void title_open_800C4C38(OpenWork *work, int x0, int y0, int xsize, int ysize, int color, int mode)
{
    POLY_FT4 *polys;
    int i;

    polys = work->f7CC_polys;
    for (i = 0; i < 9; i++)
    {
        work->f140[i] = 0x200;
        setRGB0(&polys[i], color, color, color);
    }

    if (mode == 0)
    {
        setXY4(&polys[0], x0 - 8, y0 - 8, x0, y0 - 8, x0 - 8, y0, x0, y0);
        setXY4(&polys[1], x0 + xsize, y0 - 8, x0 + xsize + 8, y0 - 8, x0 + xsize, y0, x0 + xsize + 8, y0);
        setXY4(&polys[2], x0 - 8, y0 + ysize, x0, y0 + ysize, x0 - 8, y0 + ysize + 8, x0, y0 + ysize + 8);
        setXY4(&polys[3], x0 + xsize, y0 + ysize, x0 + xsize + 8, y0 + ysize, x0 + xsize, y0 + ysize + 8, x0 + xsize + 8, y0 + ysize + 8);
        setXY4(&polys[4], x0, y0 - 8, x0 + xsize, y0 - 8, x0, y0, x0 + xsize, y0);
        setXY4(&polys[5], x0, y0 + ysize, x0 + xsize, y0 + ysize, x0, y0 + ysize + 8, x0 + xsize, y0 + ysize + 8);
        setXY4(&polys[6], x0 - 8, y0, x0, y0, x0 - 8, y0 + ysize, x0, y0 + ysize);
        setXY4(&polys[7], x0 + xsize, y0, x0 + xsize + 8, y0, x0 + xsize, y0 + ysize, x0 + xsize + 8, y0 + ysize);
        setXY4(&polys[8], x0, y0, x0 + xsize, y0, x0, y0 + ysize, x0 + xsize, y0 + ysize);
    }
    else if (mode == 1)
    {
        setXY4(&polys[0], x0 - 6, y0 - 6, x0 + 2, y0 - 6, x0 - 6, y0 + 2, x0 + 2, y0 + 2);
        setXY4(&polys[1], x0 + xsize - 2, y0 - 6, x0 + xsize + 6, y0 - 6, x0 + xsize - 2, y0 + 2, x0 + xsize + 6, y0 + 2);
        setXY4(&polys[2], x0 - 6, y0 + ysize - 2, x0 + 2, y0 + ysize - 2, x0 - 6, y0 + ysize + 6, x0 + 2, y0 + ysize + 6);
        setXY4(&polys[3], x0 + xsize - 2, y0 + ysize - 2, x0 + xsize + 6, y0 + ysize - 2, x0 + xsize - 2, y0 + ysize + 6, x0 + xsize + 6, y0 + ysize + 6);
        setXY4(&polys[4], x0 + 2, y0 - 6, x0 + xsize - 2, y0 - 6, x0 + 2, y0 + 2, x0 + xsize - 2, y0 + 2);
        setXY4(&polys[5], x0 + 2, y0 + ysize - 2, x0 + xsize - 2, y0 + ysize - 2, x0 + 2, y0 + ysize + 6, x0 + xsize - 2, y0 + ysize + 6);
        setXY4(&polys[6], x0 - 6, y0 + 2, x0 + 2, y0 + 2, x0 - 6, y0 + ysize - 2, x0 + 2, y0 + ysize - 2);
        setXY4(&polys[7], x0 + xsize - 2, y0 + 2, x0 + xsize + 6, y0 + 2, x0 + xsize - 2, y0 + ysize - 2, x0 + xsize + 6, y0 + ysize - 2);
        setXY4(&polys[8], x0 + 2, y0 + 2, x0 + xsize - 2, y0 + 2, x0 + 2, y0 + ysize - 2, x0 + xsize - 2, y0 + ysize - 2);
    }
}

void title_open_800C4F1C(OpenWork *work, int x0, int y0, int xsize, int ysize, int color, int mode)
{
    POLY_FT4 *polys;
    int i;

    polys = work->f7CC_polys;
    for (i = 0; i < 9; i++)
    {
        work->f140[i] = 0x100;
        setRGB0(&polys[i], color, color, color);
    }

    if (mode == 0)
    {
        setXY4(&polys[0], x0 - 8, y0 - 8, x0, y0 - 8, x0 - 8, y0, x0, y0);
        setXY4(&polys[1], x0 + xsize, y0 - 8, x0 + xsize + 8, y0 - 8, x0 + xsize, y0, x0 + xsize + 8, y0);
        setXY4(&polys[2], x0 - 8, y0 + ysize, x0, y0 + ysize, x0 - 8, y0 + ysize + 8, x0, y0 + ysize + 8);
        setXY4(&polys[3], x0 + xsize, y0 + ysize, x0 + xsize + 8, y0 + ysize, x0 + xsize, y0 + ysize + 8, x0 + xsize + 8, y0 + ysize + 8);
        setXY4(&polys[4], x0, y0 - 8, x0 + xsize, y0 - 8, x0, y0, x0 + xsize, y0);
        setXY4(&polys[5], x0, y0 + ysize, x0 + xsize, y0 + ysize, x0, y0 + ysize + 8, x0 + xsize, y0 + ysize + 8);
        setXY4(&polys[6], x0 - 8, y0, x0, y0, x0 - 8, y0 + ysize, x0, y0 + ysize);
        setXY4(&polys[7], x0 + xsize, y0, x0 + xsize + 8, y0, x0 + xsize, y0 + ysize, x0 + xsize + 8, y0 + ysize);
        setXY4(&polys[8], x0, y0, x0 + xsize, y0, x0, y0 + ysize, x0 + xsize, y0 + ysize);
    }
    else if (mode == 1)
    {
        setXY4(&polys[0], x0 - 6, y0 - 6, x0 + 2, y0 - 6, x0 - 6, y0 + 2, x0 + 2, y0 + 2);
        setXY4(&polys[1], x0 + xsize - 2, y0 - 6, x0 + xsize + 6, y0 - 6, x0 + xsize - 2, y0 + 2, x0 + xsize + 6, y0 + 2);
        setXY4(&polys[2], x0 - 6, y0 + ysize - 2, x0 + 2, y0 + ysize - 2, x0 - 6, y0 + ysize + 6, x0 + 2, y0 + ysize + 6);
        setXY4(&polys[3], x0 + xsize - 2, y0 + ysize - 2, x0 + xsize + 6, y0 + ysize - 2, x0 + xsize - 2, y0 + ysize + 6, x0 + xsize + 6, y0 + ysize + 6);
        setXY4(&polys[4], x0 + 2, y0 - 6, x0 + xsize - 2, y0 - 6, x0 + 2, y0 + 2, x0 + xsize - 2, y0 + 2);
        setXY4(&polys[5], x0 + 2, y0 + ysize - 2, x0 + xsize - 2, y0 + ysize - 2, x0 + 2, y0 + ysize + 6, x0 + xsize - 2, y0 + ysize + 6);
        setXY4(&polys[6], x0 - 6, y0 + 2, x0 + 2, y0 + 2, x0 - 6, y0 + ysize - 2, x0 + 2, y0 + ysize - 2);
        setXY4(&polys[7], x0 + xsize - 2, y0 + 2, x0 + xsize + 6, y0 + 2, x0 + xsize - 2, y0 + ysize - 2, x0 + xsize + 6, y0 + ysize - 2);
        setXY4(&polys[8], x0 + 2, y0 + 2, x0 + xsize - 2, y0 + 2, x0 + 2, y0 + ysize - 2, x0 + xsize - 2, y0 + ysize - 2);
    }
}

void title_open_800C5200(POLY_FT4 *poly, int arg1)
{
    int tpage;
    unsigned short tpage2;

    tpage = tpage2 = poly->tpage;
    poly->tpage = (tpage & 0x180) | ((arg1 & 3) << 5) | (poly->tpage & 0x10) | (poly->tpage & 0xF) | (tpage & 0x800);
}


#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5238.s")

void title_open_800C5360(OpenWork *work, int texid, POLY_FT4 *poly)
{
    DG_TEX *tex;
    int u0, u1;
    int v0, v1;

    tex = DG_GetTexture_8001D830(texid);

    u0 = tex->field_8_offx;
    u1 = u0 + tex->field_A_width + 1;
    v0 = tex->field_9_offy;
    v1 = v0 + tex->field_B_height + 1;

    setUV4(poly, u0, v0, u1, v0, u0, v1, u1, v1);

    poly->tpage = tex->field_4_tPage;
    poly->clut = tex->field_6_clut;
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C53E0.s")

int title_open_800C5620(int val)
{
    return title_open_800C4B2C(val) == 1;
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5644.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5750.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5760.s")

void title_open_800C593C(OpenWork *work)
{
    POLY_FT4 *polys1;
    POLY_GT4 *polys2;
    POLY_FT4 *polys3;
    POLY_FT4 *polys4;
    int       scale;
    int       r, g, b;
    int       i;

    polys1 = work->f18C_polys;
    polys2 = work->f934_polys;
    polys3 = work->f4FC_polys;
    polys4 = work->f7CC_polys;

    if (work->fB04 <= 96)
    {
        scale = 128 - work->fB04 * 4 / 3;
        for (i = 0; i < 22; i++)
        {
            r = polys1[i].r0 * scale / 128;
            g = polys1[i].g0 * scale / 128;
            b = polys1[i].b0 * scale / 128;
            setRGB0(&polys1[i], r, g, b);
        }

        for (i = 0; i < 6; i++)
        {
            r = polys2[i].r0 * scale / 128;
            g = polys2[i].g0 * scale / 128;
            b = polys2[i].b0 * scale / 128;
            setRGB0(&polys2[i], r, g, b);

            r = polys2[i].r1 * scale / 128;
            g = polys2[i].g1 * scale / 128;
            b = polys2[i].b1 * scale / 128;
            setRGB1(&polys2[i], r, g, b);

            r = polys2[i].r2 * scale / 128;
            g = polys2[i].g2 * scale / 128;
            b = polys2[i].b2 * scale / 128;
            setRGB2(&polys2[i], r, g, b);

            r = polys2[i].r3 * scale / 128;
            g = polys2[i].g3 * scale / 128;
            b = polys2[i].b3 * scale / 128;
            setRGB3(&polys2[i], r, g, b);
        }

        for (i = 0; i < 18; i++)
        {
            r = polys3[i].r0 * scale / 128;
            g = polys3[i].g0 * scale / 128;
            b = polys3[i].b0 * scale / 128;
            setRGB0(&polys3[i], r, g, b);
        }

        for (i = 0; i < 9; i++)
        {
            r = polys4[i].r0 * scale / 128;
            g = polys4[i].g0 * scale / 128;
            b = polys4[i].b0 * scale / 128;
            setRGB0(&polys4[i], r, g, b);
        }

        work->fB04++;
    }
    else
    {
        work->f164 = 0;
        work->fA74 = 0;
        work->fB0C = 1;
    }
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5CB8.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5CF0.s")

void title_open_800C5D10(OpenWork *work)
{
    int i;

    for (i = 0; i < 9; i++)
    {
        work->f140[i] = 0;
    }
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C5D30.s")

void title_open_800C61E0(OpenWork *work, GCL_ARGS *args)
{
    GM_SeSet2_80032968(0, 0x3F, 0x66);
    if (gDiskNum_800ACBF0 == 0)
    {
        if (SD_800886F4() == 0)
        {
            GCL_ExecProc_8001FF2C(work->f24F8_proc, args);
            GV_DestroyActor_800151C8(&work->actor);
        }
    }
    else
    {
        work->fB0C = 1;
        work->fA74 = 9;
        work->f24EC = 0;
        work->f24AC = 0;
        work->f24B0 = 0;
        work->f24B4 = 0; 
        work->f24B8 = 0;
        work->f24BC = 0;
        title_dword_800C33D4 = work->f24F8_proc;
    }
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800C628C.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CCDC8.s")

void title_open_800CD074(OpenWork *work)
{
    int sqrt1, sqrt2;
    int val1, val2, val3;
    int val1_2, val2_2, val3_2;

    val1 = work->fAA8;
    val2 = work->fAA9;
    val3 = work->fAAA;
    sqrt1 = SquareRoot0(val1 * val1 + val2 * val2 + val3 * val3);
    
    val1_2 = 0xFF - val1;
    val2_2 = 0xFF - val2;
    val3_2 = 0xFF - val3; 
    sqrt2 = SquareRoot0(val1_2 * val1_2 + val2_2 * val2_2 + val3_2 * val3_2);
    
    if (sqrt2 != 0)
    {
        val1_2 = (val1_2 * sqrt1) / sqrt2;
        if (val1_2 > 0xFF)
        {
            val1_2 = 0xFF;
        }
        val2_2 = (val2_2 * sqrt1) / sqrt2;
        if (val2_2 > 0xFF)
        {
            val2_2 = 0xFF;
        }
        val3_2 = (val3_2 * sqrt1) / sqrt2;
        if (val3_2 > 0xFF)
        {
            val3_2 = 0xFF;
        }
    }
    else
    {
        val1_2 = 0xFF;
        val2_2 = 0xFF;
        val3_2 = 0xFF;
    }

    work->fAAC = val1_2;
    work->fAAD = val2_2;
    work->fAAE = val3_2;
}

void title_open_800CD23C(OpenWork *work, int index, int arg3)
{
    GCL_ARGS args;
    long argv[2];
    POLY_FT4 *polys;
    int shade;

    args.argc = 2;
    args.argv = argv;
    argv[0] = work->f24D0;
    argv[1] = work->fB28;

    polys = work->f18C_polys;
    polys += index;

    if (work->f164 <= 20)
    {
        shade = work->f164 * 6;
        setRGB0(&polys[0], shade, shade, shade);
        setRGB0(&polys[1], shade, shade, shade);
    }
    else if (work->f164 <= 82)
    {
        setRGB0(&polys[0], 128, 128, 128);
        setRGB0(&polys[1], 128, 128, 128);
    }
    else if (work->f164 <= 102)
    {
        shade = 120 - (work->f164 - 82) * 6;
        setRGB0(&polys[0], shade, shade, shade);
        setRGB0(&polys[1], shade, shade, shade);
    }
    else
    {
        work->fB0C = 1;
        work->f164 = 0;
        work->fA74 = arg3;
        if (arg3 == 15)
        {
            GCL_ExecProc_8001FF2C(work->fAD8, &args);
            GV_DestroyActor_800151C8(&work->actor);
        }
    }
}

void title_open_800CD320(OpenWork *work, int index)
{
    POLY_FT4 *polys;
    int shade;

    polys = work->f18C_polys;
    polys += index;

    if (work->f164 <= 20)
    {
        shade = work->f164 * 6;

        polys[0].r0 = shade;
        polys[0].g0 = shade;
        polys[0].b0 = shade;
        polys[1].r0 = shade;
        polys[1].g0 = shade;
        polys[1].b0 = shade;
    }
    else if (work->f164 <= 82)
    {
        work->f164 = 82;
    }
    else if (work->f164 <= 102)
    {
        shade = 120 - (work->f164 - 82) * 6;

        polys[0].r0 = shade;
        polys[0].g0 = shade;
        polys[0].b0 = shade;
        polys[1].r0 = shade;
        polys[1].g0 = shade;
        polys[1].b0 = shade;
    }
    else
    {
        work->fA74 = 6;
        work->f164 = 0;
        work->fB0C = 1;
    }
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CD3B8.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CD800.s")

void title_open_800CDB4C(POLY_FT4 *poly, DG_TEX *tex, int arg2)
{
    int u0, u1;
    int v0, v1;
    int height;

    u0 = tex->field_8_offx;
    u1 = tex->field_8_offx + arg2;

    v0 = tex->field_9_offy;
    height = tex->field_B_height + 1;
    v1 = v0 + height;

    setUV4(poly, u0, v0, u1, v0, u0, v1, u1, v1);

    poly->tpage = tex->field_4_tPage;
    poly->clut = tex->field_6_clut;
}


void title_open_800CDB9C(POLY_FT4 *poly, DG_TEX *tex, int arg2)
{
    int u0, u1;
    int v0, v1;
    int height, width;

    u0 = tex->field_8_offx + arg2;
    width = tex->field_A_width + 1;
    u1 = tex->field_8_offx + width;

    v0 = tex->field_9_offy;
    height = tex->field_B_height + 1;
    v1 = v0 + height;

    setUV4(poly, u0, v0, u1, v0, u0, v1, u1, v1);

    poly->tpage = tex->field_4_tPage;
    poly->clut = tex->field_6_clut;
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CDBF8.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CDE44.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CE378.s")

void title_open_800CE4A8(OpenWork *work, int index)
{
    POLY_FT4 *polys;
    int shade;

    polys = work->f18C_polys;
    polys += index;

    switch (work->fA90)
    {
    case 0:
        if (work->f17C >= 256)
        {
            work->fA90 = 1;
            work->f17C = 0;
        }
        break;
    case 1:
        shade = work->f17C;
        setRGB0(polys, shade, shade, shade);
        if (work->f17C >= 128)
        {
            work->fA90 = 2;
            work->f17C = 0;
            setRGB0(polys, 128, 128, 128);
        }
        break;
    case 2:
        break;
    }
}

void title_open_800CE544(OpenWork *work, int index)
{
    POLY_FT4 *polys;
    int shade;

    polys = work->f18C_polys;
    polys += index;

    switch (work->fA94)
    {
    case 0:
        if (work->f180 >= 256)
        {
            work->fA94 = 1;
            work->f180 = 0;
        }
        break;
    case 1:
        shade = work->f180;
        setRGB0(&polys[0], shade, shade, shade);
        setRGB0(&polys[1], shade, shade, shade);

        if (work->f180 >= 128)
        {
            work->fA94 = 2;
            work->f180 = 0;
            setRGB0(&polys[0], 128, 128, 128);
            setRGB0(&polys[1], 128, 128, 128);
        }
        break;
    case 2:
        break;
    }
}

void title_open_800CE5F8(OpenWork *work, int index)
{
    POLY_FT4 *polys;
    int f184;
    int r;

    polys = work->f18C_polys;
    polys += index;

    switch (work->fA98)
    {
    case 0:
        if (work->f184 >= 376)
        {
            work->fA98 = 1;
            work->f184 = 0;
        }
        break;
    case 1:
        f184 = work->f184;

        r = f184 * 8;
        if (r > 255)
        {
            r = 255;
        }
        setRGB0(polys, r, f184 * 2, f184 * 2);

        if (work->f184 >= 31)
        {
            work->fA98 = 2;
            work->f184 = 0;
            setRGB0(polys, 255, 64, 64);
        }
        break;
    case 2:
        break;
    }
}

void title_open_800CE6AC(OpenWork *work, int index)
{
    POLY_FT4 *polys;
    int shade;

    polys = work->f18C_polys;
    polys += index;

    switch (work->fA9C)
    {
    case 0:
        if (work->f188 >= 160)
        {
            work->fA9C = 1;
            work->f188 = 0;
        }
        break;
    case 1:
        shade = work->f188;
        setRGB0(polys, shade, shade, shade);
        if (work->f188 >= 128)
        {
            work->fA9C = 2;
            work->f188 = 0;
            setRGB0(polys, 128, 128, 128);
        }
        break;
    case 2:
        break;
    }
}

#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CE748.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CEB14.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800CF794.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800D1B74.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800D1CB4.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800D2374.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800D2460.s")
#pragma INCLUDE_ASM("asm/overlays/title/title_open_800D2E44.s")

void title_open_800D3500(OpenWork *work, int arg1)
{
    int i;

    for (i = 0; i < 24; i++)
    {
        title_open_800C4AD0(work, i, 0);
    }

    if (work->fA74 >= 18 && work->fA74 <= 19)
    {
        title_open_800C4AD0(work, 21, 0x6739);

        MENU_Locate_80038B34(54, 60, 0x10);
        MENU_Color_80038B4C(100, 160, 135);
        MENU_Printf_80038C38(title_aMemorycardslot_800D8FAC);

        if (work->f24F0 == 3)
        {
            MENU_Locate_80038B34(223, 60, 0x10);
            MENU_Color_80038B4C(181, 85, 42);
            MENU_Printf_80038C38(title_aFull_800D8FC4);
        }
        else
        {
            MENU_Locate_80038B34(223, 60, 0x10);
            MENU_Color_80038B4C(181, 85, 42);
            MENU_Printf_80038C38(title_aNocard_800D8FCC);
        }

        MENU_Locate_80038B34(54, 75, 0x10);
        MENU_Color_80038B4C(100, 160, 135);
        MENU_Printf_80038C38(title_aMemorycardslot_800D8FD4);

        if (work->f24F4 == 3)
        {
            MENU_Locate_80038B34(223, 75, 0x10);
            MENU_Color_80038B4C(181, 85, 42);
            MENU_Printf_80038C38(title_aFull_800D8FC4);
        }
        else
        {
            MENU_Locate_80038B34(223, 75, 0x10);
            MENU_Color_80038B4C(181, 85, 42);
            MENU_Printf_80038C38(title_aNocard_800D8FCC);
        }

        MENU_Locate_80038B34(70, 100, 0x10);
        MENU_Color_80038B4C(100, 160, 135);
        MENU_Printf_80038C38(title_aDoyouwanttocontinue_800D8FEC);

        MENU_Locate_80038B34(85, 115, 0x10);
        MENU_Color_80038B4C(100, 160, 135);
        MENU_Printf_80038C38(title_aYourgamelikethis_800D9008);

        if (work->f24E0 == 0)
        {
            MENU_Locate_80038B34(100, 150, 0x10);
            MENU_Color_80038B4C(192, 192, 192);
            MENU_Printf_80038C38(title_aYes_800D9020);

            MENU_Locate_80038B34(200, 150, 0x10);
            MENU_Color_80038B4C(46, 72, 61);
            MENU_Printf_80038C38(title_aNo_800D9024);

            title_open_800C4F1C(work, -68, 33, 40, 15, 255, 1);
        }
        else
        {
            MENU_Locate_80038B34(100, 150, 0x10);
            MENU_Color_80038B4C(46, 72, 61);
            MENU_Printf_80038C38(title_aYes_800D9020);

            MENU_Locate_80038B34(200, 150, 0x10);
            MENU_Color_80038B4C(192, 192, 192);
            MENU_Printf_80038C38(title_aNo_800D9024);

            title_open_800C4F1C(work, 28, 33, 40, 15, 255, 1);
        }
    }

    title_open_800C47B8(work, arg1);
}

#pragma INCLUDE_ASM("asm/overlays/title/OpenAct_800D37F4.s")
void OpenAct_800D37F4(OpenWork *work);

void OpenDie_800D4098(OpenWork *work)
{
    DG_PRIM *prim;
    int      i;
    void    *buf;

    prim = work->prim[0];
    if (prim != NULL)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }

    prim = work->prim[2];
    if (prim != NULL)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }

    prim = work->prim[3];
    if (prim != NULL)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }

    prim = work->prim[1];
    if (prim != NULL)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }

    for (i = 0; i < 24; i++)
    {
        buf = title_open_800C4B20(&work->kcb[i]);
        GV_FreeMemory_80015FD0(2, buf);
    }
}

void title_open_800D4174(OpenWork *work, POLY_FT4 *poly, int x0, int y0, int x1, int y1, int abe)
{
    setPolyFT4(poly);
    setRGB0(poly, 128, 128, 128);
    setXY4(poly, x0, y0, x1, y0, x0, y1, x1, y1);
    SetSemiTrans(poly, abe);
}

static inline void title_open_helper_800D41E4(POLY_FT4 *poly, DG_TEX *tex, int uo, int vo)
{
    int u0, u1;
    int v0, v1;

    u0 = tex->field_8_offx;
    u1 = u0 + tex->field_A_width + uo;
    v0 = tex->field_9_offy;
    v1 = v0 + tex->field_B_height + vo;
    setUV4(poly, u0, v0, u1, v0, u0, v1, u1, v1);

    poly->tpage = tex->field_4_tPage;
    poly->clut = tex->field_6_clut;
}

void title_open_800D41E4(OpenWork *work, int name, POLY_FT4 *poly, int x0, int y0, int x1, int y1, int abe, int type)
{
    DG_TEX *tex;

    title_open_800D4174(work, poly, x0, y0, x1, y1, abe);

    tex = DG_GetTexture_8001D830(name);
    if (type == 0)
    {
        title_open_helper_800D41E4(poly, tex, 1, 1);
    }
    else if (type == 1)
    {
        title_open_helper_800D41E4(poly, tex, 1, 0);
    }
    else if (type == 2)
    {
        title_open_helper_800D41E4(poly, tex, 0, 1);
    }
    else if (type == 3)
    {
        title_open_helper_800D41E4(poly, tex, 0, 0);
    }
}

void title_open_800D4368(OpenWork *work, int name, POLY_FT4 *poly, int x0, int y0, int x1, int y1, int abe)
{
    DG_TEX *tex;
    int     u0, u1;
    int     v0, v1;

    tex = DG_GetTexture_8001D830(name);

    setPolyFT4(poly);

    u0 = tex->field_8_offx;
    u1 = u0 + tex->field_A_width + 1;
    v0 = tex->field_9_offy;
    v1 = v0 + tex->field_B_height + 1;
    setUV4(poly, u0, v0, u1, v0, u0, v1, u1, v1);

    poly->tpage = tex->field_4_tPage;
    poly->clut = tex->field_6_clut;

    setRGB0(poly, 0, 0, 0);
    setXY4(poly, x0, y0, x1, y0, x0, y1, x1, y1);
    SetSemiTrans(poly, abe);
}

void title_open_800D4464(OpenWork *work, int name, POLY_GT4 *poly, int x0, int y0, int x1, int y1, int abe)
{
    DG_TEX *tex;
    int     u0, u1;
    int     v0, v1;

    tex = DG_GetTexture_8001D830(name);

    setPolyGT4(poly);

    u0 = tex->field_8_offx;
    u1 = u0 + tex->field_A_width + 1;
    v0 = tex->field_9_offy;
    v1 = v0 + tex->field_B_height + 1;
    setUV4(poly, u0, v0, u1, v0, u0, v1, u1, v1);

    poly->tpage = tex->field_4_tPage;
    poly->clut = tex->field_6_clut;

    setRGB0(poly, 0, 0, 0);
    setRGB1(poly, 0, 0, 0);
    setRGB2(poly, 0, 0, 0);
    setRGB3(poly, 0, 0, 0);
    setXY4(poly, x0, y0, x1, y0, x0, y1, x1, y1);
    SetSemiTrans(poly, abe);
}

#pragma INCLUDE_ASM("asm/overlays/title/OpenGetResources_800D4584.s")
int  OpenGetResources_800D4584(OpenWork *work, int);

GV_ACT * NewOpen_800D6814(int arg0, int arg1)
{
    OpenWork *work;

    GM_GameStatus_800AB3CC |= 0x4A6000;

    work = (OpenWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(OpenWork));
    title_dword_800D92D0 = 0;

    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)OpenAct_800D37F4, (TActorFunction)OpenDie_800D4098, aOpenC);

        if (OpenGetResources_800D4584(work, arg1) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }

    return &work->actor;
}
