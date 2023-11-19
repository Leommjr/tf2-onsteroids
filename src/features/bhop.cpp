#include <math.h>
#include "features.h"
#include "../util.h"

extern Entity* localplayer;
extern EngineClient* engine;

//just copied from https://github.com/8dcc/tf2-cheat/blob/main/src/features/movement.c
void autostrafe_rage(usercmd_t* cmd) {
    /* TODO: Get at runtime */
    static const float sv_airaccelerate = 10.0f;
    static const float sv_maxspeed      = 320.0f;
    static const float cl_forwardspeed  = 450.0f;
    static const float cl_sidespeed     = 450.0f;


    const vec3_t l_velocity = localplayer->get_velocity();
    const float speed     = vec_len2d(l_velocity);

    /* If low speed, start forward */
    if (speed < 30)
        return;

    float term = sv_airaccelerate / sv_maxspeed * 100.0f / speed;
    if (term < -1 || term > 1)
        return;

    float best_delta = acosf(term);

    /* Use engine viewangles in case we do something nasty with cmd's angles */
    vec3_t viewangles;
    engine->get_view_angles(&viewangles);

    /* Get our desired angles and delta */
    float yaw        = DEG2RAD(viewangles.y);
    float vel_dir    = atan2f(l_velocity.y, l_velocity.x) - yaw;
    float target_ang = atan2f(-cmd->sidemove, cmd->forwardmove);
    float delta      = angle_delta_rad(vel_dir, target_ang);

    float movedir = delta < 0 ? vel_dir + best_delta : vel_dir - best_delta;

    cmd->forwardmove = cosf(movedir) * cl_forwardspeed;
    cmd->sidemove    = -sinf(movedir) * cl_sidespeed;
}


void bhop(usercmd_t* cmd) {
    const bool is_jumping = (cmd->buttons & IN_JUMP) != 0;

    if (!(localplayer->get_flags() & FL_ONGROUND))
        cmd->buttons &= ~IN_JUMP;

    if (is_jumping)
        autostrafe_rage(cmd);
}