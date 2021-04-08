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

#ifndef _SENSORS_H_
#define _SENSORS_H_

class btSensors {
public:
	btSensors(void);
	~btSensors(void);
	
	const bool	StartUp(void);
	void	ShutDown(void);
	
	inline bool	TurnOff(void) const { return m_offComand; };
	
private:
	bool	m_offComand;
};

#endif //!_SENSORS_H_