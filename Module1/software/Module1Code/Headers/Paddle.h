/*
 * Paddle.h
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 */
#include "../Headers/Definitions.h"

#ifndef PADDLE_H_
#define PADDLE_H_

const int paddleMoveScale = 1;
const int paddleHeight=10;
const int paddleStartWidth=50;

typedef struct Paddle
{
	float x;
	float y;
	int width;

} Paddle;

extern Paddle *initPaddle(float x);
extern void moveHorizontal(Paddle *paddle, int x);


#endif /* PADDLE_H_ */
