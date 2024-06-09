#include "common/IPrefix.h"
#include "common/PluginAPI.h"
#include "SafeWrite.h"

extern "C" {
	__declspec(dllexport) bool FOSEPlugin_Query(const FOSEInterface* fose, PluginInfo* info) {
		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = "F3TripleBuffering";
		info->version = 100;
		return true;
	}

	__declspec(dllexport) bool FOSEPlugin_Load(FOSEInterface* fose) {
		if (!fose->isEditor) {
			SafeWriteBuf(0x4905FD, (void*)"\xBA\x02\x00\x00\x00\x90", 6);
		}

		return true;
	}
}
