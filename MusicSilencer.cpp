#include "MusicSilencer.h"


/*MusicSilencer::MusicSilencer()
{
}


MusicSilencer::~MusicSilencer()
{
}
*/
MusicStatus musicStatus;


uint8 volumeFilter(uint8 data, uint16 addr) {
	uint8 returnData = data;
	
	// Vanilla
	if (musicStatus.engine == SMW_Vanilla && addr == 0x57) {
		// Save volume
		musicStatus.currentVolume = data;
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
		// Save volume
		musicStatus.currentVolume = data;
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
	musicStatus.disabled = !musicStatus.disabled;
	// Turn off immediatley
	if (musicStatus.engine != Disabled) {
		if (musicStatus.disabled) {
			// Resave the volume just in case
			musicStatus.currentVolume = S9xAPUGetByte(0x57);
			// Turn it off if applicable
			S9xAPUSetByte(volumeFilter(musicStatus.currentVolume,0x57), 0x57);
			// Message
			S9xMessage(S9X_INFO, 0, "Music Disabled.");
		}
		// Turn on immediatley
		else {
			S9xAPUSetByte(musicStatus.currentVolume, 0x57);
			// Message
			S9xMessage(S9X_INFO, 0, "Music Enabled.");
		}
	}
	else {
		S9xMessage(S9X_INFO, 0, "Set The Music Engine First.");
	}
	return musicStatus.disabled;
}

bool getMusicDisabled() {
	return musicStatus.disabled;
}

MusicEngine getCurrentMusicEngine() {
	return musicStatus.engine;
}