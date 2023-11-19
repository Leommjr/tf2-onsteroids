#pragma once

#include "../vmt/vmt.h"
#include <dlfcn.h>

//libs paths
#define CLIENT_SO "./tf/bin/client.so"
#define ENGINE_SO "./bin/engine.so"
//interfaces versions
#define CLIENT_DLL_INTERFACE_VERSION "VClient017"
#define ENGINE_INTERFACE_VERSION "VEngineClient014"

//data
typedef struct {
    float x, y;
} vec2_t;

typedef struct {
    float x, y, z;
} vec3_t;

typedef struct {
    float m[4][4];
} VMatrix;

enum in_buttons {
    IN_ATTACK    = (1 << 0),
    IN_JUMP      = (1 << 1),
    IN_DUCK      = (1 << 2),
    IN_FORWARD   = (1 << 3),
    IN_BACK      = (1 << 4),
    IN_USE       = (1 << 5),
    IN_CANCEL    = (1 << 6),
    IN_LEFT      = (1 << 7),
    IN_RIGHT     = (1 << 8),
    IN_MOVELEFT  = (1 << 9),
    IN_MOVERIGHT = (1 << 10),
    IN_ATTACK2   = (1 << 11),
    IN_RUN       = (1 << 12),
    IN_RELOAD    = (1 << 13),
    IN_ALT1      = (1 << 14),
    IN_ALT2      = (1 << 15),
    IN_SCORE     = (1 << 16),
    IN_SPEED     = (1 << 17),
    IN_WALK      = (1 << 18),
    IN_ZOOM      = (1 << 19),
    IN_WEAPON1   = (1 << 20),
    IN_WEAPON2   = (1 << 21),
    IN_BULLRUSH  = (1 << 22),
    IN_GRENADE1  = (1 << 23),
    IN_GRENADE2  = (1 << 24),
    IN_ATTACK3   = (1 << 25),
};

typedef struct {
    void* vmt;
    int command_number;
    int tick_count;
    vec3_t viewangles;
    float forwardmove;
    float sidemove;
    float upmove;
    int buttons;
    uint8_t impulse;
    int weaponselect;
    int weaponsubtype;
    int random_seed;
    short mousedx;
    short mousedy;
    bool hasbeenpredicted;
} usercmd_t;


typedef void* (*CreateInterfaceFn) (const char*, int*);
typedef bool (*CreateMoveFn) (void*, float, usercmd_t*);


template <typename interface> interface* GetInterface(const char* filename, const char* version) {
	void* library = dlopen(filename, RTLD_NOLOAD | RTLD_NOW);

	if (!library)
		return nullptr;

	void* createinterface_sym = dlsym(library, "CreateInterface");

	if (!createinterface_sym)
		return nullptr;

	CreateInterfaceFn factory = reinterpret_cast<CreateInterfaceFn>(createinterface_sym);

	return reinterpret_cast<interface*>(factory(version, nullptr));
}

class BaseClient
{
    /*
    public:
        void HudProcessInput(bool bActive)
        {
            return vmt::get_virtual_function<void(*)(void*, bool)>(this, 10)(this, bActive);
        }
    */
};

class ClientMode
{
    /*
    public:
        bool CreateMove(float flInputSampleTime, usercmd_t* cmd)
        {
            return vmt::get_virtual_function<bool(*)(void*, float, usercmd_t*)>(this, 22)(this, flInputSampleTime, cmd);
        }
    */
};

class EngineClient
{
    public:
        void get_screen_size(int* width, int* height)
        {
            return vmt::get_virtual_function<void(*)(void*, int*, int*)>(this, 5)(this, width, height);
        }
        int get_local_player()
        {
            return vmt::get_virtual_function<int(*)(void*)>(this, 12)(this);
        }
        void get_view_angles(vec3_t* angles)
        {
            return vmt::get_virtual_function<void(*)(void*, vec3_t*)>(this, 19)(this, angles);
        }
        void set_view_angles(vec3_t* angles)
        {
            return vmt::get_virtual_function<void(*)(void*, vec3_t*)>(this, 20)(this, angles);
        }
        VMatrix* world_to_screen_matrix()
        {
            return vmt::get_virtual_function<VMatrix*(*)(void*)>(this, 36)(this);
        }
};
