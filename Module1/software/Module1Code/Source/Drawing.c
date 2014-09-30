/*
 * Drawing.c
 *
 *  Created on: Sep 25, 2014
 *      Author: William
 */

#include "../Headers/Drawing.h"

static alt_up_pixel_buffer_dma_dev* pixel_buffer;
//static alt_up_pixel_buffer_dma_dev* pixel_buffer2;
//static int currentBuffer;
static alt_up_char_buffer_dev *char_buffer;

void initVGA()
{
	// Use the name of your pixel buffer DMA core
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0");

	// Set the background buffer address – Although we don’t use the
	//background,
	// they only provide a function to change the background
	// buffer address, so
	// we must set that, and then swap it to the foreground.
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, PIXEL_BUFFER_BASE);
	// Swap background and foreground buffers
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	// Wait for the swap to complete while
	(alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));
	// Clear the screen
	clearScreen();

	// Initialize character buffer
	char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
	alt_up_char_buffer_init(char_buffer);
}

void clearScreen()
{
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, background);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 0, topScreenBound,rightScreenBound+1, topScreenBound, screenOutline, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 0, topScreenBound, 0, bottomScreenBound+1,screenOutline, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, rightScreenBound+1, bottomScreenBound+1,rightScreenBound+1, topScreenBound, screenOutline, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, rightScreenBound+1, bottomScreenBound+1, 0,bottomScreenBound+1, screenOutline, 0);
}

void drawBall(Ball *ball)
{
	int colour = ball->colour;
	int x      = ball->x/100;
	int y      = ball->y/100;

	coverBall(ball->prevX,ball->prevY,background);

	if(ball->alive == 0)
		return;

	coverBall(x,y,colour);
	ball->prevX=x;
	ball->prevY=y;
}

void coverBall(int x, int y, int colour)
{
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y,x+4, y, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+1, y+1,x+5, y+1, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+2,x+6, y+2, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+3,x+6, y+3, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+4,x+6, y+4, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+1, y+5,x+5, y+5, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y+6,x+4, y+6, colour, 0);
}

void drawPaddle(Paddle *paddle)
{
	int colour = paddle->colour;
	int x      = paddle->x/100;
	int y      = paddle->y/100;
	int width  = paddle->width;
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, paddle->prevX, paddle->prevY,paddle->prevX+width-1, paddle->prevY, background, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, paddle->prevX, paddle->prevY+1,paddle->prevX+width-1, paddle->prevY+1, background, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, paddle->prevX, paddle->prevY+2,paddle->prevX+width-1, paddle->prevY+2, background, 0);
	coverPaddle(x,y,width,colour);
	paddle->prevX=x;
	paddle->prevY=y;
}

void coverPaddle(int x, int y, int width, int colour)
{
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y,x+1, y, Red, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+1,x+1, y+1, Red, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+2,x+1, y+2, Red, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+width-2, y,x+width-1, y, Red, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+width-2, y+1,x+width-1, y+1, Red, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+width-2, y+2,x+width-1, y+2, Red, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y,x+width-3, y, White, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y+1,x+width-3, y+1, LightGrey, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y+2,x+width-3, y+2, DarkGrey, 0);
}

void drawBrick (Brick *brick)
{
	coverBrick(brick->x,brick->y,0);
	if(brick->prevHealth == brick->health || brick->health==0)
		return;

	coverBrick(brick->x,brick->y,brick->health);

	brick->prevHealth = brick->health;
}

void coverBrick(int x, int y, int health)
{
	int colour= background;
	if (health>=3)
	{
		colour = 0xFFFF;
	}
	else if (health==2)
	{
		colour = 0x5555;
	}
	else if (health==1)
	{
		colour = 0x2222;
	}
	int i = 0;
	for (i=0;i < brickHeight;i++)
	{
		alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+i,x+brickWidth-1, y+i, colour, 0);
	}
}

void drawText(char *text, int x, int y, int selected)
{
	if(selected)
		alt_up_char_buffer_string(char_buffer,"-> ",x-3,y);
	else
		alt_up_char_buffer_string(char_buffer,"  ",x-3,y);

	alt_up_char_buffer_string(char_buffer,text,x,y);
}
