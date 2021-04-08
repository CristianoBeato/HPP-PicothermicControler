/*
# ------------------------------------------------------------------------------------
#	 Beato's raspberry pi pico termic controler
# ------------------------------------------------------------------------------------
#
#	Copyright(c) 2021, Cristiano B.Santos <cristianobeato_dm@hotmail.com>
#
#	MIT License
#
#	Permission is hereby granted, free of charge, to any person obtaining a copy
#	of this software and associated documentation files(the "Software"), to deal
#	in the Software without restriction, including without limitation the rights
#	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#	copies of the Software, and to permit persons to whom the Software is
#	furnished to do so, subject to the following conditions :
#
#	The above copyright notice and this permission notice shall be included in
#	all copies or substantial portions of the Software.
#
#	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
#	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#	THE SOFTWARE.
#
#----------------------------------------------------------------------#
*/

#include "precompiled.h"

static btSensors s_sensors = btSensors();
static btControls s_controls = btControls();

static const unsigned int k_UPDATE_TIME = 1000; // whait one second before update

int main()
{
	// init all pico subsistems
	stdio_init_all();
	
	// initialize sub systems
	if(!s_sensors.StartUp())
	{
		printf("ERROR: Can't initialize sensors!\n");
		return -1;
	}
	
	if(!s_controls.StartUp())
	{
		printf("ERROR: Can't initialize controls!\n");
		return -1;
	}
	
	do
	{
		//TODO: Get begin time
		unsigned int startMs = 0; 
		
		// ruin Sensors time
		
		
		// TODO: get the elapset time of process 
		unsigned int elapsedTime = 0 - startMs; 
		
		// sleep the rest of the time
		sleep_ms(k_UPDATE_TIME - elapsedTime);
	}
	while(!s_sensors.TurnOff());
	
	// Clear to exit
	s_controls.ShutDown();
	s_sensors.ShutDown();
	
    return 0;
}