/**
 * Copyright (c) 2015-2018 Brad Bahls.  All Rights Reserved.
 * Unauthorized copying of this file by any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Color palette definitions.
 * Date: 11-16-2015
 * Author: Brad Bahls (chembrad@msn.com)
 */

#include <vector>

typedef std::vector<unsigned int> ColorVec;
typedef std::vector<ColorVec> ColPal;

// Palette base struct.
struct Palette
{
    ColPal palette;
    ColorVec c1;
    ColorVec c2;
    ColorVec c3;
    ColorVec c4;
    ColorVec c5;
    ColorVec c6;
    ColorVec c7;
    ColorVec c8;
    ColorVec c9;
    ColorVec c10;
    ColorVec c11;
    ColorVec c12;
    ColorVec c13;
    ColorVec c14;
    ColorVec c15;
    ColorVec c16;
};

/** Gameboy 16-color palette
 * Source: https://code.google.com/p/grafx/wiki/PaletteRepository
 */

struct GBPalette : Palette
{
    GBPalette()
    {
        Palette::c1 = {230,214,156};
        Palette::c2 = {180,165,106};
        Palette::c3 = {123,113,98};
        Palette::c4 = {57,56,41};
        Palette::c5 = {123,113,98};
        Palette::c6 = {180,165,106};
        Palette::c7 = {57,56,41};
        Palette::c8 = {230,214,156};
        Palette::c9 = {24,48,48};
        Palette::c10 = {80,120,104};
        Palette::c11 = {168,192,176};
        Palette::c12 = {224,240,232};
        Palette::c13 = {215,232,148};
        Palette::c14 = {174,196,64};
        Palette::c15 = {82,127,57};
        Palette::c16 = {32,70,49};
        Palette::palette = {
             Palette::c1,Palette::c2,Palette::c3,Palette::c4
            ,Palette::c5,Palette::c6,Palette::c7,Palette::c8
            ,Palette::c9,Palette::c10,Palette::c11,Palette::c12
            ,Palette::c13,Palette::c14,Palette::c15,Palette::c16
            };
    }
} GBPal;

/** Commodore-64 16-color palette
 * Source: https://code.google.com/p/grafx/wiki/PaletteRepository
 */

struct C64Palette : Palette
{
    C64Palette()
    {
        Palette::c1 = {204,89,198};
        Palette::c2 = {255,253,255}; 
        Palette::c3 = {65,55,205}; 
        Palette::c4 = {117,161,236}; 
        Palette::c5 = {131,240,220}; 
        Palette::c6 = {89,205,54}; 
        Palette::c7 = {247,238,89}; 
        Palette::c8 = {209,127,48}; 
        Palette::c9 = {145,95,51}; 
        Palette::c10 = {249,155,151}; 
        Palette::c11 = {190,53,53}; 
        Palette::c12 = {255,255,255}; 
        Palette::c13 = {202,202,202}; 
        Palette::c14 = {142,142,142}; 
        Palette::c15 = {91,91,91}; 
        Palette::c16 = {127,127,127}; 
        Palette::palette = { 
             Palette::c1,Palette::c2,Palette::c3,Palette::c4
            ,Palette::c5,Palette::c6,Palette::c7,Palette::c8
            ,Palette::c9,Palette::c10,Palette::c11,Palette::c12
            ,Palette::c13,Palette::c14,Palette::c15,Palette::c16
            };
    }
} C64Pal;

/** Arne's Eroge Copper 16-color palette
 *  Source: androidarts.com/palette/16pal.htm
 */

struct ECPalette : Palette
{
    ECPalette()
    {
        Palette::c1 = {125,56,64};
        Palette::c2 = {13,8,13};
        Palette::c3 = {42,35,73};
        Palette::c4 = {65,128,160};
        Palette::c5 = {50,83,95};
        Palette::c6 = {116,173,187};
        Palette::c7 = {123,178,78};
        Palette::c8 = {255,249,228};
        Palette::c9 = {190,187,178};
        Palette::c10 = {251,223,155};
        Palette::c11 = {240,189,119};
        Palette::c12 = {197,145,84};
        Palette::c13 = {130,91,49};
        Palette::c14 = {232,153,115};
        Palette::c15 = {193,108,91};
        Palette::c16 = {79,43,36};
        Palette::palette = {
             Palette::c1,Palette::c2,Palette::c3,Palette::c4
            ,Palette::c5,Palette::c6,Palette::c7,Palette::c8
            ,Palette::c9,Palette::c10,Palette::c11,Palette::c12
            ,Palette::c13,Palette::c14,Palette::c15,Palette::c16
            };
    }
} ECPal;


