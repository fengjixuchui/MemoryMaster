#include <Windows.h>
#include <stdio.h>
#include <MemoryMaster.h>

#pragma comment(lib, "MemoryMaster.lib")

using namespace MemoryMaster;

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
) {

	if (fdwReason != DLL_PROCESS_ATTACH) {
		return TRUE;
	}

	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	SigFinder finder = SigFinder("client.dll");

	void* localPlayer = finder.Find(
		"\x48\x8B\x15\xB4\x10\x1A\x02\x48\x8D\x05\xB5\x63\x1F\x01\x00\x00\x00\x00\x00\x00\x00\x48\x85\xD2\x74\x0C",
		"xxxxxxxxxxxxxx???????xxxxx"
	);

	printf("[*] p_localPlayer = %p\n", localPlayer);

	return TRUE;
}