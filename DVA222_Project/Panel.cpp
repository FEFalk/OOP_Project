#include "stdafx.h"
#include "Panel.h"


Panel::Panel()
{
	panel = new Container();
}
Panel::Panel(int locX, int locY, int width, int height, int size):Container(locX, locY, width, height, size)
{
	panel = (Container *)realloc(panel, size * sizeof(Container));
	this->size = size;
	size++;
}


Panel::~Panel()
{
}
void Panel::OnLoaded(void)
{
	color = Color(255, 0, 0);
}
void Panel::OnPaint()
{
	SetColor(color.r, color.g, color.b);

	DrawRectangle(X, Y, Width, Height);
	FillRectangle(X, Y, Width, Height);
}
void Panel::SetNewColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}