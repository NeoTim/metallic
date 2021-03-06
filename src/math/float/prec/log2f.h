/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2017 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include "../kernel/atanhf.h"
#include "../../reinterpret.h"
#include <float.h>

inline double __prec_log2f(double x)
{
    const double log2e = 1.44269504088896340736;

    int64_t i = reinterpret(int64_t, x);
    int64_t exponent = (i - 0x3FE6A09E667F3BCD) >> (DBL_MANT_DIG - 1);

    x = reinterpret(double, i - (exponent << (DBL_MANT_DIG - 1)));

    return 2 * log2e * __kernel_atanhf((x - 1) / (x + 1)) + exponent;
}
