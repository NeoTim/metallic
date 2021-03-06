/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2017 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include "../kernel/atanf.h"
#include <math.h>

inline double __prec_atan2f(double y, double x)
{
    const double pi = 3.14159265358979323846;

    double absy = fabs(y);
    double absx = fabs(x);

    if (absy > absx)
        return copysign(pi / 2, y) - __kernel_atanf(x / y);

    double sharp = absy == absx ? copysign(pi / 4, y) : __kernel_atanf(y / absx);

    return signbit(x) ? copysign(pi, y) - sharp : sharp;
}
