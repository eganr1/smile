#pragma once

#include <jni.h>
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

