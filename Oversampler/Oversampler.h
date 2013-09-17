/*
Oversampler.h - A simple library which makes it easier to oversample Arduino
ADC inputs.
https://github.com/cellularmitosis/Oversampler
v0.1 (Sept 15, 2013)

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

#ifndef Oversampler_h
#define Oversampler_h

#include <stdint.h>

struct _OversamplerData
{
  uint16_t accumulator;
  uint16_t averagedValue;
};

typedef struct _OversamplerData OversamplerData;

OversamplerData* createOversamplerData();
uint16_t analogRead2x(OversamplerData *data, uint8_t pin);
uint16_t analogRead4x(OversamplerData *data, uint8_t pin);
uint16_t analogRead8x(OversamplerData *data, uint8_t pin);
uint16_t analogRead16x(OversamplerData *data, uint8_t pin);
uint16_t analogRead32x(OversamplerData *data, uint8_t pin);
uint16_t analogRead64x(OversamplerData *data, uint8_t pin);

#endif // Oversampler_h
