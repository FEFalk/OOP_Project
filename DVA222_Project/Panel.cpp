#include "stdafx.h"
#include "Panel.h"


Panel::Panel()
{
	bgColor = Color(255, 0, 0);
}
Panel::Panel(int locX, int locY, int width, int height, float order)
	:Container(locX, locY, width, height, order)
{
	bgColor = Color(255, 0, 0);
}


Panel::~Panel()
{
	
}
void Panel::OnLoaded(void)
{
	Container::OnLoaded();
	
}
void Panel::OnPaint()
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->SetPosition(controls[i]->GetOffset().X + position.X, controls[i]->GetOffset().Y + position.Y);
	}

	Container::OnPaint();
	SetColor(bgColor.r, bgColor.g, bgColor.b);
	FillRectangle(position.X, position.Y, Width, Height, SortOrder);
}
void Panel::SetBackgroundColor(int r, int g, int b)
{
	bgColor = Color(r, g, b);
}