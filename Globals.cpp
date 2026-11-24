#include "globals.h"

//#define ticketsEnabled addr(0xC80B1C) // search "missing ticket" then scroll to the top "result = sub_4DEE60();"

/*
char sub_4DEE60()
{
    return byte_C80B1C;
}
*/

namespace ServerReplicator
{
    /*
    SendTop = (SendTop_t)addr(0x512BF0);
    ProcessTicket = (ProcessTicket_t)addr(0x5132B0);
    OnReceive = (OnReceive_t)addr(0x513880);
    */
}

namespace Server
{
    start_t start = (start_t)addr(0x4EB720); // search "Failed to start network server"
}

CProcessPerfCounter_t CProcessPerfCounter = (CProcessPerfCounter_t)addr(0x7F3990);