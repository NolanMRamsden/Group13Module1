/*
 * Ball.c
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 */
#include "../Headers/Definitions.h"
#include "../Headers/Ball.h"

Ball *startBall(float x, float y, float xVelo, float yVelo)
{
	Ball *ball;
	ball->x = x;
	ball->y = y;
	ball->xVelo = xVelo;
	ball->yVelo = yVelo;
	ball->alive = 1;
	return ball;
}

void updatePosition(Ball *ball)
{
	ball->x += ball->xVelo;
	ball->y += ball->yVelo;
	if (ball->x < leftScreenBound)
		ball->x = leftScreenBound;
	if (ball->x > rightScreenBound)
		ball->x = rightScreenBound;
	if (ball->y < bottomScreenBound)
		ball->y = bottomScreenBound;
	if (ball->y > topScreenBound)
		ball->y = topScreenBound;
}
