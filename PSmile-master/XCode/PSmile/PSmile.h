/*
 *  PSmile.h
 *  PSmile
 *
 *  Created by Bryan Chung on 30/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PSmile_
#define PSmile_

/* The classes below are exported */
#pragma GCC visibility push(default)

#include "pSmile_PSmile.h"
#include "smile.h"
#include "rimage.h"

class CPSmile
{
	public:
		CPSmile(void);
		virtual ~CPSmile(void);
		float getSmile(float*, int, int);
};

#pragma GCC visibility pop
#endif
