/*
 * Ball.h
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 */
#ifndef BALL_H_
#define BALL_H_

#include "../Headers/Definitions.h"
const int ballMoveScale = 1;

typedef struct Ball
{
	float x;
	float y;
	float xVelo;
	float yVelo;
	int alive;
} Ball;

extern Ball *startBall(float x, float y, float xVelo, float yVelo);
extern void updatePosition(Ball *ball);
extern void bounceWall(Ball *ball);
extern void bounceRoof(Ball *ball);

#endif /* BALL_H_ */
