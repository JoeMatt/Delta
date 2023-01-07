/* Copyright (c) 2013-2015 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <mgba-util/gui/font.h>

const struct GUIFontGlyphMetric defaultFontMetrics[128] = {
	{  0,  0, { 0, 0, 0, 0 }}, // 0x00
	{  0,  0, { 0, 0, 0, 0 }}, // 0x01
	{  0,  0, { 0, 0, 0, 0 }}, // 0x02
	{  0,  0, { 0, 0, 0, 0 }}, // 0x03
	{  0,  0, { 0, 0, 0, 0 }}, // 0x04
	{  0,  0, { 0, 0, 0, 0 }}, // 0x05
	{  0,  0, { 0, 0, 0, 0 }}, // 0x06
	{  0,  0, { 0, 0, 0, 0 }}, // 0x07
	{  0,  0, { 0, 0, 0, 0 }}, // 0x08
	{  0,  0, { 0, 0, 0, 0 }}, // 0x09
	{  0,  0, { 0, 0, 0, 0 }}, // 0x0A
	{  0,  0, { 0, 0, 0, 0 }}, // 0x0B
	{  0,  0, { 0, 0, 0, 0 }}, // 0x0C
	{  0,  0, { 0, 0, 0, 0 }}, // 0x0D
	{  0,  0, { 0, 0, 0, 0 }}, // 0x0E
	{  0,  0, { 0, 0, 0, 0 }}, // 0x0F
	{  0,  0, { 0, 0, 0, 0 }}, // 0x10
	{  0,  0, { 0, 0, 0, 0 }}, // 0x11
	{  0,  0, { 0, 0, 0, 0 }}, // 0x12
	{  0,  0, { 0, 0, 0, 0 }}, // 0x13
	{  0,  0, { 0, 0, 0, 0 }}, // 0x14
	{  0,  0, { 0, 0, 0, 0 }}, // 0x15
	{  0,  0, { 0, 0, 0, 0 }}, // 0x16
	{  0,  0, { 0, 0, 0, 0 }}, // 0x17
	{  0,  0, { 0, 0, 0, 0 }}, // 0x18
	{  0,  0, { 0, 0, 0, 0 }}, // 0x19
	{  0,  0, { 0, 0, 0, 0 }}, // 0x1A
	{  0,  0, { 0, 0, 0, 0 }}, // 0x1B
	{  0,  0, { 0, 0, 0, 0 }}, // 0x1C
	{  0,  0, { 0, 0, 0, 0 }}, // 0x1D
	{  0,  0, { 0, 0, 0, 0 }}, // 0x1E
	{  0,  0, { 0, 0, 0, 0 }}, // 0x1F
	{  8,  1, { 0, 0, 0, 0 }}, // 0x20 " "
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x21 "!"
	{ 10,  5, { 2, 3, 9, 3 }}, // 0x22 """
	{ 12, 11, { 2, 2, 3, 2 }}, // 0x23 "#"
	{ 10, 13, { 1, 3, 2, 3 }}, // 0x24 "&"
	{ 14, 11, { 2, 1, 3, 1 }}, // 0x25 "%"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x26 "&"
	{  4,  5, { 2, 6, 9, 6 }}, // 0x27 "'"
	{  6, 11, { 2, 5, 3, 5 }}, // 0x28 "("
	{  6, 11, { 2, 5, 3, 5 }}, // 0x29 ")"
	{  8,  7, { 2, 4, 5, 4 }}, // 0x2A "*"
	{ 10,  9, { 3, 3, 4, 3 }}, // 0x2B "+"
	{  4,  5, { 9, 6, 2, 6 }}, // 0x2C ","
	{  6,  3, { 6, 4, 7, 4 }}, // 0x2D "-"
	{  4,  4, { 9, 6, 3, 6 }}, // 0x2E "."
	{  8, 11, { 2, 4, 3, 4 }}, // 0x2F "/"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x30 "0"
	{ 10, 11, { 2, 4, 3, 4 }}, // 0x31 "1"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x32 "2"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x33 "3"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x34 "4"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x35 "5"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x36 "6"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x37 "7"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x38 "8"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x39 "9"
	{  4, 11, { 2, 6, 3, 6 }}, // 0x3A ":"
	{  4, 12, { 2, 6, 2, 6 }}, // 0x3B ";"
	{  8, 11, { 2, 4, 3, 4 }}, // 0x3C "<"
	{ 10,  7, { 4, 3, 5, 3 }}, // 0x3D "="
	{  8, 11, { 2, 4, 3, 4 }}, // 0x3E ">"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x3F "?"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x40 "@"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x41 "A"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x42 "B"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x43 "C"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x44 "D"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x45 "E"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x46 "F"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x47 "G"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x48 "H"
	{  6, 11, { 2, 5, 3, 5 }}, // 0x49 "I"
	{  7, 11, { 2, 5, 3, 4 }}, // 0x4A "J"
	{  9, 11, { 2, 3, 3, 4 }}, // 0x4B "K"
	{  8, 11, { 2, 4, 3, 4 }}, // 0x4C "L"
	{ 11, 11, { 2, 3, 3, 2 }}, // 0x4D "M"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x4E "N"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x4F "O"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x50 "P"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x51 "Q"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x52 "R"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x53 "S"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x54 "T"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x55 "U"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x56 "V"
	{ 11, 11, { 2, 3, 3, 2 }}, // 0x57 "W"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x58 "X"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x59 "Y"
	{ 10, 11, { 2, 3, 3, 3 }}, // 0x5A "Z"
	{  6, 11, { 2, 5, 3, 5 }}, // 0x5B "["
	{  8, 11, { 2, 4, 3, 4 }}, // 0x5C "\"
	{  6, 11, { 2, 5, 3, 5 }}, // 0x5D "]"
	{  8,  7, { 2, 4, 7, 4 }}, // 0x5E "^"
	{ 10,  3, { 10, 3, 3, 3 }}, // 0x5F "_"
	{  6,  5, { 8, 6, 3, 4 }}, // 0x60 "`"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x61 "a"
	{  8, 11, { 2, 4, 3, 4 }}, // 0x62 "b"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x63 "c"
	{  8, 11, { 2, 4, 3, 4 }}, // 0x64 "d"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x65 "e"
	{  7, 11, { 2, 5, 3, 4 }}, // 0x66 "f"
	{  8,  9, { 6, 4, 1, 4 }}, // 0x67 "g"
	{  8, 11, { 2, 4, 3, 4 }}, // 0x68 "h"
	{  6, 11, { 2, 5, 3, 5 }}, // 0x69 "i"
	{  7, 13, { 2, 5, 1, 4 }}, // 0x6A "j"
	{  8, 11, { 2, 4, 3, 4 }}, // 0x6B "k"
	{  5, 11, { 2, 5, 3, 6 }}, // 0x6C "l"
	{ 10,  7, { 6, 3, 3, 3 }}, // 0x6D "m"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x6E "n"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x6F "o"
	{  8,  9, { 6, 4, 1, 4 }}, // 0x70 "p"
	{  8,  9, { 6, 4, 1, 4 }}, // 0x71 "q"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x72 "r"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x73 "s"
	{  8,  9, { 4, 4, 3, 4 }}, // 0x74 "t"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x75 "u"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x76 "v"
	{  9,  7, { 6, 4, 3, 3 }}, // 0x77 "w"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x78 "x"
	{  8,  9, { 6, 4, 1, 4 }}, // 0x79 "y"
	{  8,  7, { 6, 4, 3, 4 }}, // 0x7A "z"
	{  7, 11, { 2, 5, 3, 4 }}, // 0x7B "{"
	{  4, 11, { 2, 6, 3, 6 }}, // 0x7C "|"
	{  7, 11, { 2, 4, 3, 5 }}, // 0x7D "}"
	{ 10,  5, { 5, 3, 6, 3 }}, // 0x7E "}"
	{  0,  0, { 0, 0, 0, 0 }}, // 0x7F
};

const struct GUIIconMetric defaultIconMetrics[] = {
	[GUI_ICON_BATTERY_FULL] = { 0, 2, 32, 12 },
	[GUI_ICON_BATTERY_HIGH] = { 32, 2, 32, 12 },
	[GUI_ICON_BATTERY_HALF] = { 64, 2, 32, 12 },
	[GUI_ICON_BATTERY_LOW] = { 96, 2, 32, 12 },
	[GUI_ICON_BATTERY_EMPTY] = { 128, 2, 32, 12 },
	[GUI_ICON_SCROLLBAR_BUTTON] = { 6, 16, 4, 5 },
	[GUI_ICON_SCROLLBAR_TRACK] = { 23, 16, 2, 16 },
	[GUI_ICON_SCROLLBAR_THUMB] = { 38, 16, 4, 16 },
	[GUI_ICON_CURSOR] = { 48, 16, 16, 16 },
	[GUI_ICON_POINTER] = { 68, 20, 8, 8 },
	[GUI_ICON_BUTTON_CIRCLE] = { 2, 34, 12, 11 },
	[GUI_ICON_BUTTON_CROSS] = { 18, 34, 12, 11 },
	[GUI_ICON_BUTTON_TRIANGLE] = { 34, 34, 12, 11 },
	[GUI_ICON_BUTTON_SQUARE] = { 50, 34, 12, 11 },
	[GUI_ICON_BUTTON_HOME] = { 66, 34, 12, 11 },
	[GUI_ICON_LEFT] = { 82, 34, 12, 12 },
	[GUI_ICON_UP] = { 98, 34, 12, 12 },
	[GUI_ICON_RIGHT] = { 114, 34, 12, 12 },
	[GUI_ICON_DOWN] = { 130, 34, 12, 12 },
	[GUI_ICON_STATUS_FAST_FORWARD] = { 2, 50, 12, 12 },
	[GUI_ICON_STATUS_MUTE] = { 17, 50, 14, 12 },
};
