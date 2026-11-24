#include "pch.h"
#include <thread>
#include "detours.h"
#include "Server.h"
#include "Globals.h"
#include <pdh.h>


PDH_HQUERY* __fastcall CProcessPerfCounter_hook(void* thisPtr)
{
    static PDH_HQUERY d = nullptr;
    return &d;
}

void InitConsole()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
    SetConsoleTitleA("RBXNetworkServer DEBUG");

    ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void main()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)Server::start, NetworkServerstart_hook);
    DetourAttach(&(PVOID&)CProcessPerfCounter, CProcessPerfCounter_hook);
    DetourTransactionCommit();
}

__declspec(dllexport) void __cdecl xD(bool) {}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (RBXNetworkServer::Debug)
            InitConsole();

        std::thread(main).detach();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
