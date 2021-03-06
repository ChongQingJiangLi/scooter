/*
 * (c) 2003 Trevor Blackwell <tlb@tlb.org>
 *
 *  This file is part of the scooter onboard code package.
 *  
 *  Scooter is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  Scooter is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with Autopilot; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _ADC_H_
#define _ADC_H_

#include "string.h"

extern void adc_init( void );
uint8_t adc_collect_samples(uint16_t *dst, int minsamples);

#endif
