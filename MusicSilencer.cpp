/***********************************************************************************
  MusicSilencer
  Copyright (c) 2018 GhostSonic

  Permission to use, copy, modify and/or distribute Snes9x in both binary
  and source form, for non-commercial purposes, is hereby granted without
  fee, providing that this license information and copyright notice appear
  with all copies and any derived work.

  This software is provided 'as-is', without any express or implied
  warranty. In no event shall the authors be held liable for any damages
  arising from the use of this software or it's derivatives.

  Snes9x is freeware for PERSONAL USE only. Commercial users should
  seek permission of the copyright holders first. Commercial use includes,
  but is not limited to, charging money for Snes9x or software derived from
  Snes9x, including Snes9x or derivatives in commercial game bundles, and/or
  using Snes9x as a promotion for your commercial product.

  The copyright holders request that bug fixes and improvements to the code
  should be forwarded to them so everyone can benefit from the modifications
  in future versions.

  Super NES and Super Nintendo Entertainment System are trademarks of
  Nintendo Co., Limited and its subsidiary companies.
***********************************************************************************/


#include "MusicSilencer.h"

MusicStatus musicStatus;


uint8 volumeFilter(uint8 data, uint16 addr) {
	uint8 returnData = data;
	
	// Vanilla
	if (musicStatus.engine == SMW_Vanilla && addr == 0x57) {
		if (musicStatus.disabled) {
			// Find song and see if it's fine
			uint8 songRead = S9xAPUGetByte(0x0006);
			if (!musicListSMW_Vanilla[songRead]) {
				returnData = 0;
			}
		}
	}
	// MusicK
	else if (musicStatus.engine == SMW_Musik && addr == 0x57) {
		// Find song and see if it's fine
		if (musicStatus.disabled) {
			uint8 songRead = S9xGetByteFree(0x1dfb);
			// Simple
			if (songRead > 9) {
				returnData = 0;
			}
		}
	}
	return returnData;
}

void setMusicEngine(MusicEngine engine) {
	musicStatus.engine = engine;
	// Set callback (ugly way of doing this but it's getting fucky)
	if (musicStatus.engine != Disabled) {
		S9xAPUSetWriteCallback(volumeFilter);
	}
}

bool toggleMusicDisable() {
	if (musicStatus.engine != Disabled) {
		musicStatus.disabled = !musicStatus.disabled;
		if (musicStatus.disabled) {
			// Message
			S9xMessage(S9X_INFO, 0, "Music Disabled");
		}
		// Turn on immediatley
		else {
			// Message
			S9xMessage(S9X_INFO, 0, "Music Enabled");
		}
	}
	else {
		S9xMessage(S9X_INFO, 0, "Set the Music Engine First");
	}
	return musicStatus.disabled;
}

bool getMusicDisabled() {
	return musicStatus.disabled;
}

MusicEngine getCurrentMusicEngine() {
	return musicStatus.engine;
}