#include "StdAfx.h"
#include "CheckBoxButton.h"

CheckBoxButton::CheckBoxButton()
{
	checked = false;
}

CheckBoxButton::CheckBoxButton(int locX, int locY)
	: MyButton(locX, locY, 30, 30)
{
	checked = false;
}



void CheckBoxButton::OnLoaded()
{

}
void CheckBoxButton::OnPaint()
{
	SetColor(0, 255, 0);
    if (checked)
	{
		DrawRectangle(position.X, position.Y, Width, Height, SortOrder);
		DrawRectangle(position.X+3, position.Y+3, 24, 24, SortOrder);
	}
    else
		DrawRectangle(position.X, position.Y, Width, Height, SortOrder);
    
}

void CheckBoxButton::OnMouseMove(int button, int x, int y)
{
	if (x>position.X && x < position.X + Width && y>position.Y && y < position.Y + Height)
		hit = true;
	else
		hit = false;
}

void CheckBoxButton::OnMouseDown(int button, int x, int y)
{
    if(hit && button==MOUSE_LEFT)
        pressed = true;
	else
		pressed = false;
}

void CheckBoxButton::OnMouseUp(int button, int x, int y)
{
	if(pressed && hit && checked == false)
		checked = true;
	else if(pressed && hit && checked == true)
		checked = false;
}