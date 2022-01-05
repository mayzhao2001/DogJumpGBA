#ifndef MAIN_H
#define MAIN_H

#include "gba.h"

// TODO: Create any necessary structs

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/


typedef struct
{
  volatile int visible;
  int col;
  int row;
  
} SUNFLOWER;

typedef struct
{
  volatile int visible;
  int row;
  int col;
  
} CLOUD;

typedef struct
{
  int row;
  int col;
  
} DOG;


void reset(void);
void sunflowerSetVisible(SUNFLOWER *sunflower);
void generateSunflowers(void);
void drawSunflower(void);
void drawSunflowerHelper(SUNFLOWER *sunflower);
void undrawImageDMA(int row, int col, int width, int height, const u16 *image);
void drawImageAtCol(int row, int col, int cOffset, int width, int height, const u16 *image);
void drawDog(void);
void undrawFlowers(void);
void undrawFlowersHelper(SUNFLOWER *sun, const u16 *image);
void moveFlower(void);
int checkCollision(DOG *doggy, SUNFLOWER *sunny);
int isAlive(void);
int getStringWidth(char *string);

#endif
