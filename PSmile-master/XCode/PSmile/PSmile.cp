/*
 *  PSmile.cp
 *  PSmile
 *
 *  Created by Bryan Chung on 30/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "PSmile.h"
// #include "PSmilePriv.h"

CPSmile::CPSmile(void)
{
}

CPSmile::~CPSmile(void)
{
}

float CPSmile::getSmile(float* img, int w, int h)
{
//	int n = w*h;
	MPSmile smileFinder;
	VisualObject faces;
	RImage<float> rimage(img, w, h);
	float amount = -1.0f;
	if (!smileFinder.findSmiles(rimage, faces))
	{
		if (faces.size()==1) 
		{
			FaceObject* face = static_cast<FaceObject*> (*(faces.begin()));
			amount = face->activation;
		}
	}
	return amount;
}

