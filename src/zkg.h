/* Copyright (c) 2013, Bastien Dejean
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ZKG_ZKG_H
#define ZKG_ZKG_H

#include <xcb/xcb_keysyms.h>
#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "helpers.h"

#define CONFIG_HOME_ENV     "XDG_CONFIG_HOME"
#define ZKG_SHELL_ENV     "ZKG_SHELL"
#define SHELL_ENV           "SHELL"
#define HOTKEY_PREFIX       'H'
#define COMMAND_PREFIX      'C'
#define BEGIN_CHAIN_PREFIX  'B'
#define END_CHAIN_PREFIX    'E'
#define TIMEOUT_PREFIX      'T'
#define TIMEOUT              3

extern xcb_connection_t *dpy;
extern xcb_window_t root;
extern xcb_key_symbols_t *symbols;

extern int timeout;

extern bool running, grabbed, bell, chained, locked;
extern xcb_keysym_t abort_keysym;

extern uint16_t num_lock;
extern uint16_t caps_lock;
extern uint16_t scroll_lock;

void key_event(xcb_generic_event_t *evt, uint8_t event_type);
void mapping_notify(xcb_generic_event_t *evt);
void setup(void);
void hold(int sig);

#endif
