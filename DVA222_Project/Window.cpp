#include "stdafx.h"
#include "Window.h"


Window::Window()
{
}
Window::Window(int locX, int locY, int width, int height):Panel(locX, locY, width, height)
{

}


Window::~Window()
{
}
void Window::OnLoaded(void)
{
	color = Color(255, 0, 0);
	titelString.clear();
	titelString.append("Window I am!");
}
void Window::OnPaint()
{
	SetNewColor(0, 255, 0);
	DrawRectangle(X, Y, Width+1, Height+1);
	SetNewColor(255, 0, 0);
	FillRectangle(X, Y, Width, Height);
	SetNewColor(0, 0, 255);
	DrawString(titelString, X-5, Y+50);
	resize(50, 50);
}

void Window::SetNewColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
	SetColor(r, g, b);
}

Color Window::GetColor()
{
	return color;
}

void Window::OnResize(int width, int height)
{
	/*resize(width, height);*/
}

void Window::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + Height)
		hit = true;
	else
		hit = false;
	if (pressed)
	{
		X = x;
		Y = y;
	}
}

void Window::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
		pressed = true;
	else
		pressed = false;
}

void Window::OnMouseUp(int button, int x, int y)
{
	if (pressed)
		pressed = false;
}