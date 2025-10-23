// nb.c - main entrance point for nb
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

#define NB_VERSION "1.0"
#define NB_COPYRIGHT_YEARS "2022 - 2025"

#include <stdio.h>
#include <string.h>

#include "terminal.h"
#include "cursor.h"
#include "editor.h"

void initEditor() {
    E.cpos.x = 0;
    E.cpos.y = 0;
    T_getwinsize(&E.T_rows, &E.T_columns);

    E.filename = "";
}

int main(int argc, char* *argv) {
    char* filename = "";

    if (argc >= 2) {
        filename = argv[1];
    }

    initEditor();
    

    return 0;
}