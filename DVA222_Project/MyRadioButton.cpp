#include "StdAfx.h"
#include "MyRadioButton.h"

MyRadioButton::MyRadioButton()
{
	pressed = false;
}

MyRadioButton::MyRadioButton(int locX, int locY, int radius)
	: MyButton(locX, locY, radius * 2, radius * 2)
{
	pressed = false;
}



void MyRadioButton::OnLoaded()
{
	
}
void MyRadioButton::OnPaint()
{
	SetColor(0, 0, 0);
    if (pressed)
	{
		DrawCircle(position.X, position.Y, Width, SortOrder);
		DrawCircle(position.X, position.Y, Width-5, SortOrder);
	}
    else
		DrawCircle(position.X, position.Y, Width, SortOrder);
    
}

void MyRadioButton::OnMouseMove(int button, int x, int y)
{
	if (x > position.X -15 && x < position.X + 15 && y>position.Y -15 && y < position.Y + 15)
		hit = true;
	else
		hit = false;
}

void MyRadioButton::OnMouseDown(int button, int x, int y)
{
    if(hit && button==MOUSE_LEFT)
        pressed = true;
	else
		pressed = false;
}

void MyRadioButton::OnMouseUp(int button, int x, int y)
{

}