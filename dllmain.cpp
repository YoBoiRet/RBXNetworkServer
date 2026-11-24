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

void enableTickets()
{
    CreateThread(nullptr, 0, [](LPVOID) -> DWORD {
        char lastValue = *(char*)ticketsEnabled;

        while (true)
        {
            char current = *(char*)ticketsEnabled;

            if (current != lastValue)
            {
                printf("changed: %d -> %d\n", lastValue, current);
                lastValue = current;
            }

            *(char*)ticketsEnabled = 1;
            Sleep(1);
        }

        return 0;
        }, nullptr, 0, nullptr);
}

void main()
{
    printf("enabled tickets\n");
    enableTickets();

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