/* 
 * This file is part of NativeOS
 * Copyright (C) 2015-2018 The NativeOS contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <kernel/cpu/idt.h>
#include <kernel/cpu/io.h>
#include <driver/vga.h>

static void keyboard_int_handler(struct idt_data* idt)
{
    int scancode = IO_InP(0x60);
    VGACon_PutChar('?');
}

void keyboard_init()
{
    idt_set_handler(0x21, &keyboard_int_handler);
}
