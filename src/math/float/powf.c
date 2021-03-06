/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2017 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include "prec/exp2f.h"
#include "prec/log2f.h"
#include "../round.h"
#include "../reinterpret.h"
#include <math.h>
#include <stdint.h>

static float _unsigned(float x, float y)
{
    if (x == 1)
        return 1;

    if (x == 0)
        return signbit(y) ? HUGE_VALF : 0;

    if (isinf(x))
        return signbit(y) ? 0 : HUGE_VALF;

    if (x > 0)
        return __prec_exp2f(y * __prec_log2f(x));

    return NAN;
}

float powf(float x, float y)
{
    uint32_t sign = 0;

    if (y == 0)
        return 1;

    if (signbit(x) && __rintf(y) == y) {
        x = -x;
        sign = -(__rintf(y / 2) != y / 2);
    }

    return copysignf(_unsigned(x, y), reinterpret(float, sign));
}
