/*
 * Score.c
 *
 *  Created on: 2014-09-29
 *      Author: Gavin
 */

#include <stdbool.h>
#include <stdio.h>

int get_score_from_sd_card(char read_data[])
{
	int score = 0;
	printf("hello? \n");
	char * file_name = malloc(15);
	sdcard_FirstFile("", file_name);

	file_name = "TOTAL.txt";
	printf("file name: %s \n", file_name);
	short int file_handle = sdcard_fopen(file_name, true); // Open the score file

	printf("File handle: %d \n", file_handle);

	sdcard_ReadFile(read_data, file_handle); // Reads the score file into the supplied character buffer

	// printArray(read_data); // Print out the contents of the score for debug purposes

	// Convert the char array to an integer score
	score = atoi(read_data);
	score++;
	printf("Initial Score: %d", score);

	sdcard_fclose(file_handle);

	return score;
}

void write_score_to_sd_card(int score)
{
	int array_size = 100;
	char score_string[100] = {0};

	char read_data[100] = {0};

	int i = 0;
	printf("Integet score: %d \n", score);
	// Convert the score to a char array
	sprintf(score_string, "%d", score);

	 for(i = 0; score_string[i] != NULL; i++);
	 printf("index of the end of score_string: %d \n", i);
	 score_string[i] = '/';

	// Open the score file
	short int file_handle = sdcard_fopen("TOTAL.txt", true);

	// Read the file, retrieve it's file size, and delete everything

	sdcard_ReadFile(read_data, file_handle);
	printf("Reading from the write: %s \n", read_data);

	printf("Size of the data read: %d \n", sizeof(read_data));

	int j = 0;
	for(j = 0; read_data[j] != NULL; j++);

	printf("New size of the data read: %d \n", j);

	for(i; i < j; i++)
	{
		score_string[i] = '/';
	}
	// Write it to our lovely file
	sdcard_fclose(file_handle);
	file_handle = sdcard_fopen("TOTAL.txt", true);

	printf("write file handle: %d \n", file_handle);
	sdcard_WriteFile(score_string, file_handle);
	sdcard_fclose(file_handle);
	printf("Stored score: %s \n", score_string);

}


