#include "util/global.h"

bool getIsLockOpen()
{
	// Open the Preferences with a namespace
	preferences.begin("vinylLock", true);

	// Retrieve the saved state, default to true if not found
	int lockOpen = preferences.getBool("lockOpen", true);

	// Close Preferences
	preferences.end();

	return lockOpen;
}

void toggleLockOpen(bool lockOpen)
{
	preferences.begin("vinylLock", false);
	preferences.putBool("lockOpen", !lockOpen);
	preferences.end();
}