/*
 * Level.c
 *
 *  Created on: Sep 25, 2014
 *      Author: Karen
 */
#include "../Headers/Level.h"

void initLevel(int lev)
{
	level->balls = malloc(sizeof(Ball));
	startBall(level->balls,40,40,200,100);
	level->balls2 = malloc(sizeof(Ball));
	startBall(level->balls2,40,60,300,300);
	level->balls3 = malloc(sizeof(Ball));
	startBall(level->balls3,10,60,100,320);

	level->paddle = malloc(sizeof(Paddle));
	initPaddle(level->paddle,30);

	level->brickRow = malloc(sizeof(BrickRow));
	initBrickRow(level->brickRow,2);
}


void drawStart(Level *level)
{
	drawBall(level->balls);
	drawBall(level->balls2);
	drawBall(level->balls3);
	drawPaddle(level->paddle);
	int i=0;
	for(i=0;i<bricksPerRow;i++)
		drawBrick(level->brickRow->bricks[i]);
}
