#include "linker.h"


int s03b_dword_800C3290 = 0x027F0200;
int s03b_dword_800C3294 = 0x00000000;
int s03b_dword_800C3298 = 0x00000E46;
int s03b_dword_800C329C = 0x067F0200;
int s03b_dword_800C32A0 = 0x047F1400;
int s03b_dword_800C32A4 = 0x047F1600;
int s03b_dword_800C32A8 = 0x00000000;
int s03b_dword_800C32AC = 0x0C280E5A;
int s03b_dword_800C32B0 = 0x0C280E46;
int s03b_dword_800C32B4 = 0x00001450;
int s03b_dword_800C32B8 = 0x017F0100;
int s03b_dword_800C32BC = 0x027F7600;
int s03b_dword_800C32C0 = 0x00000000;
int s03b_dword_800C32C4 = 0x0A320455;
int s03b_dword_800C32C8 = 0x047D6A28;
int s03b_dword_800C32CC = 0x00000000;
int s03b_dword_800C32D0 = 0x3200077F;
int s03b_dword_800C32D4 = 0x0000027F;
int s03b_dword_800C32D8 = 0x0A3C04FF;
int s03b_dword_800C32DC = 0x1C1E0C28;
int s03b_dword_800C32E0 = 0x000004A0;

int s03b_dword_800C32E4 = 0x4B5D0000;
int s03b_dword_800C32E8 = 0x00000002;
int s03b_dword_800C32EC = 0x937AFFFF;
int s03b_dword_800C32F0 = 0x00010000;
int s03b_dword_800C32F4 = 0xE2E9FFFF;
int s03b_dword_800C32F8 = 0x00010000;

int s03b_dword_800C32FC = 0x00000000;
int s03b_dword_800C3300 = 0x00000001;
int s03b_dword_800C3304 = 0x00000002;
int s03b_dword_800C3308 = 0x00000018;
int s03b_dword_800C330C = 0x00000011;
int s03b_dword_800C3310 = 0x00000012;
int s03b_dword_800C3314 = 0x00000013;
int s03b_dword_800C3318 = 0x00000014;
int s03b_dword_800C331C = 0x00000017;
int s03b_dword_800C3320 = 0x00000015;
int s03b_dword_800C3324 = 0x00000016;
int s03b_dword_800C3328 = 0x00000019;
int s03b_dword_800C332C = 0x0000001A;
int s03b_dword_800C3330 = 0xFFFFFFFF;

int s03b_dword_800C3334 = 0x800D2F58;
int s03b_dword_800C3338 = 0x800D2F54;
int s03b_dword_800C333C = 0x800D2F50;
int s03b_dword_800C3340 = 0x800D2F4C;
int s03b_dword_800C3344 = 0x800D2F48;
int s03b_dword_800C3348 = 0x800D2F44;
int s03b_dword_800C334C = 0x800D2F40;
int s03b_dword_800C3350 = 0x800D2F3C;
int s03b_dword_800C3354 = 0x800D2F38;
int s03b_dword_800C3358 = 0x800D2F34;
int s03b_dword_800C335C = 0x800D2F30;
int s03b_dword_800C3360 = 0x800D2F2C;
int s03b_dword_800C3364 = 0x800D2F28;
int s03b_dword_800C3368 = 0x800D2F24;
int s03b_dword_800C336C = 0x00000000;
int s03b_dword_800C3370 = 0x00000000;
int s03b_dword_800C3374 = 0xFFFFFFFF;
int s03b_dword_800C3378 = 0xFFFFFFFF;
int s03b_dword_800C337C = 0x00000000;
int s03b_dword_800C3380 = 0x00000000;
int s03b_dword_800C3384 = 0x00000000;
int s03b_dword_800C3388 = 0x00000000;
int s03b_dword_800C338C = 0x00000000;
int s03b_dword_800C3390 = 0x00000000;
int s03b_dword_800C3394 = 0x00000000;
int s03b_dword_800C3398 = 0x00000000;

const char s03b_dword_800D2E5C[] = "拷問台";
const char s03b_aTurn_800D2E64[] = "turn";
const char s03b_aLeave_800D2E6C[] = "leave";
const char s03b_dword_800D2E74[] = "リキッド";
const char s03b_dword_800D2E80[] = "オセロット";
const char s03b_aTime_800D2E8C[] = "Time";
const int s03b_dword_800D2E94 = 0x800C47B4;
const int s03b_dword_800D2E98 = 0x800C481C;
const int s03b_dword_800D2E9C = 0x800C4854;
const int s03b_dword_800D2EA0 = 0x800C4890;
const int s03b_dword_800D2EA4 = 0x800C48C8;
const int s03b_dword_800D2EA8 = 0x800C49A8;
const char s03b_aMode_800D2EAC[] = "mode";
const char s03b_aGoubg_800D2EB4[] = "gou_bg";
const char s03b_aGoumon_800D2EBC[] = "goumon";
