#include "libmy.h"
#include "mem.h"
#include "gbfs.h"
#include "key.h"
#include "sav.h"
#include "mode3.h"
#include "spr.h"
#include "fade.h"
#include "sjis.h"
#include "vgm.arm.h"
#include "snd.arm.h"
#include "irq.arm.h"
#include "lex.h"

//---------------------------------------------------------------------------
u32 LibMyVblankCnt;


//---------------------------------------------------------------------------
EWRAM_CODE void LibMyInit(void)
{
	REG_WSCNT = 0x4317;
	REG_DISPCNT = MODE_3 | BG2_ON | OBJ_ON | OBJ_1D_MAP;

	GbfsInit();
	LexInit();
	MemInit();
	KeyInit();
	SavInit();

	SprInit();
	SjisInit();
	Mode3Init();
	FadeInit();

	VgmInit();
	SndInit();

	IrqInit();
}
//---------------------------------------------------------------------------
IWRAM_CODE void LibMyExec(void)
{
	LibMyVblankCnt++;

	KeyExec();
	SprExec();
	Mode3Exec();
}
//---------------------------------------------------------------------------
EWRAM_CODE u32 LibMyGetVblankCnt(void)
{
	return LibMyVblankCnt++;
}
