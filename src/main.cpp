#include <windows.h>
#include <thread>

#include "console.hpp"


BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        DisableThreadLibraryCalls(hModule);

        std::thread([]()
        {
            IW8Console();

        }).detach();

        break;

    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}