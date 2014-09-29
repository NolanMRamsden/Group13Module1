/*
 * Ball.c
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 */
#include "../Headers/Definitions.h"
#include "../Headers/Ball.h"

void startBall(Ball *ball, int x, int y, int xVelo, int yVelo)
{
	ball->x = x*100;
	ball->y = y*100;
	ball->xVelo = xVelo;
	ball->yVelo = yVelo;
	ball->alive = 1;
}

void updatePosition(Ball *ball)
{
	ball->x += ball->xVelo;
	ball->y += ball->yVelo;

	int x = ball->x/100;
	int y = ball->y/100;
	if (x <= leftScreenBound)
	{
		ball->x = leftScreenBound*100;
		bounceWall(ball);
	}
	else if (x >= rightScreenBound)
	{
		ball->x = rightScreenBound*100;
		bounceWall(ball);
	}
	if (y >= bottomScreenBound)
	{
		ball->y = bottomScreenBound*100;
		bounceRoof(ball);
	}
	else if (y <= topScreenBound)
	{
		ball->y = topScreenBound*100;
		bounceRoof(ball);
	}
}

void bounceWall(Ball *ball)
{
	ball->xVelo = -ball->xVelo;
}

void bounceRoof(Ball *ball)
{
	ball->yVelo = -ball->yVelo;
}


