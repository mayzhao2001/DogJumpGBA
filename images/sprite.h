/*
 * Exported with nin10kit v1.7
 * Invocation command was nin10kit --mode=sprites --for_bitmap --bpp=4 --transparent=FF00FF sprite Animated_Sprite.gif 
 * Time-stamp: Friday 04/09/2021, 04:26:24
 * 
 * Image Information
 * -----------------
 * Animated_Sprite.gif (frame 0) 64@64
 * Animated_Sprite.gif (frame 1) 64@64
 * Animated_Sprite.gif (frame 2) 64@64
 * Animated_Sprite.gif (frame 3) 64@64
 * Animated_Sprite.gif (frame 4) 64@64
 * Animated_Sprite.gif (frame 5) 64@64
 * Animated_Sprite.gif (frame 6) 64@64
 * Animated_Sprite.gif (frame 7) 64@64
 * Transparent color: (255, 0, 255)
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef SPRITE_H
#define SPRITE_H

#define SPRITE_PALETTE_TYPE (0 << 13)
#define SPRITE_DIMENSION_TYPE (1 << 6)

extern const unsigned short sprite_palette[256];
#define SPRITE_PALETTE_SIZE 512
#define SPRITE_PALETTE_LENGTH 256

extern const unsigned short sprite[8192];
#define SPRITE_SIZE 16384
#define SPRITE_LENGTH 8192

#define ANIMATED_SPRITE0_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE0_ID 512

#define ANIMATED_SPRITE1_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE1_ID 576

#define ANIMATED_SPRITE2_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE2_ID 640

#define ANIMATED_SPRITE3_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE3_ID 704

#define ANIMATED_SPRITE4_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE4_ID 768

#define ANIMATED_SPRITE5_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE5_ID 832

#define ANIMATED_SPRITE6_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE6_ID 896

#define ANIMATED_SPRITE7_PALETTE_ID (0 << 12)
#define ANIMATED_SPRITE7_ID 960

extern const unsigned short Animated_Sprite_frames[8];
#define ANIMATED_SPRITE_FRAMES 8

#define ANIMATED_SPRITE_SPRITE_SHAPE (0 << 14)
#define ANIMATED_SPRITE_SPRITE_SIZE (3 << 14)

#endif

