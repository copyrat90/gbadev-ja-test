#ifndef __MEM_H__
#define __MEM_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "../libgba/gba.h"


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
typedef struct {
	u32 dummy ALIGN(4);

} ST_MEM;


//---------------------------------------------------------------------------
EWRAM_CODE void MemInit(void);

EWRAM_CODE void MemInc(void* src, void* dst, u32 size);
EWRAM_CODE void MemFix(void* src, void* dst, u32 size);
EWRAM_CODE void MemClear(void* dst, u32 size);

EWRAM_CODE void MemIncFast(void* src, void* dst, u32 size);
EWRAM_CODE void MemFixFast(void* src, void* dst, u32 size);


#ifdef __cplusplus
}
#endif
#endif
