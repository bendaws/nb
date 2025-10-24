// cursor.h - cursor controller
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

#ifndef CURSOR_H
#define CURSOR_H

#include <unistd.h>
#include <stdio.h>

struct cursor {
    int x;
    int y;
};

void cursor_move(struct cursor self) {
    char txt[80];
    int len = snprintf(txt, sizeof(txt), "\033[%d;%dH", self.y, self.x);
    write(STDOUT_FILENO, txt, len);
}

struct cursor cursor_home() {
    struct cursor C = {0, 0};
    return C;
}

#endif