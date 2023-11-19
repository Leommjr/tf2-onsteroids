#include <memory>
#include <iostream>
#include <thread>
#include "vmt/vmt.h"
#include "sdk/sdk.h"
#include "sdk/entity.h"
#include "features/features.h"
#include <fstream>
#include <string>

BaseClient* clientdll{nullptr};
EntityList* entitylist{nullptr};
Entity* localplayer{nullptr};
EngineClient* engine{nullptr};
std::unique_ptr<VMTHook> clientmode_hook;

/*
static inline ClientMode* get_clientmode(void) {
    const int byte_offset = 1;

    void* func_ptr      = clientdll->HudProcessInput();
    void* g_pClientMode = *(void**)(func_ptr + byte_offset);
    ClientMode* ret     = *(ClientMode**)g_pClientMode;

    return ret;
}
*/


bool hkCreateMove(void* thisptr, float flInputSampleTime, usercmd_t* cmd) {
	/*hook createmove function from ClientMode class. It is in the 22 idx from vmt*/
	bool ret = clientmode_hook->GetOriginalFunction<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);
    localplayer = entitylist->get_entity(engine->get_local_player());
    if (!localplayer || !localplayer->is_alive())
        return ret;

    bhop(cmd);
    return ret;
}


//std::thread* thread;

__attribute__((constructor)) /* Entry point when injected */
void load(void)
{
    clientdll = GetInterface<BaseClient>(CLIENT_SO, CLIENT_DLL_INTERFACE_VERSION); // get the clientdll interface
    entitylist = GetInterface<EntityList>(CLIENT_SO, ENTITYLIST_INTERFACE_VERSION);
    engine = GetInterface<EngineClient>(ENGINE_SO, ENGINE_INTERFACE_VERSION);
    //thread = new std::thread(print_addr);
    const uintptr_t hudprocessinput{ reinterpret_cast<uintptr_t>(vmt::get_virtual_table(clientdll)[10]) };
    void* g_pClientMode{ *reinterpret_cast<void**>(reinterpret_cast<void*>(hudprocessinput) + 1)} ; //get clientmode from hudprocessinput. clientmode can be extract from global scope too
    ClientMode* client_mode{ *reinterpret_cast<ClientMode**>(g_pClientMode) };
    clientmode_hook = std::make_unique<VMTHook>(client_mode);
    clientmode_hook->HookFunction(reinterpret_cast<void*>(hkCreateMove), 22);
}

__attribute__((destructor)) /* Entry point when unloaded */
void unload()
{
    
}