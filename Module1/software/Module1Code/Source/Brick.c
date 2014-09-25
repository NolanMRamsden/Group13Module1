/*
 * Brick.c
 *
 *  Created on: Sep 24, 2014
 *      Author: Nolan
 */


#include "../Headers/Brick.h"

Brick *initBrick(int x, int y)
{
	Brick *brick;
	brick->x = x;
	brick->y = y;
	brick->width = brickWidth;
	brick->height = brickHeight;
	brick->health = startBrickHealth;
	return brick;
}

void hit(Brick *brick)
{
	brick->health--;
	if(brick->health < 0)
		brick->health=0;
}
