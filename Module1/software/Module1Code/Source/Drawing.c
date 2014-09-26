/*
 * Drawing.c
 *
 *  Created on: Sep 25, 2014
 *      Author: William
 */

#include "../Headers/Drawing.h"

static alt_up_pixel_buffer_dma_dev* pixel_buffer;
static alt_up_char_buffer_dev *char_buffer;
static prevX;
static prevY;
void initVGA()
{
	// Use the name of your pixel buffer DMA core
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0");

	// Set the background buffer address � Although we don�t use the
	//background, // they only provide a function to change the background
	// buffer address, so
	// we must set that, and then swap it to the foreground.
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, PIXEL_BUFFER_BASE);
	// Swap background and foreground buffers
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	// Wait for the swap to completewhile
	(alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));
	// Clear the screen
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);

	// Initialize character buffer
	char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
	alt_up_char_buffer_init(char_buffer);
}

void drawBall(int x,int y, int colour)
{
	if(colour != background)
			drawBall(prevX,prevY,background);

	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y,x+4, y, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+1, y+1,x+5, y+1, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+2,x+6, y+2, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+3,x+6, y+3, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x, y+4,x+6, y+4, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+1, y+5,x+5, y+5, colour, 0);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, x+2, y+6,x+4, y+6, colour, 0);

	prevX=x;
	prevY=y;


}
