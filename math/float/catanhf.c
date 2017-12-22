/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2017 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include "catanf.h"
#include <complex.h>

float _Complex catanhf(float _Complex z)
{
    z = __catanf(cimagf(z), z);

    return CMPLXF(cimagf(z), z);
}
