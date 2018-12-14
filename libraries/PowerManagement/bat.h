/*
****************************************************************************
* Copyright (c) 2017 Arduino srl. All right reserved.
*
* File : bat.h
* Date : 2017/04/10
* Revision : 0.0.1 $
* Author: jeff[at]arduino[dot]org
* Modify : Frank Wu (frank@dreamtechio.org)
*
****************************************************************************

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef __BAT_H__
#define __BAT_H__

#include <Wire.h>
#include <stdint.h>
#include "Arduino.h"

extern "C" {
  #include "nrf_delay.h"
}

#define REC_BUF_LENGTH 4

class bat {
public:
	bat(void);
	double analogRead(void);
  int capacity(void);
private:
	uint8_t recBuffer[REC_BUF_LENGTH];

};

#endif __BAT_H___