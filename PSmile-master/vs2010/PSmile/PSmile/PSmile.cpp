#include "stdafx.h"
#include "PSmile.h"

CPSmile::CPSmile(void)
{
}


CPSmile::~CPSmile(void)
{
}

float CPSmile::getSmile(float* img, int w, int h)
{
	int n = w*h;
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
