#include "StdAfx.h"
#include "ImageBox.h"

ImageBox::ImageBox(int locX, int locY, int width, int height)
    : ControlBase(locX, locY, width, height, 0)
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
	DrawBitmap(*image, position.X, position.Y, Width, Height);
}