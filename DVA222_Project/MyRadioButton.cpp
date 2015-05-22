#include "StdAfx.h"
#include "MyRadioButton.h"

MyRadioButton::MyRadioButton()
{
	checked=false;
}

MyRadioButton::MyRadioButton(int locX, int locY)
	: MyButton(locX, locY, 30, 30)
{
	checked=false;
}



void MyRadioButton::OnLoaded()
{
	
}
void MyRadioButton::OnPaint()
{
	SetColor(255, 0, 0);
    if (checked)
	{
		DrawCircle(position.X, position.Y, 15);
		DrawCircle(position.X, position.Y, 10);
	}
    else
		DrawCircle(position.X, position.Y, 15);
    
}

void MyRadioButton::OnMouseMove(int button, int x, int y)
{
	if (x>position.X && x < position.X + Width && y>position.Y && y < position.Y + Height)
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
	if(pressed && hit)
		checked = true;
}