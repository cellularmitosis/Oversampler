/*
Oversampler.cpp - A simple library which makes it easier to oversample Arduino
ADC inputs.
https://github.com/cellularmitosis/Oversampler
v0.2 (Sept 18, 2013)

Copyright (c) 2013 Jason Pepas

This software is released under the terms of the MIT License:

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "Oversampler.h"
#include "Arduino.h"

#include <stdlib.h>


OversamplerData* createOversamplerData()
{
	// thanks to http://stackoverflow.com/a/252810  --jpepas
	OversamplerData *data = NULL;
	data = (OversamplerData*)malloc(sizeof(OversamplerData));
 	if (data == NULL)
 	{
		return NULL;
	}

	initOversamplerData(data);  
  
	return data;
}


void initOversamplerData(OversamplerData *data)
{
	data->accumulator = 0;
	data->averagedValue = 0;
}


uint16_t analogReadNx(OversamplerData *data, uint8_t pin, uint8_t sampleCount, uint8_t halveCount)
{
  if (data == NULL)
  {
  	return 0;
  }
  
  data->accumulator = 0;
  for (uint8_t count=0; count < sampleCount; count++)
  {
    data->accumulator += analogRead(pin);
  }
  data->averagedValue = data->accumulator >> halveCount;
  return data->averagedValue;
}


uint16_t analogRead2x(OversamplerData *data, uint8_t pin)
{
	return analogReadNx(data, pin, 2, 1);
}


uint16_t analogRead4x(OversamplerData *data, uint8_t pin)
{
	return analogReadNx(data, pin, 4, 2);
}


uint16_t analogRead8x(OversamplerData *data, uint8_t pin)
{
	return analogReadNx(data, pin, 8, 3);
}


uint16_t analogRead16x(OversamplerData *data, uint8_t pin)
{
	return analogReadNx(data, pin, 16, 4);
}


uint16_t analogRead32x(OversamplerData *data, uint8_t pin)
{
	return analogReadNx(data, pin, 32, 5);
}


uint16_t analogRead64x(OversamplerData *data, uint8_t pin)
{
	return analogReadNx(data, pin, 64, 6);
}

