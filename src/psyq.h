#ifndef _PSYQ_H_
#define _PSYQ_H_

#include <SYS/TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>
#include <LIBSPU.H>

void SpuSetCommonAttr_80097038(SpuCommonAttr *attr);

DISPENV       *PutDispEnv_80090094(DISPENV *env);
MATRIX        *MulMatrix0_80092A48(MATRIX *m0, MATRIX *m1, MATRIX *m2);
MATRIX        *MulRotMatrix_80092B58(MATRIX *m0);
MATRIX        *RotMatrixYXZ_80093798(SVECTOR *r, MATRIX *m);
MATRIX        *RotMatrixYXZ_gte_80094108(SVECTOR *r, MATRIX *m);
MATRIX        *RotMatrixY_80093BC8(long r, MATRIX *m);
VECTOR        *ApplyMatrixLV_80092C48(MATRIX *m, VECTOR *v0, VECTOR *v1);
void           SetTransMatrix_80093248(MATRIX *);
char          *strcpy_8008E768(char *dest, const char *src);
int            ChangeTh_800994EC(int thread);
int            LoadImage2_80091FB0(RECT *, u_long *);
int            ResetCallback_80098318(void);
int            Square0_80093340(VECTOR *, VECTOR *);
int            SquareRoot0_80092708(int);
int            StoreImage2_8009209C(RECT *, u_long *);
int            StoreImage_8008FB70(RECT *, u_long *);
int            VSync_80098108(int);
void           VSyncCallback_800983A8(void (*func)());
int            rand_8008E6B8(void);
int            ratan2_80094308(int, int);
int            rcos_800925D8(int a1);
int            rsin_80092508(int a1);
int            sprintf_8008E878(char *buffer, const char *format, ...);
int            strcmp_8008E6F8(const char *str1, const char *str2);
long           EnableEvent_800994AC(long);
long           OpenEvent_8009946C(unsigned long desc, long spec, long mode, void (*func)());
long           OpenTh_800994CC(long (*func)(), unsigned long, unsigned long);
long           SetConf_800997BC(unsigned long, unsigned long, unsigned long);
long           StartCARD_800990F8(void);
long           TestEvent_8009949C(long);
u_long        *ClearOTagR_8008FD50(u_long *ot, int n);
unsigned int   GetRCnt_800996E8(unsigned int rcnt);
unsigned short GetTPage_80092418(int tp, int abr, int x, int y);
void           SetDrawTPage_800924A8(DR_TPAGE *p, int dfe, int dtd, int tpage);
void           CloseEvent_8009947C(int event);
void           DrawOTag_8008FE58(unsigned int *pOt);
void           DrawPrim_8008FDFC(void *p);
void           DrawSyncCallback_8008F76C(void *);
void           EnterCriticalSection_8009952C(void);
void           ExitCriticalSection_8009953C(void);
void           InitCARD_8009908C(long val);
void           LoadImage_8008FB10(RECT *, unsigned char *);
void           OuterProduct12_800933AC(VECTOR *v0, VECTOR *v1, VECTOR *v2);
void           PutDrawEnv_8008FEC8(DRAWENV *);
void           ReadRotMatrix_80092DD8(MATRIX *m);
void           SetDrawEnv_800906B0(DR_ENV *dr_env, DRAWENV *env);
void           SetMem_8009944C(int);
void           SetRotMatrix_80093218(MATRIX *m);
void           StopCARD_80099130(void);
void           SwEnterCriticalSection_8009954C(void);
void           SwExitCriticalSection_8009956C(void);
void           VectorNormal_80092838(VECTOR *v0, VECTOR *v1);
void          *memset_8008E688(void *pSrc, int value, int len);
void           SetDispMask_8008F7CC(int);
void           InitGeom_80092680(void);
void           PadInitDirect_8009C6CC(unsigned char *pad1, unsigned char *pad2);
void           PadSetAct_8009A678(int port, unsigned char *data, int len);
void           PadStartCom_8009A22C(void);
void           StopPAD_80099F08(void);
void           ChangeClearPAD_8009960C(long val);
int            strlen_8008E7B8(char *s);
void          *memcpy_8008E648(void *destination, const void *source, int num);
int            erase_800995FC(char *);
long           card_read_8009901C(long chan, long block, unsigned char *buf);
void           bu_init_80098FEC(void);
int            ResetGraph(int mode);
void           SpuSetKey_80096C18(int, int);
long           RotTransPers_80093478(SVECTOR *v0, long *sxy, long *p, long *flag);
long           LoadExec_8009940C(char *, unsigned long, unsigned long);
void           SpuGetAllKeysStatus_8009748C(char *status);
void           _96_init_8009941C(void);
void           _96_remove_80099434(void);
void           StopCallback_8009840C(void);
long           SpuSetIRQ_80096A28(long on_off);
void           StrFadeIn_800822C8(unsigned int a1);
int            StrFadeOutStop_80082380(unsigned int fadeSpeed);
int            SePlay_800888F8(int a1);
int            StrFadeOut_80082310(unsigned int a1);
int            CdInit(void); // TODO: needs address
void           SpuInit_80094568(void);
void           PadStopCom_8009A24C(void);

struct DIRENTRY *firstfile_80099AEC(char *, struct DIRENTRY *);
struct DIRENTRY *nextfile_800995EC(struct DIRENTRY *);

#endif // _PSYQ_H_
