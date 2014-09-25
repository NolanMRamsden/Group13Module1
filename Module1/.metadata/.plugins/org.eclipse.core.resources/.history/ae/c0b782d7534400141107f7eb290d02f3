/*
 * Input.c
 *
 *  Created on: Sep 24, 2014
 *      Author: Karen
 */
#include "../Headers/Definitions.h"
const int scalars[4] = {-5,-2,2,5};
//returns a number from -10 to 10 for the scalar value of horizontal movement
int getUserInput()
{
	int i=0;
	for(i=0;i<4;i++)
	{
		if( (*pushbutton & (1 << i)) == 0)
			return scalars[i];
	}
	return 0;
}

int getSwitchIndex()
{
	int i=0;
	for(i=0;i<8;i++)
	{
		if( (*switches & (1 << i)) == 1)
			return i;
	}
	return -1;
}

void turnOnLED(int index)
{
	if (index > 8)
		return;
	*leds = *leds | (1<<index);
}

void turnOffLED(int index)
{
	if (index > 8)
		return;
	*leds = *leds & (256 & ~(1<<index));
}
