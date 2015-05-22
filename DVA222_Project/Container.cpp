#include "stdafx.h"
#include "Container.h"


Container::Container()
{
	container = new ControlBase();
}
Container::Container(int locX, int locY, int width, int height):ControlBase(locX, locY, width, height)
{

}


Container::~Container()
{
}
void Container::OnLoaded(void)
{
	color = Color(255, 0, 0);
}
void Container::OnPaint()
{
	SetColor(color.r, color.g, color.b);
	FillRectangle(X, Y, Width, Height);
}
void Container::SetNewColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}