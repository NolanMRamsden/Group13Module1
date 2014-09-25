/*
 * Brick.h
 *
 *  Created on: Sep 24, 2014
 *      Author: Nolan
 */

#ifndef BRICK_H_
#define BRICK_H_

const int brickHeight=10;
const int brickWidth=50;
const int startBrickHealth=1;

typedef struct Brick
{
	int x;
	int y;
	int width;
	int height;
	int health;
} Brick;

extern Brick *initBrick(int x, int y);
extern void hit(Brick *brick);

#endif /* BRICK_H_ */
