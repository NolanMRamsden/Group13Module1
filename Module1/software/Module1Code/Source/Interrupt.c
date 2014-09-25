/*
 * Interrupt.c
 *
 *  Created on: Sep 24, 2014
 *      Author: Nolan
 */
#include "../Headers/Definitions.h"
#include "sys/alt_alarm.h"
#include "alt_types.h"

static alt_alarm alarm;


alt_u32 interruptFunction(void* context)
{

	return alt_ticks_per_second()/screenRefreshRate;
}

void initInterrupt()
{
	alt_alarm_start (&alarm, alt_ticks_per_second()/screenRefreshRate, interruptFunction, NULL );
}

void stopInterrupt()
{
	alt_alarm_stop (&alarm);
}
