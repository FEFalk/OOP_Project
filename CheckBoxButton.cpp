#include "StdAfx.h"
#include "CheckBoxButton.h"

CheckBoxButton::CheckBoxButton()
{
	checked = false;
}

CheckBoxButton::CheckBoxButton(int locX, int locY)
	: MyButton(locX, locY, 15, 15)
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
    	DrawRectangle(X, Y, 15, 15);
		DrawRectangle(X+2.75, Y+2.75, 10, 10);
	}
    else
        DrawRectangle(X, Y, 15, 15);
    
}

void CheckBoxButton::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X+Width && y>Y && y < Y+Height)
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