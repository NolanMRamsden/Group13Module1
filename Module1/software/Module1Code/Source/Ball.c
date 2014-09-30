/*
 * Ball.c
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 */
#include "../Headers/headers.h"

void startBall(Ball *ball, int x, int y, int xVelo, int yVelo)
{
	ball->x = x*100;
	ball->y = y*100;
	ball->prevX = x*100;
	ball->prevY = y*100;
	ball->xVelo = xVelo;
	ball->yVelo = yVelo;
	ball->alive = 1;
	ball->colour = 0xFFFF;
}
void nullBall(Ball *ball)
{
	ball->alive = 0;
}

void updatePosition(Ball *ball)
{
	if(ball->alive == 0)
		return;

	ball->x += ball->xVelo;
	ball->y += ball->yVelo;

	int x = ball->x/100;
	int y = ball->y/100;

	//screen bounds
	if (x <= leftScreenBound)
	{
		ball->x = leftScreenBound*100;
		bounceWall(ball);
	}
	else if (x >= rightScreenBound-ballDiameter)
	{
		ball->x = rightScreenBound*100-ballDiameter*100;
		bounceWall(ball);
	}
	if (y <= topScreenBound+1)
	{
		ball->y = topScreenBound*100+100;
		bounceRoof(ball);
	}else if (y >= bottomScreenBound-ballDiameter)
	{
		ball->y = bottomScreenBound*100-ballDiameter*100;
		bounceRoof(ball);
	}

	//hit paddle
	if (ball->y >= level->paddle->y-ballDiameter*100-100
	&&  ball->y <= level->paddle->y-ballDiameter*100 + level->paddle->height*100+100)
	{
		if(ball->x >= level->paddle->x
		&& ball->x <= level->paddle->x + level->paddle->width*100
		)//&& ball->yVelo > 0)
		{
			bounceRoof(ball);
		}
	}

	//hit brick
	int i=0;
	int hasBounced=0;
	for(i=0;i<bricksPerRow;i++)
	{
		Brick brick = *level->brickRow->bricks[i];
		if(brick.health >0)
		{
			if (ball->y/100 >= brick.y + ballDiameter
			&&  ball->y/100<= brick.y + brickHeight)
			{
				if(ball->x/100+ballDiameter/2 >= brick.x -1
				&& ball->x/100-ballDiameter/2 <= brick.x + brickWidth +1)//&& ball->yVelo > 0)
				{
					/*if(ball->yVelo < 0)
						ball->y=(brick.y-ballDiameter)*100;
					else*/ if(ball->yVelo < 0)
						ball->y=(brick.y + brickHeight)*100;
					if(hasBounced==0)
						bounceRoof(ball);
					hasBounced=1;
					hit(level->brickRow->bricks[i]);
				}
			}
		}
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


