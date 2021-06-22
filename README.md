# uloader
A .3dsx app that launches an embedded [universal-otherapp](https://github.com/TuxSH/universal-otherapp). This allows universal-otherapp to work with entrypoints that don't (or can't) load otherapp.bin from the sdmc (like ninjhax). Only tested on latest firm, US region.

# Credits
* Yellows8 - this is mostly a stripped down version of https://github.com/yellows8/hblauncher_loader
* TuxSH - the creator of https://github.com/TuxSH/universal-otherapp.

# Directions
This works exactly like universal-otherapp, other than you launch the uloader.3dsx from hbmenu to trigger it.<br>
1. Create boot9strap folder on sdmc root.
2. Download https://github.com/SciresM/boot9strap/releases/tag/1.3 (boot9strap.firm and boot9strap.firm.sha) and place them inside the boot9strap folder.
3. Download https://github.com/d0k3/SafeB9SInstaller/releases/tag/v0.0.7 and place SafeB9SInstaller.bin on the sdmc root. Note the .bin file extension, only use that one.
4. Download https://github.com/LumaTeam/Luma3DS/releases/tag/v10.2.1 and place boot.firm on the sdmc root.
5. Run uloader.3dsx, this should eventually launch SafeB9SInstaller which will walk you through installing boot9strap (perm cfw).<br>

Note: these instructions aren't meant to be complete or exhaustive in any way - they're only for experienced users. Beginners/novices should stick to https://3ds.hacks.guide for 3ds cfw install instructions (which won't include uloader).

# Compile tips
You need a local copy of libctru with the following small change:<br>
static Handle gspGpuHandle --> Handle gspGpuHandle<br>
https://github.com/devkitPro/libctru/blob/master/libctru/source/services/gspgpu.c#L15<br>
This copy is already included here, but lacks source code.