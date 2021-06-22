#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <3ds.h>

#define VERSION "1.0"
extern Handle gspGpuHandle;

void gxlowcmd_4(u32* inadr, u32* outadr, u32 size, u32 width0, u32 height0, u32 width1, u32 height1, u32 flags)
{
	GX_TextureCopy(inadr, width0 | (height0<<16), outadr, width1 | (height1<<16), size, flags);
}

int otherapp(u32 *paramblk, u32 *stack);

int main(int argc, char **argv)
{
	Result ret = 0;
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL);

	printf("uloader %s by zoogie\n", VERSION);
	//ret = svcFlushProcessDataCache(0xffff8001, (u32)PAYLOAD_TEXTADDR, payloadsize_aligned);

	u32 *paramblk = linearMemAlign(0x10000, 0x1000);
	if(paramblk==NULL)
	{
		ret = 0xfe;
		printf("Failed to alloc the paramblk.\n");
		return ret;
	}
	memset(paramblk, 0, 0x10000);

	paramblk[0x1c>>2] = (u32)gxlowcmd_4;
	paramblk[0x20>>2] = (u32)GSPGPU_FlushDataCache;
	paramblk[0x48>>2] = 0x8d;//flags
	paramblk[0x58>>2] = (u32)&gspGpuHandle;
	
	otherapp(paramblk, (u32*)(0x10000000-0x1000));

	printf("Press the START button to exit.\n");  //we won't get here

	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;
	}

	gfxExit();
	return 0;
}