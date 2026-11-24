#include "Server.h"

void __fastcall NetworkServerstart_hook(DWORD* _this, void*, int port, int a3)
{
    Server::start(_this, nullptr, port, a3);

    if (GetConsoleWindow())
        ShowWindow(GetConsoleWindow(), SW_SHOW);

    printf("started network server on port %d\n", port);
}