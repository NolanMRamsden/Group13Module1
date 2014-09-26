/*
 * Interrupt.c
 *
 *  Created on: Sep 24, 2014
 *      Author: Nolan
 */

#include "../Headers/Interrupt.h"

static alt_alarm alarm;
static int i;
static Ball *ball;

alt_u32 interruptFunction(void* context)
{
	updatePosition(ball);
	drawBall(ball->x/100,ball->y/100,0xFFFF);
	return alt_ticks_per_second()/screenRefreshRate;
}

void initInterrupt()
{
	i=0;
	ball = malloc(sizeof(Ball));
	startBall(ball,10,10,400,200);
	alt_alarm_start (&alarm, alt_ticks_per_second()/screenRefreshRate, interruptFunction, NULL );
}

void stopInterrupt()
{
	alt_alarm_stop (&alarm);
}
