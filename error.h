// error.h - error handler
/*
    Copyright (C) 2025 Ben Daws

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA
*/

#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "terminal.h"

struct errorEvent {
    char* msg; // Error msg: eg. (Something failed)
    char* trace; // Stack trace (where it happened)
    char* info;

    int crash; // 1 to make a crash screen
};

struct errorEvent E_error(char* msg, char* src, char* info, bool doCrash) {
    struct errorEvent new;

    new.msg = msg;
    new.trace = src;
    new.info = info;
    new.crash = doCrash >= 1;

    return new;
}

void E_report(struct errorEvent err) {
    if (err.crash) {
        // crash screen
        T_exitraw();
        T_clearscr();

        printf("nb_crash:\n\r# Event details:\n\r");
        printf("#\tMessage: %s\n\r", err.msg);
        printf("#\tTrace:   %s\n\r", err.trace);
        printf("#\tInfo:    %s\n\r", err.info);

        exit(1);
    }
}

#endif