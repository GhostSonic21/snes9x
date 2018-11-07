#include "apu/apu.h"
//#include "port.h"
//#include "memmap.h"
#include "getset.h"

const bool musicListSMW_Vanilla[] = {
	false, false, false, false, false,		// 00 - 04
	false, false, false, false, true,		// 05 - 09
	true, false, false, true, true,			// 0A - 0E
	true, true, true, false, false,			// 0F - 13
	false, false, false, true, true,		// 14 - 18
	false, false, true, false, false,		// 19 - 1D
	false, false
};

enum MusicEngine {
	Disabled,
	SMW_Vanilla,
	SMW_Musik
};



struct MusicStatus {
	MusicEngine engine = Disabled;
	bool disabled = false;
	uint8 currentVolume = 0;
};

void setMusicEngine(MusicEngine);
MusicEngine getCurrentMusicEngine();
bool toggleMusicDisable();
bool getMusicDisabled();
uint8 volumeFilter(uint8, uint16);

// Might not use classes
/*#pragma once
class MusicSilencer
{
public:
	MusicSilencer();
	~MusicSilencer();
};*/

