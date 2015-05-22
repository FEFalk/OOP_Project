#pragma once

#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"

class ImageBox :
	public ControlBase
{
public:
	ImageBox(int locX, int locY, int width, int height);
	~ImageBox(void);

	void OnLoaded();
	void OnPaint(void);

	Bitmap *image;
};

