#include "Game/linkvarbuf.h"
#include "menuman.h"
#include "linker.h"

extern MenuMan_Inventory_14h_Unk gMenuLeftItems_800BD5A0[];
extern menu_weapon_rpk_info      gMenuItemRpkInfo_8009E484[];

extern short                     GM_WeaponTypes_8009D580[];
extern short                     GM_ItemTypes_8009D598[];
extern int                       GM_PlayerStatus_800ABA50;
extern int                       GM_DisableItem_800ABA28;

extern int                       dword_8009F46C;

extern int                       dword_800ABAD0;
int SECTION(".sbss")             dword_800ABAD0;

void menu_sub_8003B568(void)
{
    int   imgIdx;
    u_long palIdx;
    int   i;

    for (i = 0; i < MENU_ITEMS_LEFT_COUNT; i++)
    {
        imgIdx = 0xc + i;
        palIdx = 0x2e;
        if (imgIdx != 0x16)
        {
            palIdx = 0;
            if (imgIdx == 0x1b)
            {
                palIdx = 0x2f;
            }
        }
        menu_init_rpk_item_8003DDCC(&gMenuLeftItems_800BD5A0[i], imgIdx, palIdx);
    }
}

MenuMan_Inventory_14h_Unk * menu_rpk_8003B5E0(int index)
{
    return &gMenuLeftItems_800BD5A0[gMenuItemRpkInfo_8009E484[index].field_4_rpk_idx - 12];
}

// https://decomp.me/scratch/txHAy
// G0 function in a G8 file
#pragma INCLUDE_ASM("asm/menu_8003B614.s") // 188 bytes

int menu_inventory_Is_Item_Disabled_8003B6D0(int item)
{
    int bit;
    
    if ((GM_WeaponTypes_8009D580[GM_CurrentWeaponId + 1] & 0x200) &&
        (GM_ItemTypes_8009D598[item + 1] & 1))
    {
        return 1;
    }

    if (GM_PlayerStatus_800ABA50 & 0x42)
    {
        if ((item == ITEM_C_BOX_A) ||
            (item == ITEM_C_BOX_B) ||
            (item == ITEM_C_BOX_C))
        {     
            return 1;   
        }
    }

    if (dword_8009F46C != 0)
    {
        if ((item == ITEM_SCOPE)   ||
            (item == ITEM_C_BOX_A) ||
            (item == ITEM_C_BOX_B) ||
            (item == ITEM_C_BOX_C) ||
            (item == ITEM_CAMERA))
        {
            return 1;
        }
    }

    bit = 1 << item;
    return (GM_DisableItem_800ABA28 & bit) != 0;
}

#pragma INCLUDE_ASM("asm/menu_8003B794.s") // 348 bytes
#pragma INCLUDE_ASM("asm/menu_inventory_left_helper_8003B8F0.s") // 764 bytes

#pragma INCLUDE_ASM("asm/menu_8003BBEC.s") // 232 bytes

#pragma INCLUDE_ASM("asm/menu_inventory_left_update_helper_8003BCD4.s") // 584 bytes
#pragma INCLUDE_ASM("asm/menu_inventory_left_update_helper2_8003BF1C.s") // 816 bytes
#pragma INCLUDE_ASM("asm/menu_inventory_left_update_helper3_8003C24C.s") // 672 bytes
#pragma INCLUDE_ASM("asm/menu_inventory_left_update_helper4_8003C4EC.s") // 1136 bytes
#pragma INCLUDE_ASM("asm/menu_inventory_left_update_8003C95C.s") // 572 bytes

int sub_8003CB98(struct Actor_MenuMan *pActor)
{
    int field_0_item_id_idx; // $a0
    MenuMan_Inventory_14h_Unk *pItem; // $v0
    int result;

    menu_restore_nouse_80043470();
    field_0_item_id_idx = pActor->field_1DC_menu_left.field_0.field_0_item_id_idx;
    result = -1;
    if ( field_0_item_id_idx != -1
      || (field_0_item_id_idx = pActor->field_1DC_menu_left.field_11, field_0_item_id_idx != -1) )
    {
        pItem = menu_rpk_8003B5E0(field_0_item_id_idx);
        result = sub_8003CFE0(pItem, 0);
    }
    return result;
}

void menu_inventory_left_8003CBF0(struct Actor_MenuMan *menuMan)
{
    short val = -1;
    menuMan->m7FnPtrs_field_2C[2] = (TMenuUpdateFn)menu_inventory_left_update_8003C95C;
    menuMan->field_1DC_menu_left.field_0.field_0_item_id_idx = val;
    menuMan->field_1DC_menu_left.field_10 = 0;
    menuMan->field_1DC_menu_left.field_0.field_4 = 0;
    menuMan->field_1DC_menu_left.field_0.field_6 = 1;
    menuMan->field_1DC_menu_left.field_11 = val;
    menuMan->field_28_flags |= 4;
    dword_800ABAD0 = 0;
    sub_8003D6A8(&menuMan->field_1DC_menu_left, 0, (int *)menu_inventory_left_helper_8003B8F0);
    menu_sub_8003B568();
    sub_8003CB98(menuMan);
    menu_init_nouse_800434A8();
}

void menu_left_kill_8003CC74(Actor_MenuMan *pMenu)
{
    pMenu->field_28_flags &= ~4u;
}
