#include "Server.h"

void __fastcall NetworkServerstart_hook(DWORD* _this, void*, int port, int a3)
{
    *(char*)ticketsEnabled = 1; // this gets auto disabled on rbxapp clients ig so we gotta enable it
    
    Server::start(_this, nullptr, port, a3);

    if (GetConsoleWindow())
        ShowWindow(GetConsoleWindow(), SW_SHOW);

    printf("started network server on port %d\n", port);
}
