// terminal.h - terminal stuff
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

#ifndef TERMINAL_H
#define TEMINAL_H

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

void T_getwinsize(int* rows, int* columns) {
    struct winsize w;
    
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        *rows = w.ws_row;
        *columns = w.ws_col;
    }
}

struct termios orig_termios;

void T_exitraw() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void T_enterraw() {
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) exit('TG');
    atexit(T_exitraw);
    struct termios raw = orig_termios;

    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) exit('TS');
}

#endif