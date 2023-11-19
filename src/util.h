#pragma once

#include "sdk/sdk.h"
#include <math.h>

// from https://github.com/8dcc/tf2-cheat/blob/main/src/include/util.h

#define DEG2RAD(n) ((n)*M_PI / 180.0f)
#define RAD2DEG(n) ((n)*180.0f / M_PI)
#define CLAMP(val, min, max) \
    (((val) > (max)) ? (max) : (((val) < (min)) ? (min) : (val)))
    
static inline float vec_dotproduct(vec3_t a, vec3_t b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

static inline vec3_t vec_add(vec3_t a, vec3_t b) {
    return (vec3_t){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
    };
}

static inline vec3_t vec_sub(vec3_t a, vec3_t b) {
    return (vec3_t){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
    };
}

static inline vec3_t vec_mul(vec3_t a, vec3_t b) {
    return (vec3_t){
        .x = a.x * b.x,
        .y = a.y * b.y,
        .z = a.z * b.z,
    };
}

static inline vec3_t vec_flmul(vec3_t a, float b) {
    return (vec3_t){
        .x = a.x * b,
        .y = a.y * b,
        .z = a.z * b,
    };
}

static inline bool vec_equal(vec3_t a, vec3_t b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

static inline bool vec_is_zero(vec3_t v) {
    return v.x == 0.0f && v.y == 0.0f && v.z == 0.0f;
}

static inline float vec_len(vec3_t v) {
    return sqrtf(vec_dotproduct(v, v));
}

static inline float vec_len2d(vec3_t v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

static inline void ang_clamp(vec3_t* v) {
    v->x = CLAMP(v->x, -89.0f, 89.0f);
    v->y = CLAMP(remainderf(v->y, 360.0f), -180.0f, 180.0f);
    v->z = CLAMP(v->z, -50.0f, 50.0f);
}

static inline void vec_norm(vec3_t* v) {
    v->x = isfinite(v->x) ? remainderf(v->x, 360.f) : 0.f;
    v->y = isfinite(v->y) ? remainderf(v->y, 360.f) : 0.f;
    v->z = 0.0f;
}


static inline vec3_t vec_to_ang(vec3_t v) {
    return (vec3_t){
        .x = RAD2DEG(atan2(-v.z, hypot(v.x, v.y))),
        .y = RAD2DEG(atan2(v.y, v.x)),
        .z = 0.0f,
    };
}

static inline vec3_t ang_to_vec(vec3_t a) {
    const float sy = sin(a.y / 180.f * (float)(M_PI));
    const float cy = cos(a.y / 180.f * (float)(M_PI));

    const float sp = sin(a.x / 180.f * (float)(M_PI));
    const float cp = cos(a.x / 180.f * (float)(M_PI));

    return (vec3_t){
        .x = cp * cy,
        .y = cp * sy,
        .z = -sp,
    };
}

static inline float angle_delta_rad(float a, float b) {
    float delta = isfinite(a - b) ? remainder(a - b, 360) : 0;

    if (a > b && delta >= M_PI)
        delta -= M_PI * 2;
    else if (delta <= -M_PI)
        delta += M_PI * 2;

    return delta;
}

static inline float vec_length_sqr(vec3_t v) {
    return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}