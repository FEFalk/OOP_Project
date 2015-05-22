#include "stdafx.h"
#include "Window.h"

Window::Window()
{
	window = new Container();
}
Window::Window(int locX, int locY, int width, int height, int size) :Panel(locX, locY, width, height)
{
	window = (Window *)realloc(panel, size * sizeof(Window));
	this->size = size;
	size++;
}


Window::~Window()
{
}
void Window::OnLoaded(void)
{
	titelString.clear();
	titelString.append("HejHej");
	color = Color(255, 0, 0);
}
void Window::OnPaint()
{
	SetColor(color.r, color.g, color.b);

	DrawRectangle(X, Y, Width, Height);
	FillRectangle(X, Y, Width, Height);
}
void Window::SetNewColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}