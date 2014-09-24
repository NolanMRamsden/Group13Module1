/*
 * Definitions.h
 *
 *  Created on: Sep 23, 2014
 *      Author: Nolan
 *
 *      Defines memory location for IO
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#define switches   (volatile char*)   0x00004030
#define leds       (volatile char*)   0x00004020
#define pushbutton (volatile char*)   0x00004000

#define leftScreenBound   0
#define rightScreenBound  320
#define topScreenBound    0
#define bottomScreenBound 320

#endif /* DEFINITIONS_H_ */