/** Minecraft dyed-wool color space (Alpha omitted in rgb)
 *  Source: http://gaming.stackexchange.com/questions/47212/what-are-the-color-values-for-dyed-wool
 *
 *  Color           Hex         RGB
 *  -----           ---         ---
 *  White           FFe4e4e4    228,228,228
 *  Light Gray      FFa0a7a7    160,167,167
 *  Dark Gray       FF414141    65,65,65
 *  Black           FF181414    24,20,20
 *  Red             FF9e2b27    158,43,39
 *  Orange          FFea7e35    234,126,53
 *  Yellow          FFc2b51c    194,181,28
 *  Lime Green      FF39ba2e    57,186,46
 *  Green           FF364b18    54,75,24
 *  Light Blue      FF6387d2    99,135,210
 *  Cyan            FF267191    38,113,145
 *  Blue            FF253193    37,49,147
 *  Purple          FF7e34bf    126,52,191
 *  Magenta         FFbe49c9    190,73,201
 *  Pink            FFd98199    217,129,153
 *  Brown           FF56331c    86,51,28
 */

struct MCPalette : Palette
{
    MCPalette() 
    {
        Palette::c1 = {228,228,228};
        Palette::c2 = {160,167,167}; 
        Palette::c3 = {65,65,65}; 
        Palette::c4 = {24,20,20}; 
        Palette::c5 = {158,43,39}; 
        Palette::c6 = {234,126,53}; 
        Palette::c7 = {194,181,28}; 
        Palette::c8 = {57,186,46}; 
        Palette::c9 = {54,75,24}; 
        Palette::c10 = {99,135,210}; 
        Palette::c11 = {38,113,145}; 
        Palette::c12 = {37,49,147}; 
        Palette::c13 = {126,52,191}; 
        Palette::c14 = {190,73,201}; 
        Palette::c15 = {217,129,153}; 
        Palette::c16 = {86,51,28}; 
        Palette::palette = { 
             Palette::c1,Palette::c2,Palette::c3,Palette::c4
            ,Palette::c5,Palette::c6,Palette::c7,Palette::c8
            ,Palette::c9,Palette::c10,Palette::c11,Palette::c12
            ,Palette::c13,Palette::c14,Palette::c15,Palette::c16
            };
    }
} MCPal;


/** Deepsleep Terminal Palette
 *  Source: https://lospec.com/palette-list/deepsleep-terminal
 */

struct DeepSleepPalette : Palette
{
    DeepSleepPalette()
    {
        Palette::c1 = {50,50,50};
        Palette::c2 = {83,83,83};
        Palette::c3 = {210,82,82};
        Palette::c4 = {240,112,112};
        Palette::c5 = {127,225,115};
        Palette::c6 = {157,255,145};
        Palette::c7 = {255,198,109};
        Palette::c8 = {255,228,139};
        Palette::c9 = {64,153,255};
        Palette::c10 = {94,183,247};
        Palette::c11 = {246,128,255};
        Palette::c12 = {255,157,255};
        Palette::c13 = {190,214,255};
        Palette::c14 = {220,244,255};
        Palette::c15 = {238,238,236};
        Palette::c16 = {255,255,255};
        Palette::palette = {
             Palette::c1,Palette::c2,Palette::c3,Palette::c4
            ,Palette::c5,Palette::c6,Palette::c7,Palette::c8
            ,Palette::c9,Palette::c10,Palette::c11,Palette::c12
            ,Palette::c13,Palette::c14,Palette::c15,Palette::c16
            };
    }
} DSPal;
