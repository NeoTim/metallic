/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2018 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include "common.h"
#include "../../../src/math/float/log10f.c"
#include <assert.h>

int main(void)
{
    assert(reinterpret(uint32_t, _log10f(1)) == 0);
    assert(_log10f(0) == -INFINITY);
    assert(_log10f(-0.0) == -INFINITY);
    assert(_log10f(INFINITY) == INFINITY);
    assert(isnan(_log10f(-INFINITY)));
    assert(isnan(_log10f(NAN)));

    for (int32_t i = 0; i < 0x7F800000; i += 77) {
        float x = reinterpret(float, i);
        verify(approx(_log10f(x), log10(x)), x);
    }

    for (uint32_t i = 1; i < 0x80000000; i += 12345) {
        float x = reinterpret(float, i);
        verify(isnan(_log10f(-x)), x);
    }
}
