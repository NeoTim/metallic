/* This file is part of Metallic, a runtime library for WebAssembly.
 *
 * Copyright (C) 2017 Chen-Pang He <chen.pang.he@jdh8.org>
 *
 * This Source Code Form is subject to the terms of the Mozilla
 * Public License v. 2.0. If a copy of the MPL was not distributed
 * with this file, You can obtain one at http://mozilla.org/MPL/2.0/
 */
#include <string.h>

size_t strcspn(const char string[static 1], const char reject[static 1])
{
    size_t count = 0;

    while (!strchr(reject, string[count]))
        ++count;

    return count;
}
