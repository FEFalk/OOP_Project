#include "StdAfx.h"
#include "ImageBox.h"

ImageBox::ImageBox(int locX, int locY, int width, int height)
    : ControlBase(locX, locY, width, height)
{

}


ImageBox::~ImageBox(void)
{
	delete image;
}

void ImageBox::OnLoaded()
{
	image = new Bitmap("randomImage.bmp");
}

void ImageBox::OnPaint()
{
	DrawBitmap(*image, X,Y,Width, Height);
}