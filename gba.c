#include "gba.h"

#define MAX_ROWS 160
#define MAX_COLS 240

volatile unsigned short *videoBuffer = (volatile unsigned short *) 0x6000000;
u32 vBlankCounter = 0;

void waitForVBlank(void) {
  // TODO: IMPLEMENT

  // (1)
  // Write a while loop that loops until we're NOT in vBlank anymore:
  // (This prevents counting one VBlank more than once if your app is too fast)

  // (2)
  // Write a while loop that keeps going until we're in vBlank:

  // (3)
  // Finally, increment the vBlank counter:

  while (SCANLINECOUNTER > 160);
  while (SCANLINECOUNTER < 160);
  vBlankCounter++;
}

static int __qran_seed = 42;
static int qran(void) {
  __qran_seed = 1664525 * __qran_seed + 1013904223;
  return (__qran_seed >> 16) & 0x7FFF;
}

int randint(int min, int max) { return (qran() * (max - min) >> 15) + min; }

void setPixel(int row, int col, u16 color) {
  // TODO: IMPLEMENT
  UNUSED(row);
  UNUSED(col);
  UNUSED(color);

  *(videoBuffer + OFFSET(row, col, MAX_COLS)) = color;
}


void drawRectDMA(int row, int col, int width, int height, volatile u16 color) {
  // TODO: IMPLEMENT
  UNUSED(row);
  UNUSED(col);
  UNUSED(width);
  UNUSED(height);
  UNUSED(color);

  volatile unsigned short lcolor;        
  lcolor = color;        
  for(int i = 0; i < height; i++) {
    //  for(int c=0; c<width; c++)
      //  setPixel(row+r, col+c, color);
        DMA[3].src = & lcolor;
        DMA[3].dst = & videoBuffer[OFFSET(row + i,col,MAX_COLS)];
        DMA[3].cnt = width | DMA_ON | DMA_SOURCE_FIXED | DMA_DESTINATION_INCREMENT;
      }
  }

void drawFullScreenImageDMA(const u16 *image) {
  // TODO: IMPLEMENT
  UNUSED(image);

  int row = 0;
  for (int i = 0; i < MAX_ROWS; i++) {
        DMA[3].src = image + OFFSET(i, 0, MAX_COLS);
        DMA[3].dst = videoBuffer + OFFSET(row + i, 0, MAX_COLS);
        DMA[3].cnt = MAX_COLS | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
    }
}

void drawImageDMA(int row, int col, int width, int height, const u16 *image) {
  // TODO: IMPLEMENT
  UNUSED(row);
  UNUSED(col);
  UNUSED(width);
  UNUSED(height);
  UNUSED(image);

      for (int i = 0; i < height; i++) {
        DMA[3].src = image + OFFSET(i, 0, width);
        DMA[3].dst = videoBuffer + OFFSET(row + i, col, MAX_COLS);
        DMA[3].cnt = width | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
    }
}
void fillScreenDMA(volatile u16 color) {
  // TODO: IMPLEMENT
  UNUSED(color);

  DMA[3].src = &color;
  DMA[3].dst = videoBuffer;
  DMA[3].cnt = 38400 | DMA_ON | DMA_SOURCE_FIXED;
}

void drawChar(int row, int col, char ch, u16 color) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      if (fontdata_6x8[OFFSET(j, i, 6) + ch * 48]) {
        setPixel(row + j, col + i, color);
      }
    }
  }
}

void drawString(int row, int col, char *str, u16 color) {
  while (*str) {
    drawChar(row, col, *str++, color);
    col += 6;
  }
}

void drawCenteredString(int row, int col, int width, int height, char *str, u16 color) {
  u32 len = 0;
  char *strCpy = str;
  while (*strCpy) {
    len++;
    strCpy++;
  }

  u32 strWidth = 6 * len;
  u32 strHeight = 8;

  int new_row = row + ((height - strHeight) >> 1);
  int new_col = col + ((width - strWidth) >> 1);
  drawString(new_row, new_col, str, color);
}

void undrawImageDMA(int row, int col, int width, int height, const u16 *image) {
    for (int i = 0; i < height; i++) {
        DMA[DMA_CHANNEL_3].src = image + OFFSET(row + i, col, 240);
        DMA[DMA_CHANNEL_3].dst = videoBuffer + OFFSET(row + i, col, 240);
        DMA[DMA_CHANNEL_3].cnt = width |
                                 DMA_SOURCE_INCREMENT |
                                 DMA_DESTINATION_INCREMENT |
                                 DMA_ON;
    }
}

void drawImageAtCol(int row, int col, int cOffset, int width, int height, const u16 *image) {
    for (int i = 0; i < height; i++) {
        DMA[DMA_CHANNEL_3].src = image + OFFSET(i, cOffset, width);
        DMA[DMA_CHANNEL_3].dst = videoBuffer + OFFSET(row + i, col, 240);
        DMA[DMA_CHANNEL_3].cnt = (width - cOffset) |
                                 DMA_SOURCE_INCREMENT |
                                 DMA_DESTINATION_INCREMENT |
                                 DMA_ON;
    }
}
