
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
	// Initialize SD Card
	 sdcard_Init();
	 int score = 0;

	while(!sdcard_isPresent())
	{
		printf("No SD Card inserted \n");
	}
	while(!sdcard_isFAT16())
	{
		printf("SD Card must be FAT16 formatted! \n");
	}

	 char read_data [100] = {0}; // The score will be read into this buffer
	 printf("read data: %s \n", read_data);
	 score = get_score_from_sd_card(read_data);

	 score +=2;

	// printf("going to write: %d \n", score);

	write_score_to_sd_card(score);

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


