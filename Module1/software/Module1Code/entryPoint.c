
#include "Headers/headers.h"

static int currentState;
static int prevState;

void changeState(int state)
{
	prevState = currentState;
	currentState = state;
}

int main()
{
	initVGA();
	//level = malloc(sizeof(Level));

	initLevel(3);


	drawStart(level);

	initInterrupt();
	currentState=prevState=Playing;

	int counter=0;
	while(1)
	{
		counter++;
		if(counter>650000)
		{
			counter=0;
			if(getSwitchIndex()== 0)
				changeState(Paused);
			else if(getSwitchIndex()== 1)
				changeState(Menu);
			else
				changeState(Playing);
		}

		if(prevState != currentState)
		{
			if(currentState == Menu)
			{
				stopInterrupt();
				drawText("Menu",40,30,1);
			}else if(currentState == Paused)
			{
				stopInterrupt();
				drawText("Paused",40,30,0);
			}else if(currentState == Playing)
			{
				drawText("      ",40,30,0);
				initInterrupt();
			}
			prevState = currentState;
		}
	}
	return 0;
}


