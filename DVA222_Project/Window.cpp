#include "stdafx.h"
#include "Window.h"


Window::Window()
{
}
Window::Window(int locX, int locY, int width, int height, int order)
	: Panel(locX, locY, width, height, order)
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
	SetColor(borderColor.r, borderColor.g, borderColor.b);
	DrawRectangle(position.X, position.Y, Width + 1, Height + 1);
	SetColor(bgColor.r, bgColor.g, bgColor.b);
	FillRectangle(position.X, position.Y, Width, Height, 0);
	SetColor(titleColor.r, titleColor.g, titleColor.b);
	DrawString(titelString, position.X - 5, position.Y + 50);
	resize(50, 50);
}

void Window::SetBackgroundColor(int r, int g, int b)
{
	bgColor.r = r;
	bgColor.g = g;
	bgColor.b = b;
}

void Window::SetBorderColor(int r, int g, int b)
{
	borderColor.r = r;
	borderColor.g = g;
	borderColor.b = b;
}

void Window::SetTitleColor(int r, int g, int b)
{
	titleColor.r = r;
	titleColor.g = g;
	titleColor.b = b;
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
	if (x>position.X && x < position.X + Width && y>position.Y && y < position.Y + Height)
		hit = true;
	else
		hit = false;
	if (pressed)
	{
		position.X = x;
		position.Y = y;
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