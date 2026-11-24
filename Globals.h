
#pragma once
#include <Windows.h>
#include <pdh.h>

#define addr(Address) ((DWORD)GetModuleHandle(NULL) + Address - 0x400000) // not required for a version this old

#define ticketsEnabled addr(0xC80B1C) // search "missing ticket" then scroll to the top "result = sub_4DEE60();"


namespace ServerReplicator
{
    /*
    typedef void(__fastcall* SendTop_t)(ServerReplicatorOwn* _this, void*, RakPeerInterface* peer);
    extern SendTop_t SendTop;

    typedef void(__fastcall* ProcessTicket_t)(ServerReplicatorOwn* _this, void*, Packet* packet);
    extern ProcessTicket_t ProcessTicket; // search "Player %d is already in the world"

    typedef int(__fastcall* OnReceive_t)(ServerReplicatorOwn* _this, void*, Packet* packet);
    extern OnReceive_t OnReceive; // search "Received remotePlayer %s from %s"
    */

}

namespace Server
{
    typedef void(__fastcall* start_t)(DWORD* _this, void*, int a2, int a3);
    extern start_t start; 
}

typedef PDH_HQUERY* (__fastcall* CProcessPerfCounter_t)(void* thisPtr);
extern CProcessPerfCounter_t CProcessPerfCounter;

/*
SendTop:
 sub_59F650(*v6, 1, "New connection from %s\n", v8);
      v9 = v29;
      LOBYTE(v35) = 2;
      if ( v29 )
      {
        if ( !_InterlockedExchangeAdd(v29 + 1, 0xFFFFFFFF) )
        {
          (*(void (__thiscall **)(volatile signed __int32 *))(*v9 + 4))(v9);
          if ( !_InterlockedExchangeAdd(v9 + 2, 0xFFFFFFFF) )
            (*(void (__thiscall **)(volatile signed __int32 *))(*v9 + 8))(v9);
        }
      }
      LOBYTE(v35) = 1;
      std::string::~string(v25);
      v10 = this - 148;
      v11 = (int *)sub_4D9460(v26, *(_DWORD *)v33, *((_DWORD *)v33 + 1), v10);
      v30 = *v11;
      LOBYTE(v35) = 4;
      sub_402120(v11 + 1);
      v12 = v27;
      LOBYTE(v35) = 1;
      if ( v27 )
      {
        if ( !_InterlockedExchangeAdd(v27 + 1, 0xFFFFFFFF) )
        {
          (*(void (__thiscall **)(volatile signed __int32 *))(*v12 + 4))(v12);
          if ( !_InterlockedExchangeAdd(v12 + 2, 0xFFFFFFFF) )
            (*(void (__thiscall **)(volatile signed __int32 *))(*v12 + 8))(v12);
        }
      }
      v13 = v30;
      sub_597BC0(v10);
      v23 = a2;
      *(_BYTE *)(v13 + 117) = 1;
      sub_506910(v13, v23); <-- dis it!!!
*/
