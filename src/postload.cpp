#include "common.hpp"
#include "utils/hooks.h"
#include "console.hpp"

namespace
{
	void* scan_pattern(const char* pattern, const char* mask)
	{
		auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
		MODULEINFO module_info = {};
		GetModuleInformation(GetCurrentProcess(), reinterpret_cast<HMODULE>(base), &module_info, sizeof(module_info));

		auto size = module_info.SizeOfImage;
		auto pattern_len = strlen(mask);

		for (uintptr_t i = 0; i < size - pattern_len; i++)
		{
			bool found = true;
			for (uintptr_t j = 0; j < pattern_len; j++)
			{
				if (mask[j] == 'x' && pattern[j] != *reinterpret_cast<char*>(base + i + j))
				{
					found = false;
					break;
				}
			}
			if (found) return reinterpret_cast<void*>(base + i);
		}
		return nullptr;
	}
}

 // sets the sign in state for mw19
 
 

// E8 ? ? ? ? 84 C0 75 ? 45 84 FF live is in systemlink lobby

 void mainmenuoffline()
{
    LUI_OpenMenu("MainMenuOffline");
}
void LUI_OpenMenu(const char* menu)
{	// 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 41 8B F1 41 8B D8
	// 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 41 8B F1 41 8B D8
	auto func = reinterpret_cast<void* (*)(int a1, const char* menu, int a3, int a4, int a5)>(
		scan_pattern("\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x00\x41\x8B\xF1\x41\x8B\xD8", "xxxx?xxxx?xxx?xxxxxx")
	);

	if (func) func(0, menu, 0, 0, 0);
}