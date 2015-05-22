#include "stdafx.h"
#include "Panel.h"


Panel::Panel()
{

}
Panel::Panel(int locX, int locY, int width, int height, float order)
	:Container(locX, locY, width, height, order)
{

}


Panel::~Panel()
{
	
}
void Panel::OnLoaded(void)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnLoaded();
	}

	color = Color(255, 0, 0);
}
void Panel::OnPaint()
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnPaint();
	}

	SetColor(color.r, color.g, color.b);

	FillRectangle(position.X, position.Y, Width, Height, SortOrder);
}
void Panel::SetNewColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}