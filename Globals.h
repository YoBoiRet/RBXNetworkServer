
#pragma once
#include <Windows.h>
#include <pdh.h>

#define addr(Address) ((DWORD)GetModuleHandle(NULL) + Address - 0x400000) 

#define ticketsEnabled addr(0xC80B1C) 

namespace Server
{
    typedef void(__fastcall* start_t)(DWORD* _this, void*, int a2, int a3);
    extern start_t start; 
}

typedef PDH_HQUERY* (__fastcall* CProcessPerfCounter_t)(void* thisPtr);
extern CProcessPerfCounter_t CProcessPerfCounter;

