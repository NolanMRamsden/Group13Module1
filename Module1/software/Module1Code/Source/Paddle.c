/*
 * Paddle.c
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 */
#include "../Headers/Definitions.h"
#include "../Headers/Paddle.h"

Paddle *initPaddle(float x)
{
	Paddle *paddle;
	paddle->x = x;
	paddle->y = paddleHeight;
	paddle->width = paddleStartWidth;
	return paddle;
}

void moveHorizontal(Paddle *paddle, int x)
{
	paddle->x += (x*paddleMoveScale);
	if ( x < leftScreenBound)
		x = leftScreenBound;
	if ( x > rightScreenBound )
		x = rightScreenBound;
}

