/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2018 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include "common.h"
#include "../../../src/math/float/log2f.c"
#include <assert.h>

int main(void)
{
    assert(reinterpret(uint32_t, _log2f(1)) == 0);
    assert(_log2f(0) == -INFINITY);
    assert(_log2f(-0.0) == -INFINITY);
    assert(_log2f(INFINITY) == INFINITY);
    assert(isnan(_log2f(-INFINITY)));
    assert(isnan(_log2f(NAN)));

    for (int32_t i = 0; i < 0x7F800000; i += 77) {
        float x = reinterpret(float, i);
        verify(approx(_log2f(x), log2(x)), x);
    }

    for (uint32_t i = 1; i < 0x80000000; i += 12345) {
        float x = reinterpret(float, i);
        verify(isnan(_log2f(-x)), x);
    }
}
