#include "linker.h"
#include "libgv/libgv.h"
#include "Game/game.h"
#include "libdg/libdg.h"
#include "libgcl/hash.h"
#include "libgcl/libgcl.h"

/*
TODO:
    Matched on decomp.me, pipeline not set up to match overlays yet
*/

extern int          GV_Time_800AB330;
extern int          GM_AlertMode_800ABA00;
extern unsigned int GM_PlayerStatus_800ABA50;
extern OBJECT      *dword_800ABA20;

extern void sub_800C3AA8( DG_OBJ *obj );

#define EXEC_LEVEL 5 //goes in libgv.h
#define DEFAULT_TIME 0x40

typedef struct _BreathWork
{
    GV_ACT         actor;
    unsigned short name;
    unsigned short visible;
    int            time;
} BreathWork;


void BreathAct_800C38A0( BreathWork* work )
{
    GV_MSG    *message;
    int        message_result;
    OBJECT    *object;

    message_result = GV_ReceiveMessage_80016620( work->name, &message );

    for (; message_result > 0 ; --message_result, ++message )
    {
        switch ( message->message[0] )
        {
            case HASH_ENTER:
                work->visible = 1;
                break;
            default:
                work->visible = 0;
        }
    }

    if ( work->visible && GM_AlertMode_800ABA00 != 3 && !( GM_PlayerStatus_800ABA50 & 0x2013 ) )
    {
        object = dword_800ABA20;
        if  ( object != NULL && ( GV_Time_800AB330 % work->time == 0 ) )
        {
            sub_800C3AA8( &object->objs->objs[6] );
        }
    }
}


void BreathDie_800C39AC( BreathWork* work )
{
    return;
}


int BreathGetResources_800C39B4( BreathWork *work, int name, int where )
{
    if (GCL_GetOption_80020968('t'))
    {
         work->time = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }
    else
    {
        work->time = DEFAULT_TIME;
    }

    work->name = name;
    work->visible = 1;
    return 0;
}

void        *NewBreath_800C3A1C( int name, int where, int argc, char **argv )
{
    BreathWork        *work ;


    work = (BreathWork *)GV_NewActor_800150E4( EXEC_LEVEL, sizeof( BreathWork ) ) ;
    if ( work != NULL ) {
        /* ワークにコールバックを登録する */
        GV_SetNamedActor_8001514C( &( work->actor ), ( TActorFunction )BreathAct_800C38A0, ( TActorFunction )BreathDie_800C39AC, "breath.c" ) ;
        if ( BreathGetResources_800C39B4( work, name, where ) >= 0 ) {
            return (void *)work ;
        }
        GV_DestroyActor_800151C8( &work->actor ) ;
    }
    return NULL ;
}