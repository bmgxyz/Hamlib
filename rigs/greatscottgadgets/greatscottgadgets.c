/*
 *  Hamlib Great Scott Gadgets backend - main file
 *  Copyright (c) 2024 by Bradley Gannon
 *
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

// cppcheck-suppress *
#include <stdint.h>
// cppcheck-suppress *
#include <stdio.h>
// cppcheck-suppress *
#include <stdlib.h>
// cppcheck-suppress *
#include <string.h>  /* String function definitions */
// cppcheck-suppress *
#include <unistd.h>  /* UNIX standard function definitions */
// cppcheck-suppress *
#include <time.h>

#include "hamlib/rig.h"
#include "serial.h"
#include "misc.h"
#include "register.h"

#include "greatscottgadgets.h"

static int hackrfone_init(RIG *rig) {
    RETURNFUNC(RIG_OK);
}

/*
 * HackRF One rig capabilities.
 */

struct rig_caps hackrfone_caps =
{
    RIG_MODEL(RIG_MODEL_HACKRFONE),
    .model_name =     "HackRF One",
    .mfg_name =       "Great Scott Gadgets",
    .version =        "20241029.0",
    .copyright =      "LGPL",
    .status =         RIG_STATUS_ALPHA,
    .rig_type =       RIG_FLAG_RECEIVER | RIG_FLAG_TRANSMITTER,
    .ptt_type =       RIG_PTT_NONE,
    .dcd_type =       RIG_DCD_NONE,
    .rig_init =       hackrfone_init,
};

DECLARE_INITRIG_BACKEND(greatscottgadgets)
{
    rig_register(&hackrfone_caps);
    return RIG_OK;
}

DECLARE_PROBERIG_BACKEND(greatscottgadgets)
{
    return (RIG_MODEL_HACKRFONE);
}
