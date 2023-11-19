#pragma once

#include "../vmt/vmt.h"
#include "sdk.h"
#define ENTITYLIST_INTERFACE_VERSION "VClientEntityList003"

//offsets
#define velocity 0x110
#define health 0x98
#define flags 0x36c

enum entity_flags {
    FL_ONGROUND              = (1 << 0),
    FL_DUCKING               = (1 << 1),
    FL_WATERJUMP             = (1 << 2),
    FL_ONTRAIN               = (1 << 3),
    FL_INRAIN                = (1 << 4),
    FL_FROZEN                = (1 << 5),
    FL_ATCONTROLS            = (1 << 6),
    FL_CLIENT                = (1 << 7),
    FL_FAKECLIENT            = (1 << 8),
    FL_INWATER               = (1 << 9),
    FL_FLY                   = (1 << 10),
    FL_SWIM                  = (1 << 11),
    FL_CONVEYOR              = (1 << 12),
    FL_NPC                   = (1 << 13),
    FL_GODMODE               = (1 << 14),
    FL_NOTARGET              = (1 << 15),
    FL_AIMTARGET             = (1 << 16),
    FL_PARTIALGROUND         = (1 << 17),
    FL_STATICPROP            = (1 << 18),
    FL_GRAPHED               = (1 << 19),
    FL_GRENADE               = (1 << 20),
    FL_STEPMOVEMENT          = (1 << 21),
    FL_DONTTOUCH             = (1 << 22),
    FL_BASEVELOCITY          = (1 << 23),
    FL_WORLDBRUSH            = (1 << 24),
    FL_OBJECT                = (1 << 25),
    FL_KILLME                = (1 << 26),
    FL_ONFIRE                = (1 << 27),
    FL_DISSOLVING            = (1 << 28),
    FL_TRANSRAGDOLL          = (1 << 29),
    FL_UNBLOCKABLE_BY_PLAYER = (1 << 30)
};

class Entity {
    public:
        //virtual functions
        vec3_t* get_abs_origin()
        {
            return vmt::get_virtual_function<vec3_t*(*)(void*)>(this, 11)(this);
        }
        vec3_t* get_abs_angles()
        {
            return vmt::get_virtual_function<vec3_t*(*)(void*)>(this, 12)(this);
        }
        int get_index()
        {
            return vmt::get_virtual_function<int(*)(void*)>(this, 79)(this);
        }
        int get_team_number()
        {
            return vmt::get_virtual_function<int(*)(void*)>(this, 117)(this);
        }
        int get_health()
        {
            return vmt::get_virtual_function<int(*)(void*)>(this, 152)(this);
        }
        int get_max_health()
        {
            return vmt::get_virtual_function<int(*)(void*)>(this, 153)(this);
        }
        bool is_alive()
        {
            return vmt::get_virtual_function<bool(*)(void*)>(this, 183)(this);
        }
        bool is_player()
        {
            return vmt::get_virtual_function<bool(*)(void*)>(this, 184)(this);
        }
        bool is_npc()
        {
            return vmt::get_virtual_function<bool(*)(void*)>(this, 187)(this);
        }
        bool is_weapon()
        {
            return vmt::get_virtual_function<bool(*)(void*)>(this, 190)(this);
        }
        vec3_t get_eye_position()
        {
            return vmt::get_virtual_function<vec3_t(*)(void*)>(this, 194)(this);
        }
        vec3_t get_eye_angle()
        {
            return vmt::get_virtual_function<vec3_t(*)(void*)>(this, 195)(this);
        }

        //atributes
        vec3_t get_velocity()
        {
            return *reinterpret_cast<vec3_t*>(reinterpret_cast<uintptr_t>(this) + velocity);
        }
        int get_flags()
        {
            return *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this) + flags);
        }
};

class EntityList {
    public:
        Entity* get_entity(int index)
        {
            return vmt::get_virtual_function<Entity*(*)(void*, int)>(this, 3)(this, index);
        }
};