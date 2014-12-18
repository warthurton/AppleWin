/*
AppleWin : An Apple //e emulator for Windows

Copyright (C) 2010-2011, William S Simms

AppleWin is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

AppleWin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AppleWin; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "StdAfx.h"
#include "cs.h"

unsigned char csbits[2][256][8];

static char *csstrs[] = {
	"   ###  ","    #   ","  ####  ","   ###  ","  ####  ","  ##### ","  ##### ","   #### ",
	"  #   # ","   # #  ","  #   # ","  #   # ","  #   # ","  #     ","  #     ","  #     ",
	"  # # # ","  #   # ","  #   # ","  #     ","  #   # ","  #     ","  #     ","  #     ",
	"  # ### ","  #   # ","  ####  ","  #     ","  #   # ","  ####  ","  ####  ","  #     ",
	"  # ##  ","  ##### ","  #   # ","  #     ","  #   # ","  #     ","  #     ","  #  ## ",
	"  #     ","  #   # ","  #   # ","  #   # ","  #   # ","  #     ","  #     ","  #   # ",
	"   #### ","  #   # ","  ####  ","   ###  ","  ####  ","  ##### ","  #     ","   #### ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"  #   # ","   ###  ","      # ","  #   # ","  #     ","  #   # ","  #   # ","   ###  ",
	"  #   # ","    #   ","      # ","  #  #  ","  #     ","  ## ## ","  #   # ","  #   # ",
	"  #   # ","    #   ","      # ","  # #   ","  #     ","  # # # ","  ##  # ","  #   # ",
	"  ##### ","    #   ","      # ","  ##    ","  #     ","  # # # ","  # # # ","  #   # ",
	"  #   # ","    #   ","      # ","  # #   ","  #     ","  #   # ","  #  ## ","  #   # ",
	"  #   # ","    #   ","  #   # ","  #  #  ","  #     ","  #   # ","  #   # ","  #   # ",
	"  #   # ","   ###  ","   ###  ","  #   # ","  ##### ","  #   # ","  #   # ","   ###  ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"  ####  ","   ###  ","  ####  ","   ###  ","  ##### ","  #   # ","  #   # ","  #   # ",
	"  #   # ","  #   # ","  #   # ","  #   # ","    #   ","  #   # ","  #   # ","  #   # ",
	"  #   # ","  #   # ","  #   # ","  #     ","    #   ","  #   # ","  #   # ","  #   # ",
	"  ####  ","  #   # ","  ####  ","   ###  ","    #   ","  #   # ","  #   # ","  # # # ",
	"  #     ","  # # # ","  # #   ","      # ","    #   ","  #   # ","  #   # ","  # # # ",
	"  #     ","  #  #  ","  #  #  ","  #   # ","    #   ","  #   # ","   # #  ","  ## ## ",
	"  #     ","   ## # ","  #   # ","   ###  ","    #   ","   ###  ","    #   ","  #   # ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"  #   # ","  #   # ","  ##### ","  ##### ","        ","  ##### ","        ","        ",
	"  #   # ","  #   # ","      # ","  ##    ","  #     ","     ## ","        ","        ",
	"   # #  ","   # #  ","     #  ","  ##    ","   #    ","     ## ","    #   ","        ",
	"    #   ","    #   ","    #   ","  ##    ","    #   ","     ## ","   # #  ","        ",
	"   # #  ","    #   ","   #    ","  ##    ","     #  ","     ## ","  #   # ","        ",
	"  #   # ","    #   ","  #     ","  ##    ","      # ","     ## ","        ","        ",
	"  #   # ","    #   ","  ##### ","  ##### ","        ","  ##### ","        ","        ",
	"        ","        ","        ","        ","        ","        ","        "," #######",
	"        ","    #   ","   # #  ","   # #  ","    #   ","  ##    ","   #    ","    #   ",
	"        ","    #   ","   # #  ","   # #  ","   #### ","  ##  # ","  # #   ","    #   ",
	"        ","    #   ","   # #  ","  ##### ","  # #   ","     #  ","  # #   ","    #   ",
	"        ","    #   ","        ","   # #  ","   ###  ","    #   ","   #    ","        ",
	"        ","    #   ","        ","  ##### ","    # # ","   #    ","  # # # ","        ",
	"        ","        ","        ","   # #  ","  ####  ","  #  ## ","  #  #  ","        ",
	"        ","    #   ","        ","   # #  ","    #   ","     ## ","   ## # ","        ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"     #  ","   #    ","    #   ","        ","        ","        ","        ","        ",
	"    #   ","    #   ","  # # # ","    #   ","        ","        ","        ","      # ",
	"   #    ","     #  ","   ###  ","    #   ","        ","        ","        ","     #  ",
	"   #    ","     #  ","    #   ","  ##### ","        ","  ##### ","        ","    #   ",
	"   #    ","     #  ","   ###  ","    #   ","    #   ","        ","        ","   #    ",
	"    #   ","    #   ","  # # # ","    #   ","    #   ","        ","        ","  #     ",
	"     #  ","   #    ","    #   ","        ","   #    ","        ","    #   ","        ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"   ###  ","    #   ","   ###  ","  ##### ","     #  ","  ##### ","    ### ","  ##### ",
	"  #   # ","   ##   ","  #   # ","      # ","    ##  ","  #     ","   #    ","      # ",
	"  #  ## ","    #   ","      # ","     #  ","   # #  ","  ####  ","  #     ","     #  ",
	"  # # # ","    #   ","    ##  ","    ##  ","  #  #  ","      # ","  ####  ","    #   ",
	"  ##  # ","    #   ","   #    ","      # ","  ##### ","      # ","  #   # ","   #    ",
	"  #   # ","    #   ","  #     ","  #   # ","     #  ","  #   # ","  #   # ","   #    ",
	"   ###  ","   ###  ","  ##### ","   ###  ","     #  ","   ###  ","   ###  ","   #    ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"   ###  ","   ###  ","        ","        ","      # ","        ","  #     ","   ###  ",
	"  #   # ","  #   # ","        ","        ","     #  ","        ","   #    ","  #   # ",
	"  #   # ","  #   # ","    #   ","    #   ","    #   ","  ##### ","    #   ","     #  ",
	"   ###  ","   #### ","        ","        ","   #    ","        ","     #  ","    #   ",
	"  #   # ","      # ","    #   ","    #   ","    #   ","  ##### ","    #   ","    #   ",
	"  #   # ","     #  ","        ","    #   ","     #  ","        ","   #    ","        ",
	"   ###  ","  ###   ","        ","   #    ","      # ","        ","  #     ","    #   ",
	"        ","        ","        ","        ","        ","        ","        ","        ",
	"   #    ","        ","  #     ","        ","      # ","        ","    ##  ","        ",
	"    #   ","        ","  #     ","        ","      # ","        ","   #  # ","        ",
	"     #  ","   ###  ","  ####  ","   #### ","   #### ","   ###  ","   #    ","   #### ",
	"        ","      # ","  #   # ","  #     ","  #   # ","  #   # ","  ####  ","  #   # ",
	"        ","   #### ","  #   # ","  #     ","  #   # ","  ##### ","   #    ","  #   # ",
	"        ","  #   # ","  #   # ","  #     ","  #   # ","  #     ","   #    ","   #### ",
	"        ","   #### ","  ####  ","   #### ","   #### ","   #### ","   #    ","      # ",
	"        ","        ","        ","        ","        ","        ","        ","   ###  ",
	"  #     ","    #   ","     #  ","  #     ","   ##   ","        ","        ","        ",
	"  #     ","        ","        ","  #     ","    #   ","        ","        ","        ",
	"  ####  ","   ##   ","    ##  ","  #   # ","    #   ","  ## ## ","  ####  ","   ###  ",
	"  #   # ","    #   ","     #  ","  #  #  ","    #   ","  # # # ","  #   # ","  #   # ",
	"  #   # ","    #   ","     #  ","  ###   ","    #   ","  # # # ","  #   # ","  #   # ",
	"  #   # ","    #   ","     #  ","  #  #  ","    #   ","  # # # ","  #   # ","  #   # ",
	"  #   # ","   ###  ","  #  #  ","  #   # ","   ###  ","  #   # ","  #   # ","   ###  ",
	"        ","        ","   ##   ","        ","        ","        ","        ","        ",
	"        ","        ","        ","        ","   #    ","        ","        ","        ",
	"        ","        ","        ","        ","   #    ","        ","        ","        ",
	"  ####  ","   #### ","  # ### ","   #### ","  ####  ","  #   # ","  #   # ","  #   # ",
	"  #   # ","  #   # ","  ##    ","  #     ","   #    ","  #   # ","  #   # ","  #   # ",
	"  #   # ","  #   # ","  #     ","   ###  ","   #    ","  #   # ","  #   # ","  # # # ",
	"  ####  ","   #### ","  #     ","      # ","   #  # ","  #  ## ","   # #  ","  # # # ",
	"  #     ","      # ","  #     ","  ####  ","    ##  ","   ## # ","    #   ","  ## ## ",
	"  #     ","      # ","        ","        ","        ","        ","        ","        ",
	"        ","        ","        ","    ### ","    #   ","  ###   ","   ## # ","        ",
	"        ","        ","        ","   ##   ","    #   ","    ##  ","  # ##  ","  # # # ",
	"  #   # ","  #   # ","  ##### ","   ##   ","    #   ","    ##  ","        ","   # #  ",
	"   # #  ","  #   # ","     #  ","  ##    ","    #   ","     ## ","        ","  # # # ",
	"    #   ","  #   # ","    #   ","   ##   ","    #   ","    ##  ","        ","   # #  ",
	"   # #  ","   #### ","   #    ","   ##   ","    #   ","    ##  ","        ","  # # # ",
	"  #   # ","      # ","  ##### ","    ### ","    #   ","  ###   ","        ","        ",
	"        ","   ###  ","        ","        ","    #   ","        ","        ","        ",
	"     #  ","     #  ","        "," #######","        "," #######","     ###","        ",
	"    #   ","    #   ","        ","  #   # ","       #"," ###### ","      ##","    ##  ",
	"  ## ## ","  ## ## ","  #     ","   # #  ","      # "," ##### #","  ######"," ###    ",
	" #######"," #     #","  ##    ","    #   "," #   #  ","   ## ##"," #   ## ","        ",
	" ###### "," #    # ","  ###   ","    #   ","  # #   "," # # ###"," #  ####"," ###    ",
	" ###### "," #    # ","  ####  ","   # #  ","   #    "," ## ####","     ## ","   ##   ",
	"  ######","  # #  #","  ## ## ","  # # # ","   #    "," ## ####"," ###### ","    #   ",
	"  ## ## ","  ## ## ","  #    #"," #######","        "," #######","  #     ","     ###",
	"    #   ","        ","    #   ","    #   "," #######","       #"," ###### "," ##  #  ",
	"   #    ","        ","    #   ","   ###  ","        ","       #"," ###### ","    ##  ",
	"  #     ","        ","    #   ","  # # # ","        ","   #   #"," ###### ","   ###  ",
	" #######","        ","    #   "," #  #  #","        ","  ##   #"," ###### ","  ######",
	"  #     ","        "," #  #  #","    #   ","        "," #######"," ###### ","   ###  ",
	"   #    ","        ","  # # # ","    #   ","        ","  ##    "," ###### ","    ##  ",
	"    #   ","        ","   ###  ","    #   ","        ","   #    "," ###### ","     #  ",
	"        ","  # # # ","    #   ","    #   ","        ","        "," ###### "," #### ##",
	"   #  ##","       #","       #","        "," #      ","    #   ","  # # # "," # # # #",
	"   ##   ","    #  #","    #  #","        "," #      ","     #  "," # # # #","  # # # ",
	"   ###  ","    #   ","   ###  ","        "," #      ","      # ","  # # # "," # # # #",
	" ###### "," #######","  ##### "," #######"," #      "," #######"," # # # #","  # # # ",
	"   ###  ","  ##### "," #######","        "," #      ","      # ","  # # # "," # # # #",
	"   ##   ","   ###  ","    #   ","        "," #      ","     #  "," # # # #","  # # # ",
	"   #    ","    #  #","    #  #","        "," #      ","    #   ","  # # # "," # # # #",
	" ## ####","       #","       #","        "," #######","        "," # # # #","  # # # ",
	"        ","        ","       #","    #   "," #######","   # #  "," #######"," #      ",
	"  ##### ","        ","       #","   ###  ","        ","   # #  ","       #"," #      ",
	" #     #","####### ","       #","  ##### ","        "," ### ###","       #"," #      ",
	" #      ","       #","       #"," #######","        ","        ","   ##  #"," #      ",
	" #      ","       #","       #","  ##### ","        "," ### ###","   ##  #"," #      ",
	" #      ","       #","       #","   ###  ","        ","   # #  ","       #"," #      ",
	" #######","########","       #","    #   ","        ","   # #  ","       #"," #      ",
	"        ","        ","       #","        "," #######","        "," #######"," #      ",
};

#define STRINGS_PER_CHAR 8
#define CHARS_PER_ROW 8
#define STRINGS_PER_CHAR_ROW (STRINGS_PER_CHAR * CHARS_PER_ROW)

void make_csbits (void) {
	int i,j;
	int szstrs = sizeof csstrs / sizeof csstrs[0];
	int numchars = szstrs / STRINGS_PER_CHAR;
	
	for (i = 0; i < numchars; ++i) {
		int si = ((i / STRINGS_PER_CHAR) * STRINGS_PER_CHAR_ROW) + (i % CHARS_PER_ROW);
		for (j = 0; j < STRINGS_PER_CHAR; ++j)
		{
			char *sp = csstrs[si];
			unsigned char cb = 0;
		
			si += CHARS_PER_ROW;

			while (*sp) {
				if (*sp++ != ' ') cb |= 0x80;
				cb >>= 1;
			}
		
			csbits[0][i][j] = cb;
		}
	}

	/* move mousetext */
	for (i = 96; i < 128; ++i)
		for (j = 0; j < 8; ++j)
			csbits[1][i-32][j] = csbits[0][i][j];

	/* move lowercase */
	for (i = 64; i < 96; ++i)
		for (j = 0; j < 8; ++j)
			csbits[1][i+32][j] = csbits[1][i+160][j] =
				csbits[0][i+160][j] = csbits[0][i][j];

	/* move numbers */
	for (i = 32; i < 64; ++i)
		for (j = 0; j < 8; ++j)
			csbits[1][i][j] = csbits[1][i+128][j] =
				csbits[0][i+64][j] = csbits[0][i+128][j] = csbits[0][i][j];

	/* move uppercase */
	for (i = 0; i < 32; ++i)
		for (j = 0; j < 8; ++j)
			csbits[1][i][j] = csbits[1][i+128][j] = csbits[1][i+192][j] =
				csbits[0][i+64][j] = csbits[0][i+128][j] = csbits[0][i+192][j] = csbits[0][i][j];

	/* invert (skip mousetext) */
	for (i = 0; i < 128; ++i)
		for (j = 0; j < 8; ++j)
		{
			csbits[0][i][j] ^= 0xFF;
			if (i < 64 || i >= 96)
				csbits[1][i][j] ^= 0xFF;
		}
}
